/*
 * Copyright Paul Reimer, 2018
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 Unported License.
 * To view a copy of this license, visit
 * https://creativecommons.org/licenses/by-nc-sa/4.0/
 * or send a letter to
 * Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

#include "actor_model.h"

namespace ActorModel {

using string_view = std::experimental::string_view;

// free functions bound to default node

// Single behaviour convenience function
auto spawn(
  const Behaviour&& _behaviour,
  const ExecConfigCallback&& _exec_config_callback
) -> Pid
{
  auto& node = Actor::get_default_node();
  return node.spawn(
    {std::move(_behaviour)},
    std::move(_exec_config_callback)
  );
}

auto spawn_link(
  const Behaviour&& _behaviour,
  const Pid& _initial_link_pid,
  const ExecConfigCallback&& _exec_config_callback
) -> Pid
{
  auto& node = Actor::get_default_node();
  return node.spawn_link(
    {std::move(_behaviour)},
    _initial_link_pid,
    std::move(_exec_config_callback)
  );
}

// Multiple chained behaviours
auto spawn(
  const Behaviours&& _behaviours,
  const ExecConfigCallback&& _exec_config_callback
) -> Pid
{
  auto& node = Actor::get_default_node();
  return node.spawn(
    std::move(_behaviours),
    std::move(_exec_config_callback)
  );
}

auto spawn_link(
  const Behaviours&& _behaviours,
  const Pid& _initial_link_pid,
  const ExecConfigCallback&& _exec_config_callback
) -> Pid
{
  auto& node = Actor::get_default_node();
  return node.spawn_link(
    std::move(_behaviours),
    _initial_link_pid,
    std::move(_exec_config_callback)
  );
}

auto process_flag(
  const Pid& pid,
  const ProcessFlag flag,
  const bool flag_setting
) -> bool
{
  auto& node = Actor::get_default_node();
  return node.process_flag(pid, flag, flag_setting);
}

auto send(
  const Pid& pid,
  const Message& message
) -> bool
{
  auto& node = Actor::get_default_node();
  return node.send(pid, message);
}

auto send(
  const Pid& pid,
  const string_view type,
  const string_view payload
) -> bool
{
  auto& node = Actor::get_default_node();
  return node.send(pid, type, payload);
}

auto send(
  const Pid& pid,
  const string_view type,
  const std::vector<uint8_t>& payload_vec
) -> bool
{
  auto& node = Actor::get_default_node();
  const auto payload = string_view{
    reinterpret_cast<const char*>(payload_vec.data()),
    payload_vec.size()
  };

  return node.send(pid, type, payload);
}

auto send(
  const Pid& pid,
  const string_view type,
  const MessageFlatbuffer& payload_flatbuffer
) -> bool
{
  auto& node = Actor::get_default_node();
  auto payload = string_view(
    reinterpret_cast<const char*>(payload_flatbuffer.data()),
    payload_flatbuffer.size()
  );
  return node.send(pid, type, payload);
}

auto send_after(
  const Time time,
  const Pid& pid,
  const Message& message
) -> TRef
{
  auto& node = Actor::get_default_node();
  return node.send_after(time, pid, message);
}

auto send_after(
  const Time time,
  const Pid& pid,
  const string_view type,
  const string_view payload
) -> TRef
{
  auto& node = Actor::get_default_node();
  return node.send_after(time, pid, type, payload);
}

auto send_after(
  const Time time,
  const Pid& pid,
  const string_view type,
  const std::vector<uint8_t>& payload_vec
) -> TRef
{
  auto& node = Actor::get_default_node();
  const auto payload = string_view{
    reinterpret_cast<const char*>(payload_vec.data()),
    payload_vec.size()
  };

  return node.send_after(time, pid, type, payload);
}

auto send_after(
  const Time time,
  const Pid& pid,
  const string_view type,
  const MessageFlatbuffer& payload_flatbuffer
) -> TRef
{
  auto& node = Actor::get_default_node();
  auto payload = string_view(
    reinterpret_cast<const char*>(payload_flatbuffer.data()),
    payload_flatbuffer.size()
  );
  return node.send_after(time, pid, type, payload);
}

auto send_interval(
  const Time time,
  const Pid& pid,
  const Message& message
) -> TRef
{
  auto& node = Actor::get_default_node();
  return node.send_interval(time, pid, message);
}

auto send_interval(
  const Time time,
  const Pid& pid,
  const string_view type,
  const string_view payload
) -> TRef
{
  auto& node = Actor::get_default_node();
  return node.send_interval(time, pid, type, payload);
}

auto send_interval(
  const Time time,
  const Pid& pid,
  const string_view type,
  const std::vector<uint8_t>& payload_vec
) -> TRef
{
  auto& node = Actor::get_default_node();
  const auto payload = string_view{
    reinterpret_cast<const char*>(payload_vec.data()),
    payload_vec.size()
  };

  return node.send_interval(time, pid, type, payload);
}

auto send_interval(
  const Time time,
  const Pid& pid,
  const string_view type,
  const MessageFlatbuffer& payload_flatbuffer
) -> TRef
{
  auto& node = Actor::get_default_node();
  auto payload = string_view(
    reinterpret_cast<const char*>(payload_flatbuffer.data()),
    payload_flatbuffer.size()
  );
  return node.send_interval(time, pid, type, payload);
}

auto cancel(const TRef tref)
  -> bool
{
  auto& node = Actor::get_default_node();
  return node.cancel(tref);
}

auto register_name(const string_view name, const Pid& pid)
  -> bool
{
  auto& node = Actor::get_default_node();
  return node.register_name(name, pid);
}

auto unregister(const string_view name)
  -> bool
{
  auto& node = Actor::get_default_node();
  return node.unregister(name);
}

auto registered()
  -> const Node::NamedProcessRegistry
{
  auto& node = Actor::get_default_node();
  return node.registered();
}

auto whereis(const string_view name)
  -> MaybePid
{
  auto& node = Actor::get_default_node();
  return node.whereis(name);
}

} // namespace ActorModel
