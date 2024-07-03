// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from action_marvin_interfaces:action/Hover.idl
// generated code does not contain a copyright notice

#ifndef ACTION_MARVIN_INTERFACES__ACTION__DETAIL__HOVER__TRAITS_HPP_
#define ACTION_MARVIN_INTERFACES__ACTION__DETAIL__HOVER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "action_marvin_interfaces/action/detail/hover__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace action_marvin_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Hover_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: initial_x
  {
    out << "initial_x: ";
    rosidl_generator_traits::value_to_yaml(msg.initial_x, out);
    out << ", ";
  }

  // member: initial_y
  {
    out << "initial_y: ";
    rosidl_generator_traits::value_to_yaml(msg.initial_y, out);
    out << ", ";
  }

  // member: initial_z
  {
    out << "initial_z: ";
    rosidl_generator_traits::value_to_yaml(msg.initial_z, out);
    out << ", ";
  }

  // member: final_x
  {
    out << "final_x: ";
    rosidl_generator_traits::value_to_yaml(msg.final_x, out);
    out << ", ";
  }

  // member: final_y
  {
    out << "final_y: ";
    rosidl_generator_traits::value_to_yaml(msg.final_y, out);
    out << ", ";
  }

  // member: final_z
  {
    out << "final_z: ";
    rosidl_generator_traits::value_to_yaml(msg.final_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Hover_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: initial_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "initial_x: ";
    rosidl_generator_traits::value_to_yaml(msg.initial_x, out);
    out << "\n";
  }

  // member: initial_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "initial_y: ";
    rosidl_generator_traits::value_to_yaml(msg.initial_y, out);
    out << "\n";
  }

  // member: initial_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "initial_z: ";
    rosidl_generator_traits::value_to_yaml(msg.initial_z, out);
    out << "\n";
  }

  // member: final_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "final_x: ";
    rosidl_generator_traits::value_to_yaml(msg.final_x, out);
    out << "\n";
  }

  // member: final_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "final_y: ";
    rosidl_generator_traits::value_to_yaml(msg.final_y, out);
    out << "\n";
  }

  // member: final_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "final_z: ";
    rosidl_generator_traits::value_to_yaml(msg.final_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Hover_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_marvin_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use action_marvin_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_marvin_interfaces::action::Hover_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_marvin_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_marvin_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const action_marvin_interfaces::action::Hover_Goal & msg)
{
  return action_marvin_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_marvin_interfaces::action::Hover_Goal>()
{
  return "action_marvin_interfaces::action::Hover_Goal";
}

template<>
inline const char * name<action_marvin_interfaces::action::Hover_Goal>()
{
  return "action_marvin_interfaces/action/Hover_Goal";
}

template<>
struct has_fixed_size<action_marvin_interfaces::action::Hover_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_marvin_interfaces::action::Hover_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_marvin_interfaces::action::Hover_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace action_marvin_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Hover_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Hover_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Hover_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_marvin_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use action_marvin_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_marvin_interfaces::action::Hover_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_marvin_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_marvin_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const action_marvin_interfaces::action::Hover_Result & msg)
{
  return action_marvin_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_marvin_interfaces::action::Hover_Result>()
{
  return "action_marvin_interfaces::action::Hover_Result";
}

template<>
inline const char * name<action_marvin_interfaces::action::Hover_Result>()
{
  return "action_marvin_interfaces/action/Hover_Result";
}

template<>
struct has_fixed_size<action_marvin_interfaces::action::Hover_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_marvin_interfaces::action::Hover_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_marvin_interfaces::action::Hover_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace action_marvin_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Hover_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: current_x
  {
    out << "current_x: ";
    rosidl_generator_traits::value_to_yaml(msg.current_x, out);
    out << ", ";
  }

  // member: current_y
  {
    out << "current_y: ";
    rosidl_generator_traits::value_to_yaml(msg.current_y, out);
    out << ", ";
  }

