/*
 * Copyright Paul Reimer, 2018
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 Unported License.
 * To view a copy of this license, visit
 * https://creativecommons.org/licenses/by-nc-sa/4.0/
 * or send a letter to
 * Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */
#include "request_manager.h"

#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "esp_log.h"

using string_view = std::experimental::string_view;
using string = std::string;

mbedtls_x509_crt cacert;

constexpr char TAG[] = "RequestManager";

size_t header_callback(char* buf, size_t size, size_t nitems, void* userdata)
{
  auto header = string_view(buf, size*nitems);
  return static_cast<RequestHandler*>(userdata)->header_callback(header);
}

size_t writefunction(char *buf, size_t size, size_t nmemb, void* userdata)
{
  auto chunk = string_view(buf, size*nmemb);
  return static_cast<RequestHandler*>(userdata)->write_callback(chunk);
}

CURLcode sslctx_function(CURL* curl, void* ssl_ctx, void* userdata)
{
  auto* conf = static_cast<mbedtls_ssl_config*>(ssl_ctx);
  return static_cast<RequestManager*>(userdata)->sslctx_callback(curl, conf);
}

RequestManager::RequestManager()
: requests{}
, multi_handle(curl_multi_init(), curl_multi_cleanup)
{
  curl_global_init(CURL_GLOBAL_ALL);

  auto m = multi_handle.get();

  // Set the maximum number of connections to keep in the cache
  curl_multi_setopt(m, CURLMOPT_MAXCONNECTS, 4L);

  // Set the maximum number of active connections (after which, block)
  curl_multi_setopt(m, CURLMOPT_MAX_TOTAL_CONNECTIONS, 4L);

  // Attempt to pipeline and/or multiplex requests if possible
  curl_multi_setopt(m, CURLMOPT_PIPELINING, CURLPIPE_HTTP1|CURLPIPE_MULTIPLEX);
}

RequestManager::~RequestManager()
{
  mbedtls_x509_crt_free(&cacert);
}

bool
RequestManager::fetch(
  Request&& _req,
  RequestHandler::OnDataCallback&& _on_data_callback,
  RequestHandler::OnDataErrback&& _on_data_errback,
  RequestHandler::OnFinishCallback&& _on_finish_callback
)
{
  //const auto& inserted = requests.emplace(std::move(_req), std::move(_res));
  const auto& inserted = requests.emplace(
    std::move(HandleImplPtr{
      curl_easy_init(),
      curl_easy_cleanup
    }),
    std::move(RequestHandler{
      std::move(_req),
      std::move(_on_data_callback),
      std::move(_on_data_errback),
      std::move(_on_finish_callback)
    })
  );

  if (inserted.second == true)
  {
    auto& handle = inserted.first->first;
    auto& handler = inserted.first->second;

    return send(handle.get(), handler);
  }

  return false;
}

