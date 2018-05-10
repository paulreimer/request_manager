/*
 * Copyright Paul Reimer, 2018
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 Unported License.
 * To view a copy of this license, visit
 * https://creativecommons.org/licenses/by-nc-sa/4.0/
 * or send a letter to
 * Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */
#pragma once

#include "request_handler.h"

#ifdef REQUESTS_USE_CURL
#include "curl/curl.h"
#include "curl/multi.h"
#endif // REQUESTS_USE_CURL

#ifdef REQUESTS_USE_SH2LIB
extern "C" {
#include "sh2lib.h"
}
#endif // REQUESTS_USE_SH2LIB

#include <experimental/string_view>

#include <memory>
#include <string>
#include <unordered_map>

#include "mbedtls/ssl.h"
#include "mbedtls/x509_crt.h"

namespace Requests {

class RequestManager
{
public:
#ifdef REQUESTS_USE_CURL
  using HandleImpl = CURL;
#endif // REQUESTS_USE_CURL
#ifdef REQUESTS_USE_SH2LIB
  using HandleImpl = sh2lib_handle;
#endif // REQUESTS_USE_SH2LIB
  using HandleImplPtr = std::unique_ptr<HandleImpl, void(*)(HandleImpl*)>;

  using string_view = std::experimental::string_view;

  RequestManager();
  ~RequestManager();

  auto fetch(
    const RequestIntentFlatbufferRef& _request_intent_buf_ref
  ) -> bool;

  auto send(
    HandleImpl* handle,
    RequestHandler& handler
  ) -> bool;

  auto wait_any()
    -> size_t;

  auto wait_all()
    -> size_t;

  auto add_cacert_pem(const string_view cacert_pem)
    -> bool;
  auto add_cacert_der(const string_view cacert_der)
    -> bool;

#ifdef REQUESTS_USE_CURL
  auto sslctx_callback(CURL* curl, mbedtls_ssl_config* ssl_ctx)
    -> CURLcode;
#endif // REQUESTS_USE_CURL

protected:
  using RequestMap = std::unordered_map<HandleImplPtr, RequestHandler>;
  RequestMap requests;

  auto get_existing_request_handler(const UUID* request_intent_id)
    -> RequestMap::const_iterator;

private:
#ifdef REQUESTS_USE_CURL
  std::unique_ptr<CURLM, CURLMcode(*)(CURLM*)> multi_handle;
#endif // REQUESTS_USE_CURL
};

} // namespace Requests
