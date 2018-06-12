#include "filesystem.h"

#include <stdio.h>

#include "esp_log.h"

using string_view = std::experimental::string_view;

constexpr char TAG[] = "filesystem";

auto filesystem_read(string_view path)
  -> std::vector<uint8_t>
{
  auto file = fopen(path.data(), "rb");
  if (file != nullptr)
  {
    // Seek to end of file to determine its size
    fseek(file, 0L, SEEK_END);
    auto file_len = ftell(file);
    rewind(file);

    std::vector<uint8_t> file_contents(file_len, 0x00);

    auto bytes_read = fread(
      const_cast<uint8_t*>(file_contents.data()),
      sizeof(uint8_t),
      file_len,
      file
    );

    fclose(file);

    if (bytes_read == file_len)
    {
      return file_contents;
    }
    else {
      ESP_LOGW(
        TAG,
        "Invalid read %d bytes from file %.*s",
        bytes_read,
        path.size(),
        path.data()
      );
    }
  }
  else {
    ESP_LOGE(
      TAG,
      "Failed to open file %.*s for reading",
      path.size(),
      path.data()
    );
  }

  return {};
}