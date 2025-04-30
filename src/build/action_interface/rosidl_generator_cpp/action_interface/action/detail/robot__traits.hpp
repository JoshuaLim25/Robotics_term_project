// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from action_interface:action/Robot.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACE__ACTION__DETAIL__ROBOT__TRAITS_HPP_
#define ACTION_INTERFACE__ACTION__DETAIL__ROBOT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "action_interface/action/detail/robot__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Robot_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: v_x
  {
    out << "v_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_x, out);
    out << ", ";
  }

  // member: w_z
  {
    out << "w_z: ";
    rosidl_generator_traits::value_to_yaml(msg.w_z, out);
    out << ", ";
  }

  // member: drive_time
  {
    out << "drive_time: ";
    rosidl_generator_traits::value_to_yaml(msg.drive_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Robot_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: v_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_x, out);
    out << "\n";
  }

  // member: w_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "w_z: ";
    rosidl_generator_traits::value_to_yaml(msg.w_z, out);
    out << "\n";
  }

  // member: drive_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drive_time: ";
    rosidl_generator_traits::value_to_yaml(msg.drive_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Robot_Goal & msg, bool use_flow_style = false)
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

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Robot_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Robot_Goal & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Robot_Goal>()
{
  return "action_interface::action::Robot_Goal";
}

template<>
inline const char * name<action_interface::action::Robot_Goal>()
{
  return "action_interface/action/Robot_Goal";
}

