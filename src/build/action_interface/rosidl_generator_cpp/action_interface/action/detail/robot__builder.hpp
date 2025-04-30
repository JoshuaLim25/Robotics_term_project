// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interface:action/Robot.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACE__ACTION__DETAIL__ROBOT__BUILDER_HPP_
#define ACTION_INTERFACE__ACTION__DETAIL__ROBOT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "action_interface/action/detail/robot__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Robot_Goal_drive_time
{
public:
  explicit Init_Robot_Goal_drive_time(::action_interface::action::Robot_Goal & msg)
  : msg_(msg)
  {}
  ::action_interface::action::Robot_Goal drive_time(::action_interface::action::Robot_Goal::_drive_time_type arg)
  {
    msg_.drive_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Robot_Goal msg_;
};

class Init_Robot_Goal_w_z
{
public:
  explicit Init_Robot_Goal_w_z(::action_interface::action::Robot_Goal & msg)
  : msg_(msg)
  {}
  Init_Robot_Goal_drive_time w_z(::action_interface::action::Robot_Goal::_w_z_type arg)
  {
    msg_.w_z = std::move(arg);
    return Init_Robot_Goal_drive_time(msg_);
  }

private:
  ::action_interface::action::Robot_Goal msg_;
};

class Init_Robot_Goal_v_x
{
public:
  Init_Robot_Goal_v_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Robot_Goal_w_z v_x(::action_interface::action::Robot_Goal::_v_x_type arg)
  {
    msg_.v_x = std::move(arg);
    return Init_Robot_Goal_w_z(msg_);
  }

private:
  ::action_interface::action::Robot_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Robot_Goal>()
{
  return action_interface::action::builder::Init_Robot_Goal_v_x();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Robot_Result_complete
{
public:
  Init_Robot_Result_complete()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interface::action::Robot_Result complete(::action_interface::action::Robot_Result::_complete_type arg)
  {
    msg_.complete = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Robot_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Robot_Result>()
{
  return action_interface::action::builder::Init_Robot_Result_complete();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Robot_Feedback_percent_complete
{
public:
  Init_Robot_Feedback_percent_complete()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interface::action::Robot_Feedback percent_complete(::action_interface::action::Robot_Feedback::_percent_complete_type arg)
  {
    msg_.percent_complete = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Robot_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Robot_Feedback>()
{
  return action_interface::action::builder::Init_Robot_Feedback_percent_complete();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Robot_SendGoal_Request_goal
{
public:
  explicit Init_Robot_SendGoal_Request_goal(::action_interface::action::Robot_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::action_interface::action::Robot_SendGoal_Request goal(::action_interface::action::Robot_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Robot_SendGoal_Request msg_;
};

class Init_Robot_SendGoal_Request_goal_id
{
public:
  Init_Robot_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Robot_SendGoal_Request_goal goal_id(::action_interface::action::Robot_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Robot_SendGoal_Request_goal(msg_);
  }

private:
  ::action_interface::action::Robot_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Robot_SendGoal_Request>()
{
  return action_interface::action::builder::Init_Robot_SendGoal_Request_goal_id();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Robot_SendGoal_Response_stamp
{
public:
  explicit Init_Robot_SendGoal_Response_stamp(::action_interface::action::Robot_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::action_interface::action::Robot_SendGoal_Response stamp(::action_interface::action::Robot_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Robot_SendGoal_Response msg_;
};

class Init_Robot_SendGoal_Response_accepted
{
public:
  Init_Robot_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Robot_SendGoal_Response_stamp accepted(::action_interface::action::Robot_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Robot_SendGoal_Response_stamp(msg_);
  }

private:
  ::action_interface::action::Robot_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Robot_SendGoal_Response>()
{
  return action_interface::action::builder::Init_Robot_SendGoal_Response_accepted();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Robot_SendGoal_Event_response
{
public:
  explicit Init_Robot_SendGoal_Event_response(::action_interface::action::Robot_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::action_interface::action::Robot_SendGoal_Event response(::action_interface::action::Robot_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Robot_SendGoal_Event msg_;
};

class Init_Robot_SendGoal_Event_request
{
public:
  explicit Init_Robot_SendGoal_Event_request(::action_interface::action::Robot_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_Robot_SendGoal_Event_response request(::action_interface::action::Robot_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Robot_SendGoal_Event_response(msg_);
  }

private:
  ::action_interface::action::Robot_SendGoal_Event msg_;
};

class Init_Robot_SendGoal_Event_info
{
public:
  Init_Robot_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Robot_SendGoal_Event_request info(::action_interface::action::Robot_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Robot_SendGoal_Event_request(msg_);
  }

private:
  ::action_interface::action::Robot_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Robot_SendGoal_Event>()
{
  return action_interface::action::builder::Init_Robot_SendGoal_Event_info();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Robot_GetResult_Request_goal_id
{
public:
  Init_Robot_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interface::action::Robot_GetResult_Request goal_id(::action_interface::action::Robot_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Robot_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Robot_GetResult_Request>()
{
  return action_interface::action::builder::Init_Robot_GetResult_Request_goal_id();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Robot_GetResult_Response_result
{
public:
  explicit Init_Robot_GetResult_Response_result(::action_interface::action::Robot_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::action_interface::action::Robot_GetResult_Response result(::action_interface::action::Robot_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Robot_GetResult_Response msg_;
};

class Init_Robot_GetResult_Response_status
{
public:
  Init_Robot_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Robot_GetResult_Response_result status(::action_interface::action::Robot_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Robot_GetResult_Response_result(msg_);
  }

private:
  ::action_interface::action::Robot_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Robot_GetResult_Response>()
{
  return action_interface::action::builder::Init_Robot_GetResult_Response_status();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Robot_GetResult_Event_response
{
public:
  explicit Init_Robot_GetResult_Event_response(::action_interface::action::Robot_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::action_interface::action::Robot_GetResult_Event response(::action_interface::action::Robot_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Robot_GetResult_Event msg_;
};

class Init_Robot_GetResult_Event_request
{
public:
  explicit Init_Robot_GetResult_Event_request(::action_interface::action::Robot_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_Robot_GetResult_Event_response request(::action_interface::action::Robot_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Robot_GetResult_Event_response(msg_);
  }

private:
  ::action_interface::action::Robot_GetResult_Event msg_;
};

class Init_Robot_GetResult_Event_info
{
public:
  Init_Robot_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Robot_GetResult_Event_request info(::action_interface::action::Robot_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Robot_GetResult_Event_request(msg_);
  }

private:
  ::action_interface::action::Robot_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Robot_GetResult_Event>()
{
  return action_interface::action::builder::Init_Robot_GetResult_Event_info();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Robot_FeedbackMessage_feedback
{
public:
  explicit Init_Robot_FeedbackMessage_feedback(::action_interface::action::Robot_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::action_interface::action::Robot_FeedbackMessage feedback(::action_interface::action::Robot_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Robot_FeedbackMessage msg_;
};

class Init_Robot_FeedbackMessage_goal_id
{
public:
  Init_Robot_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Robot_FeedbackMessage_feedback goal_id(::action_interface::action::Robot_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Robot_FeedbackMessage_feedback(msg_);
  }

private:
  ::action_interface::action::Robot_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Robot_FeedbackMessage>()
{
  return action_interface::action::builder::Init_Robot_FeedbackMessage_goal_id();
}

}  // namespace action_interface

#endif  // ACTION_INTERFACE__ACTION__DETAIL__ROBOT__BUILDER_HPP_
