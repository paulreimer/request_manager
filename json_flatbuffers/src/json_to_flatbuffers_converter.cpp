/*
 * Copyright Paul Reimer, 2018
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 Unported License.
 * To view a copy of this license, visit
 * https://creativecommons.org/licenses/by-nc-sa/4.0/
 * or send a letter to
 * Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

#include "json_to_flatbuffers_converter.h"

namespace JsonFlatbuffers {
using string = std::string;

JsonToFlatbuffersConverter::JsonToFlatbuffersConverter(
  const string_view _flatbuffers_schema_text,
  const string_view _flatbuffers_root_type,
  const JsonEmitter::JsonPath& _match_path
)
: json_emitter(_match_path)
{
  flatbuffers_parser.opts.skip_unexpected_fields_in_json = true;

  parser_loaded = flatbuffers_parser.Parse(_flatbuffers_schema_text.data());
  if (parser_loaded and not _flatbuffers_root_type.empty())
  {
    auto root_type = string{_flatbuffers_root_type};
    flatbuffers_parser.SetRootType(root_type.c_str());
  }
}

JsonToFlatbuffersConverter::JsonToFlatbuffersConverter(
  const string_view _flatbuffers_schema_text,
  const string_view _flatbuffers_root_type,
  const string_view _match_path_str
)
: json_emitter(_match_path_str)
{
  parser_loaded = flatbuffers_parser.Parse(_flatbuffers_schema_text.data());
  if (parser_loaded and not _flatbuffers_root_type.empty())
  {
    auto root_type = string{_flatbuffers_root_type};
    flatbuffers_parser.SetRootType(root_type.c_str());
  }
}

auto JsonToFlatbuffersConverter::reset()
  -> bool
{
  return json_emitter.reset();
}

auto JsonToFlatbuffersConverter::has_parse_state()
  -> bool
{
  return json_emitter.has_parse_state();
}

auto JsonToFlatbuffersConverter::parse(
  const string_view chunk,
  const Callback&& callback,
  const Errback&& errback
) -> bool
{
  return json_emitter.parse(chunk,
    [&]
    (string_view json_str) -> PostCallbackAction
    {
      if (parser_loaded)
      {
        auto parsed_ok = flatbuffers_parser.Parse(json_str.data());

        if (parsed_ok)
        {
          callback(
            BufferView(
              flatbuffers_parser.builder_.GetBufferPointer(),
              flatbuffers_parser.builder_.GetSize()
            )
          );
        }
        else {
          ESP_LOGE(
            "JsonToFlatbuffersConverter",
            "Invalid flatbuffer: %s",
            flatbuffers_parser.error_.c_str()
          );
        }
      }

      return JsonEmitter::ContinueProcessing;
    },

    [&]
    (string_view json_str) -> PostCallbackAction
    {
      ESP_LOGE(
        "JsonToFlatbuffersConverter",
        "'%.*s'\n",
        json_str.size(),
        json_str.data()
      );

      return JsonEmitter::ContinueProcessing;
    }
  );
}

} // namespace JsonFlatbuffers