template<>
struct has_fixed_size<action_interface::action::Robot_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<action_interface::action::Robot_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<action_interface::action::Robot_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Robot_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: complete
  {
    out << "complete: ";
    rosidl_generator_traits::value_to_yaml(msg.complete, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Robot_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: complete
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "complete: ";
    rosidl_generator_traits::value_to_yaml(msg.complete, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Robot_Result & msg, bool use_flow_style = false)
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

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Robot_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Robot_Result & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Robot_Result>()
{
  return "action_interface::action::Robot_Result";
}

template<>
inline const char * name<action_interface::action::Robot_Result>()
{
  return "action_interface/action/Robot_Result";
}

template<>
struct has_fixed_size<action_interface::action::Robot_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<action_interface::action::Robot_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<action_interface::action::Robot_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Robot_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: percent_complete
  {
    out << "percent_complete: ";
    rosidl_generator_traits::value_to_yaml(msg.percent_complete, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Robot_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: percent_complete
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "percent_complete: ";
    rosidl_generator_traits::value_to_yaml(msg.percent_complete, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Robot_Feedback & msg, bool use_flow_style = false)
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

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Robot_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Robot_Feedback & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Robot_Feedback>()
{
  return "action_interface::action::Robot_Feedback";
}

template<>
inline const char * name<action_interface::action::Robot_Feedback>()
{
  return "action_interface/action/Robot_Feedback";
}

template<>
struct has_fixed_size<action_interface::action::Robot_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<action_interface::action::Robot_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<action_interface::action::Robot_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "action_interface/action/detail/robot__traits.hpp"

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Robot_SendGoal_Request & msg,
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
  const Robot_SendGoal_Request & msg,
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

inline std::string to_yaml(const Robot_SendGoal_Request & msg, bool use_flow_style = false)
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

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Robot_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Robot_SendGoal_Request & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Robot_SendGoal_Request>()
{
  return "action_interface::action::Robot_SendGoal_Request";
}

template<>
inline const char * name<action_interface::action::Robot_SendGoal_Request>()
{
  return "action_interface/action/Robot_SendGoal_Request";
}

template<>
struct has_fixed_size<action_interface::action::Robot_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<action_interface::action::Robot_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<action_interface::action::Robot_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<action_interface::action::Robot_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<action_interface::action::Robot_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Robot_SendGoal_Response & msg,
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
  const Robot_SendGoal_Response & msg,
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

inline std::string to_yaml(const Robot_SendGoal_Response & msg, bool use_flow_style = false)
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

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Robot_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Robot_SendGoal_Response & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Robot_SendGoal_Response>()
{
  return "action_interface::action::Robot_SendGoal_Response";
}

template<>
inline const char * name<action_interface::action::Robot_SendGoal_Response>()
{
  return "action_interface/action/Robot_SendGoal_Response";
}

template<>
struct has_fixed_size<action_interface::action::Robot_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<action_interface::action::Robot_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<action_interface::action::Robot_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Robot_SendGoal_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Robot_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Robot_SendGoal_Event & msg, bool use_flow_style = false)
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

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Robot_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Robot_SendGoal_Event & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Robot_SendGoal_Event>()
{
  return "action_interface::action::Robot_SendGoal_Event";
}

template<>
inline const char * name<action_interface::action::Robot_SendGoal_Event>()
{
  return "action_interface/action/Robot_SendGoal_Event";
}

template<>
struct has_fixed_size<action_interface::action::Robot_SendGoal_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_interface::action::Robot_SendGoal_Event>
  : std::integral_constant<bool, has_bounded_size<action_interface::action::Robot_SendGoal_Request>::value && has_bounded_size<action_interface::action::Robot_SendGoal_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<action_interface::action::Robot_SendGoal_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interface::action::Robot_SendGoal>()
{
  return "action_interface::action::Robot_SendGoal";
}

template<>
inline const char * name<action_interface::action::Robot_SendGoal>()
{
  return "action_interface/action/Robot_SendGoal";
}

template<>
struct has_fixed_size<action_interface::action::Robot_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<action_interface::action::Robot_SendGoal_Request>::value &&
    has_fixed_size<action_interface::action::Robot_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<action_interface::action::Robot_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<action_interface::action::Robot_SendGoal_Request>::value &&
    has_bounded_size<action_interface::action::Robot_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<action_interface::action::Robot_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<action_interface::action::Robot_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<action_interface::action::Robot_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Robot_GetResult_Request & msg,
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
  const Robot_GetResult_Request & msg,
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

inline std::string to_yaml(const Robot_GetResult_Request & msg, bool use_flow_style = false)
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

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Robot_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Robot_GetResult_Request & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Robot_GetResult_Request>()
{
  return "action_interface::action::Robot_GetResult_Request";
}

template<>
inline const char * name<action_interface::action::Robot_GetResult_Request>()
{
  return "action_interface/action/Robot_GetResult_Request";
}

template<>
struct has_fixed_size<action_interface::action::Robot_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<action_interface::action::Robot_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<action_interface::action::Robot_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "action_interface/action/detail/robot__traits.hpp"

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Robot_GetResult_Response & msg,
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
  const Robot_GetResult_Response & msg,
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

inline std::string to_yaml(const Robot_GetResult_Response & msg, bool use_flow_style = false)
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

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Robot_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Robot_GetResult_Response & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Robot_GetResult_Response>()
{
  return "action_interface::action::Robot_GetResult_Response";
}

template<>
inline const char * name<action_interface::action::Robot_GetResult_Response>()
{
  return "action_interface/action/Robot_GetResult_Response";
}

template<>
struct has_fixed_size<action_interface::action::Robot_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<action_interface::action::Robot_Result>::value> {};

template<>
struct has_bounded_size<action_interface::action::Robot_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<action_interface::action::Robot_Result>::value> {};

template<>
struct is_message<action_interface::action::Robot_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Robot_GetResult_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Robot_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Robot_GetResult_Event & msg, bool use_flow_style = false)
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

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Robot_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Robot_GetResult_Event & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Robot_GetResult_Event>()
{
  return "action_interface::action::Robot_GetResult_Event";
}

template<>
inline const char * name<action_interface::action::Robot_GetResult_Event>()
{
  return "action_interface/action/Robot_GetResult_Event";
}

template<>
struct has_fixed_size<action_interface::action::Robot_GetResult_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_interface::action::Robot_GetResult_Event>
  : std::integral_constant<bool, has_bounded_size<action_interface::action::Robot_GetResult_Request>::value && has_bounded_size<action_interface::action::Robot_GetResult_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<action_interface::action::Robot_GetResult_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interface::action::Robot_GetResult>()
{
  return "action_interface::action::Robot_GetResult";
}

template<>
inline const char * name<action_interface::action::Robot_GetResult>()
{
  return "action_interface/action/Robot_GetResult";
}

template<>
struct has_fixed_size<action_interface::action::Robot_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<action_interface::action::Robot_GetResult_Request>::value &&
    has_fixed_size<action_interface::action::Robot_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<action_interface::action::Robot_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<action_interface::action::Robot_GetResult_Request>::value &&
    has_bounded_size<action_interface::action::Robot_GetResult_Response>::value
  >
{
};

template<>
struct is_service<action_interface::action::Robot_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<action_interface::action::Robot_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<action_interface::action::Robot_GetResult_Response>
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
// #include "action_interface/action/detail/robot__traits.hpp"

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Robot_FeedbackMessage & msg,
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
  const Robot_FeedbackMessage & msg,
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

inline std::string to_yaml(const Robot_FeedbackMessage & msg, bool use_flow_style = false)
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

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Robot_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Robot_FeedbackMessage & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Robot_FeedbackMessage>()
{
  return "action_interface::action::Robot_FeedbackMessage";
}

template<>
inline const char * name<action_interface::action::Robot_FeedbackMessage>()
{
  return "action_interface/action/Robot_FeedbackMessage";
}

template<>
struct has_fixed_size<action_interface::action::Robot_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<action_interface::action::Robot_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<action_interface::action::Robot_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<action_interface::action::Robot_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<action_interface::action::Robot_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<action_interface::action::Robot>
  : std::true_type
{
};

template<>
struct is_action_goal<action_interface::action::Robot_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<action_interface::action::Robot_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<action_interface::action::Robot_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // ACTION_INTERFACE__ACTION__DETAIL__ROBOT__TRAITS_HPP_