bool
RequestManager::send(
  HandleImpl* handle,
  RequestHandler& handler
)
{
  auto* curl = handle;
  auto& req = handler.req;
  auto& res = handler.res;

  // Allocate CURL_ERROR_SIZE bytes of zero-initialized data
  res.errbuf.resize(CURL_ERROR_SIZE, 0);

  // Reset the c-string contents to zero-length, null-terminated
  res.errbuf[0] = 0;

  req._url = req.uri;
  if (not req.query.empty())
  {
    char delim = (req.uri.find_first_of('?') == string::npos)? '?' : '&';
    for (auto& arg : req.query)
    {
      req._url += delim + arg.first + '=' + arg.second;
      delim = '&';
    }
  }

  curl_easy_setopt(curl, CURLOPT_URL, req._url.c_str());

  // Do not print out any updates to stdout
  curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
  curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
  // Do not install signal handlers
  curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

  // Set user data pointer attached to this request
  curl_easy_setopt(curl, CURLOPT_PRIVATE, &handler);

  // Provide a buffer for curl to store error strings in
  curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, res.errbuf.data());

  // Follow redirects (3xx responses) until the actual URL is found
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

  // Attempt HTTP/2 for HTTPS URLs, fallback to HTTP/1.1 otherwise
  curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_2TLS);

  // Do not include headers in the response stream
  curl_easy_setopt(curl, CURLOPT_HEADER, 0L);
  // Parse headers with a separate callback
  curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, header_callback);
  // Set user data pointer attached to the header function for this request
  curl_easy_setopt(curl, CURLOPT_HEADERDATA, &handler);

  // Body data incremental callback
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunction);
  // Set user data pointer attached to the write function for this request
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &handler);

  // Verify SSL certificates with CA cert(s)
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
  // Use a function to supply PEM contents of CA cert(s) in memory buffer
  curl_easy_setopt(curl, CURLOPT_SSL_CTX_FUNCTION, sslctx_function);
  // Set user data pointer attached to the sslctx function for this request
  curl_easy_setopt(curl, CURLOPT_SSL_CTX_DATA, this);

  // Turn off the default CA locations, so no attempts are made to load them
  curl_easy_setopt(curl, CURLOPT_CAINFO, NULL);
  curl_easy_setopt(curl, CURLOPT_CAPATH, NULL);

  if (handler.slist)
  {
    // Reset existing headers
    curl_slist_free_all(handler.slist);
    handler.slist = nullptr;
  }

  if (not req.headers.empty())
  {
    for (auto& hdr : req.headers)
    {
      string hdr_str(hdr.first + string(": ") + hdr.second);
      handler.slist = curl_slist_append(handler.slist, hdr_str.c_str());
    }
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, handler.slist);
  }

  if (req.method == "GET")
  {
    // Use GET (default)
  }
  else if (req.method == "POST")
  {
    // Use POST
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
  }
  else {
    // Use a custom (user-supplied) HTTP method (e.g. PATCH)
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, req.method.c_str());
  }

  // Set the POST body data, if the request specifies a body
  if (not req.body.empty())
  {
    // Specify the length of the post body
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, req.body.size());
    // Specify a pointer to the data of the post body, do not delete it
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, req.body.data());
  }

  ESP_LOGI(TAG, "Fetching %s", req.uri.c_str());
  curl_multi_add_handle(multi_handle.get(), curl);

  return true;
}

