/*
 * Copyright Paul Reimer, 2018
 *
 * All rights reserved.
 *
 */
#pragma once

#include "actor.h"
#include "node.h"

#include "actor_model_generated.h"

namespace ActorModel {

// free functions bound to default node
auto spawn(
  Behaviour&& _behaviour,
  const ActorExecutionConfigT& _execution_config = default_execution_config
) -> Pid;

auto spawn_link(
  Behaviour&& _behaviour,
  const Pid& _initial_link_pid,
  const ActorExecutionConfigT& _execution_config = default_execution_config
) -> Pid;

auto process_flag(const Pid& pid, ProcessFlag flag, bool flag_setting)
  -> bool;

auto send(const Pid& pid, const MessageT& message)
  -> bool;

auto register_name(std::experimental::string_view name, const Pid& pid)
  -> bool;

auto unregister(std::experimental::string_view name)
  -> bool;

auto registered()
  -> const Node::NamedProcessRegistry;

auto whereis(std::experimental::string_view name)
  -> MaybePid;

} // namespace ActorModel