  // member: current_z
  {
    out << "current_z: ";
    rosidl_generator_traits::value_to_yaml(msg.current_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Hover_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: current_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_x: ";
    rosidl_generator_traits::value_to_yaml(msg.current_x, out);
    out << "\n";
  }

  // member: current_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_y: ";
    rosidl_generator_traits::value_to_yaml(msg.current_y, out);
    out << "\n";
  }

  // member: current_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_z: ";
    rosidl_generator_traits::value_to_yaml(msg.current_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Hover_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_marvin_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use action_marvin_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_marvin_interfaces::action::Hover_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_marvin_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_marvin_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const action_marvin_interfaces::action::Hover_Feedback & msg)
{
  return action_marvin_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_marvin_interfaces::action::Hover_Feedback>()
{
  return "action_marvin_interfaces::action::Hover_Feedback";
}

template<>
inline const char * name<action_marvin_interfaces::action::Hover_Feedback>()
{
  return "action_marvin_interfaces/action/Hover_Feedback";
}

template<>
struct has_fixed_size<action_marvin_interfaces::action::Hover_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_marvin_interfaces::action::Hover_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_marvin_interfaces::action::Hover_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "action_marvin_interfaces/action/detail/hover__traits.hpp"

namespace action_marvin_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Hover_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Hover_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Hover_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_marvin_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use action_marvin_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_marvin_interfaces::action::Hover_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_marvin_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_marvin_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const action_marvin_interfaces::action::Hover_SendGoal_Request & msg)
{
  return action_marvin_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_marvin_interfaces::action::Hover_SendGoal_Request>()
{
  return "action_marvin_interfaces::action::Hover_SendGoal_Request";
}

template<>
inline const char * name<action_marvin_interfaces::action::Hover_SendGoal_Request>()
{
  return "action_marvin_interfaces/action/Hover_SendGoal_Request";
}

template<>
struct has_fixed_size<action_marvin_interfaces::action::Hover_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<action_marvin_interfaces::action::Hover_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<action_marvin_interfaces::action::Hover_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<action_marvin_interfaces::action::Hover_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<action_marvin_interfaces::action::Hover_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace action_marvin_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Hover_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Hover_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Hover_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_marvin_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use action_marvin_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_marvin_interfaces::action::Hover_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_marvin_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_marvin_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const action_marvin_interfaces::action::Hover_SendGoal_Response & msg)
{
  return action_marvin_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_marvin_interfaces::action::Hover_SendGoal_Response>()
{
  return "action_marvin_interfaces::action::Hover_SendGoal_Response";
}

template<>
inline const char * name<action_marvin_interfaces::action::Hover_SendGoal_Response>()
{
  return "action_marvin_interfaces/action/Hover_SendGoal_Response";
}

template<>
struct has_fixed_size<action_marvin_interfaces::action::Hover_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<action_marvin_interfaces::action::Hover_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<action_marvin_interfaces::action::Hover_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_marvin_interfaces::action::Hover_SendGoal>()
{
  return "action_marvin_interfaces::action::Hover_SendGoal";
}

template<>
inline const char * name<action_marvin_interfaces::action::Hover_SendGoal>()
{
  return "action_marvin_interfaces/action/Hover_SendGoal";
}

template<>
struct has_fixed_size<action_marvin_interfaces::action::Hover_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<action_marvin_interfaces::action::Hover_SendGoal_Request>::value &&
    has_fixed_size<action_marvin_interfaces::action::Hover_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<action_marvin_interfaces::action::Hover_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<action_marvin_interfaces::action::Hover_SendGoal_Request>::value &&
    has_bounded_size<action_marvin_interfaces::action::Hover_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<action_marvin_interfaces::action::Hover_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<action_marvin_interfaces::action::Hover_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<action_marvin_interfaces::action::Hover_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace action_marvin_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Hover_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Hover_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Hover_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_marvin_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use action_marvin_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_marvin_interfaces::action::Hover_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_marvin_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_marvin_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const action_marvin_interfaces::action::Hover_GetResult_Request & msg)
{
  return action_marvin_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_marvin_interfaces::action::Hover_GetResult_Request>()
{
  return "action_marvin_interfaces::action::Hover_GetResult_Request";
}

template<>
inline const char * name<action_marvin_interfaces::action::Hover_GetResult_Request>()
{
  return "action_marvin_interfaces/action/Hover_GetResult_Request";
}

template<>
struct has_fixed_size<action_marvin_interfaces::action::Hover_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<action_marvin_interfaces::action::Hover_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<action_marvin_interfaces::action::Hover_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "action_marvin_interfaces/action/detail/hover__traits.hpp"

namespace action_marvin_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Hover_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Hover_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Hover_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_marvin_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use action_marvin_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_marvin_interfaces::action::Hover_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_marvin_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_marvin_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const action_marvin_interfaces::action::Hover_GetResult_Response & msg)
{
  return action_marvin_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_marvin_interfaces::action::Hover_GetResult_Response>()
{
  return "action_marvin_interfaces::action::Hover_GetResult_Response";
}

template<>
inline const char * name<action_marvin_interfaces::action::Hover_GetResult_Response>()
{
  return "action_marvin_interfaces/action/Hover_GetResult_Response";
}

template<>
struct has_fixed_size<action_marvin_interfaces::action::Hover_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<action_marvin_interfaces::action::Hover_Result>::value> {};

template<>
struct has_bounded_size<action_marvin_interfaces::action::Hover_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<action_marvin_interfaces::action::Hover_Result>::value> {};

template<>
struct is_message<action_marvin_interfaces::action::Hover_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_marvin_interfaces::action::Hover_GetResult>()
{
  return "action_marvin_interfaces::action::Hover_GetResult";
}

template<>
inline const char * name<action_marvin_interfaces::action::Hover_GetResult>()
{
  return "action_marvin_interfaces/action/Hover_GetResult";
}

template<>
struct has_fixed_size<action_marvin_interfaces::action::Hover_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<action_marvin_interfaces::action::Hover_GetResult_Request>::value &&
    has_fixed_size<action_marvin_interfaces::action::Hover_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<action_marvin_interfaces::action::Hover_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<action_marvin_interfaces::action::Hover_GetResult_Request>::value &&
    has_bounded_size<action_marvin_interfaces::action::Hover_GetResult_Response>::value
  >
{
};

template<>
struct is_service<action_marvin_interfaces::action::Hover_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<action_marvin_interfaces::action::Hover_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<action_marvin_interfaces::action::Hover_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "action_marvin_interfaces/action/detail/hover__traits.hpp"

namespace action_marvin_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Hover_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Hover_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Hover_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_marvin_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use action_marvin_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_marvin_interfaces::action::Hover_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_marvin_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_marvin_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const action_marvin_interfaces::action::Hover_FeedbackMessage & msg)
{
  return action_marvin_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_marvin_interfaces::action::Hover_FeedbackMessage>()
{
  return "action_marvin_interfaces::action::Hover_FeedbackMessage";
}

template<>
inline const char * name<action_marvin_interfaces::action::Hover_FeedbackMessage>()
{
  return "action_marvin_interfaces/action/Hover_FeedbackMessage";
}

template<>
struct has_fixed_size<action_marvin_interfaces::action::Hover_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<action_marvin_interfaces::action::Hover_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<action_marvin_interfaces::action::Hover_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<action_marvin_interfaces::action::Hover_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<action_marvin_interfaces::action::Hover_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<action_marvin_interfaces::action::Hover>
  : std::true_type
{
};

template<>
struct is_action_goal<action_marvin_interfaces::action::Hover_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<action_marvin_interfaces::action::Hover_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<action_marvin_interfaces::action::Hover_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // ACTION_MARVIN_INTERFACES__ACTION__DETAIL__HOVER__TRAITS_HPP_