bool
RequestManager::wait_all()
{
  int inflight_count;
  bool any_done = false;
  int MAX_WAIT_MSECS = (30*1000);

  for (auto& handle_and_request_handler : requests)
  {
    const auto& handle = handle_and_request_handler.first;
    auto& handler = handle_and_request_handler.second;

    if (handler.req.pending && handler.req.ready)
    {
      handler.req.pending = false;
      send(handle.get(), handler);
    }
  }

  curl_multi_perform(multi_handle.get(), &inflight_count);

  do {
    int numfds = 0;
    int res = curl_multi_wait(
      multi_handle.get(),
      nullptr,
      0,
      MAX_WAIT_MSECS,
      &numfds
    );

    if (res != CURLM_OK)
    {
      ESP_LOGE(TAG, "error: curl_multi_wait() returned %d", res);
      return false;
    }

    curl_multi_perform(multi_handle.get(), &inflight_count);
  }
  while (inflight_count > 0);

  int msgs_left;
  CURLMsg* msg = nullptr;
  // Check for any messages, from any transfers
  while ((msg = curl_multi_info_read(multi_handle.get(), &msgs_left)))
  {
    // If a request has finished, find it and execute relevant callbacks
    if (msg->msg == CURLMSG_DONE)
    {
      auto& done_handle = msg->easy_handle;

      // Search for the matching handle
      auto done_req_handler = std::find_if(requests.begin(), requests.end(),
        [done_handle]
        (const auto& req_res_pair) -> bool
        {
          return (req_res_pair.first.get() == done_handle);
        }
      );

      // If a matching request handle was found
      if (done_req_handler != requests.end())
      {
        any_done = true;
        auto& handler = done_req_handler->second;

        auto post_action_callback = RequestHandler::DisposeRequest;

        // Execute the callback if it is set
        if (handler.on_finish_callback)
        {
          post_action_callback = handler.on_finish_callback(
            handler.req,
            handler.res
          );
        }

        // Remove the request handle from the multi handle
        curl_multi_remove_handle(multi_handle.get(), done_handle);

        // Reset request/response state
        if (handler.slist)
        {
          // Free the list of headers used in the request
          curl_slist_free_all(handler.slist);
          handler.slist = nullptr;
        }

        // Reset the previous response error code
        handler.res.code = -1;

        // Clear the list of headers used in the response
        handler.res.headers.clear();

        // Reset the c-string contents to zero-length, null-terminated
        handler.res.errbuf[0] = 0;

        // Dispose/re-use handle according to on_finish_callback result
        switch (post_action_callback)
        {
          case RequestHandler::DisposeRequest:
          {
            ESP_LOGI(TAG, "Removing completed request handle");
            // Cleanup, free request handle and Request/Response objects
            requests.erase(done_req_handler);
            ESP_LOGI(TAG, "Deleted successfully");
            break;
          }

          case RequestHandler::ReuseRequest:
          {
            // Re-use the old handle and re-add it to the multi handle
            ESP_LOGI(TAG, "Fetching (again) %s", handler.req.uri.c_str());
            curl_multi_add_handle(multi_handle.get(), done_handle);
            break;
          }

          case RequestHandler::QueueRequest:
          {
            ESP_LOGI(TAG, "Leave request handle available for re-use");
            handler.req.pending = true;
            handler.req.ready = false;
            break;
          }
        }
      }
    }
  }

  return any_done;
}

bool
RequestManager::add_cacert_pem(string_view cacert_pem)
{
  //TODO: this is possibly not request-safe and should be avoided during requests
  //or rewritten with a CA object per request

  // Check for null-terminating byte
  if (cacert_pem.back() == '\0')
  {
    // Parse the PEM text
    auto ret = mbedtls_x509_crt_parse(
      &cacert,
      (unsigned char*)cacert_pem.data(),
      cacert_pem.size()
    );

    if (ret >= 0)
    {
      // Return true only if parse succeeded
      return true;
    }
    else {
      ESP_LOGE(TAG, "Unable to parse CA cert string as PEM data '%.*s'",
        cacert_pem.size(), cacert_pem.data()
      );
    }
  }
  else {
    ESP_LOGE(TAG, "Expected a null terminated CA cert string");
  }

  return false;
}

bool
RequestManager::add_cacert_der(string_view cacert_der)
{
  //TODO: this is possibly not request-safe and should be avoided during requests
  //or rewritten with a CA object per request

  // Parse the DER content
  auto ret = mbedtls_x509_crt_parse_der(
    &cacert,
    (unsigned char*)cacert_der.data(),
    cacert_der.size()
  );

  if (ret >= 0)
  {
    // Return true only if parse succeeded
    return true;
  }
  else {
    ESP_LOGE(TAG, "Unable to parse CA cert string as DER data '%.*s'",
      cacert_der.size(), cacert_der.data()
    );
  }

  return false;
}

CURLcode
RequestManager::sslctx_callback(CURL* curl, mbedtls_ssl_config* ssl_ctx)
{
  // Default to fail
  CURLcode rv = CURLE_ABORTED_BY_CALLBACK;

  bool ok = true;
  if (ok)
  {
    // Update the curl handle's cacert chain
    mbedtls_ssl_conf_ca_chain(ssl_ctx, &cacert, nullptr);

    // Mark the callback as successfully passed
    rv = CURLE_OK;
  }
  else {
    // PEM parse error was encountered
    ESP_LOGE(TAG, "Invalid CA chain");
  }

  return rv;
}
