// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from action_interface:action/Robot.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACE__ACTION__DETAIL__ROBOT__STRUCT_HPP_
#define ACTION_INTERFACE__ACTION__DETAIL__ROBOT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__action_interface__action__Robot_Goal __attribute__((deprecated))
#else
# define DEPRECATED__action_interface__action__Robot_Goal __declspec(deprecated)
#endif

namespace action_interface
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Robot_Goal_
{
  using Type = Robot_Goal_<ContainerAllocator>;

  explicit Robot_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->v_x = 0.0f;
      this->w_z = 0.0f;
      this->drive_time = 0.0f;
    }
  }

  explicit Robot_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->v_x = 0.0f;
      this->w_z = 0.0f;
      this->drive_time = 0.0f;
    }
  }

  // field types and members
  using _v_x_type =
    float;
  _v_x_type v_x;
  using _w_z_type =
    float;
  _w_z_type w_z;
  using _drive_time_type =
    float;
  _drive_time_type drive_time;

  // setters for named parameter idiom
  Type & set__v_x(
    const float & _arg)
  {
    this->v_x = _arg;
    return *this;
  }
  Type & set__w_z(
    const float & _arg)
  {
    this->w_z = _arg;
    return *this;
  }
  Type & set__drive_time(
    const float & _arg)
  {
    this->drive_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interface::action::Robot_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interface::action::Robot_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interface::action::Robot_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interface::action::Robot_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interface::action::Robot_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interface::action::Robot_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interface__action__Robot_Goal
    std::shared_ptr<action_interface::action::Robot_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interface__action__Robot_Goal
    std::shared_ptr<action_interface::action::Robot_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Robot_Goal_ & other) const
  {
    if (this->v_x != other.v_x) {
      return false;
    }
    if (this->w_z != other.w_z) {
      return false;
    }
    if (this->drive_time != other.drive_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const Robot_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Robot_Goal_

// alias to use template instance with default allocator
using Robot_Goal =
  action_interface::action::Robot_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_interface


#ifndef _WIN32
# define DEPRECATED__action_interface__action__Robot_Result __attribute__((deprecated))
#else
# define DEPRECATED__action_interface__action__Robot_Result __declspec(deprecated)
#endif

namespace action_interface
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Robot_Result_
{
  using Type = Robot_Result_<ContainerAllocator>;

  explicit Robot_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->complete = false;
    }
  }

  explicit Robot_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->complete = false;
    }
  }

  // field types and members
  using _complete_type =
    bool;
  _complete_type complete;

  // setters for named parameter idiom
  Type & set__complete(
    const bool & _arg)
  {
    this->complete = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interface::action::Robot_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interface::action::Robot_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interface::action::Robot_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interface::action::Robot_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interface::action::Robot_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interface::action::Robot_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interface__action__Robot_Result
    std::shared_ptr<action_interface::action::Robot_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interface__action__Robot_Result
    std::shared_ptr<action_interface::action::Robot_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Robot_Result_ & other) const
  {
    if (this->complete != other.complete) {
      return false;
    }
    return true;
  }
  bool operator!=(const Robot_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Robot_Result_

// alias to use template instance with default allocator
using Robot_Result =
  action_interface::action::Robot_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_interface


#ifndef _WIN32
# define DEPRECATED__action_interface__action__Robot_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__action_interface__action__Robot_Feedback __declspec(deprecated)
#endif

namespace action_interface
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Robot_Feedback_
{
  using Type = Robot_Feedback_<ContainerAllocator>;

  explicit Robot_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->percent_complete = 0.0f;
    }
  }

  explicit Robot_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->percent_complete = 0.0f;
    }
  }

  // field types and members
  using _percent_complete_type =
    float;
  _percent_complete_type percent_complete;

  // setters for named parameter idiom
  Type & set__percent_complete(
    const float & _arg)
  {
    this->percent_complete = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interface::action::Robot_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interface::action::Robot_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interface::action::Robot_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interface::action::Robot_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interface::action::Robot_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interface::action::Robot_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interface__action__Robot_Feedback
    std::shared_ptr<action_interface::action::Robot_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interface__action__Robot_Feedback
    std::shared_ptr<action_interface::action::Robot_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Robot_Feedback_ & other) const
  {
    if (this->percent_complete != other.percent_complete) {
      return false;
    }
    return true;
  }
  bool operator!=(const Robot_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Robot_Feedback_

// alias to use template instance with default allocator
using Robot_Feedback =
  action_interface::action::Robot_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_interface


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "action_interface/action/detail/robot__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__action_interface__action__Robot_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__action_interface__action__Robot_SendGoal_Request __declspec(deprecated)
#endif

namespace action_interface
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Robot_SendGoal_Request_
{
  using Type = Robot_SendGoal_Request_<ContainerAllocator>;

  explicit Robot_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit Robot_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    action_interface::action::Robot_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const action_interface::action::Robot_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interface::action::Robot_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interface::action::Robot_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interface::action::Robot_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interface::action::Robot_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interface::action::Robot_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interface::action::Robot_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interface__action__Robot_SendGoal_Request
    std::shared_ptr<action_interface::action::Robot_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interface__action__Robot_SendGoal_Request
    std::shared_ptr<action_interface::action::Robot_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Robot_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const Robot_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Robot_SendGoal_Request_

// alias to use template instance with default allocator
using Robot_SendGoal_Request =
  action_interface::action::Robot_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_interface


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__action_interface__action__Robot_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__action_interface__action__Robot_SendGoal_Response __declspec(deprecated)
#endif

namespace action_interface
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Robot_SendGoal_Response_
{
  using Type = Robot_SendGoal_Response_<ContainerAllocator>;

  explicit Robot_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit Robot_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interface::action::Robot_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interface::action::Robot_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interface::action::Robot_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interface::action::Robot_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interface::action::Robot_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interface::action::Robot_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interface__action__Robot_SendGoal_Response
    std::shared_ptr<action_interface::action::Robot_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interface__action__Robot_SendGoal_Response
    std::shared_ptr<action_interface::action::Robot_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Robot_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const Robot_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Robot_SendGoal_Response_

// alias to use template instance with default allocator
using Robot_SendGoal_Response =
  action_interface::action::Robot_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_interface


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__action_interface__action__Robot_SendGoal_Event __attribute__((deprecated))
#else
# define DEPRECATED__action_interface__action__Robot_SendGoal_Event __declspec(deprecated)
#endif

namespace action_interface
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Robot_SendGoal_Event_
{
  using Type = Robot_SendGoal_Event_<ContainerAllocator>;

  explicit Robot_SendGoal_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit Robot_SendGoal_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<action_interface::action::Robot_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<action_interface::action::Robot_SendGoal_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<action_interface::action::Robot_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<action_interface::action::Robot_SendGoal_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<action_interface::action::Robot_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<action_interface::action::Robot_SendGoal_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<action_interface::action::Robot_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<action_interface::action::Robot_SendGoal_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interface::action::Robot_SendGoal_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interface::action::Robot_SendGoal_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interface::action::Robot_SendGoal_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interface::action::Robot_SendGoal_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_SendGoal_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_SendGoal_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_SendGoal_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_SendGoal_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interface::action::Robot_SendGoal_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interface::action::Robot_SendGoal_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interface__action__Robot_SendGoal_Event
    std::shared_ptr<action_interface::action::Robot_SendGoal_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interface__action__Robot_SendGoal_Event
    std::shared_ptr<action_interface::action::Robot_SendGoal_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Robot_SendGoal_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const Robot_SendGoal_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Robot_SendGoal_Event_

// alias to use template instance with default allocator
using Robot_SendGoal_Event =
  action_interface::action::Robot_SendGoal_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_interface

namespace action_interface
{

namespace action
{

struct Robot_SendGoal
{
  using Request = action_interface::action::Robot_SendGoal_Request;
  using Response = action_interface::action::Robot_SendGoal_Response;
  using Event = action_interface::action::Robot_SendGoal_Event;
};

}  // namespace action

}  // namespace action_interface


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__action_interface__action__Robot_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__action_interface__action__Robot_GetResult_Request __declspec(deprecated)
#endif

namespace action_interface
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Robot_GetResult_Request_
{
  using Type = Robot_GetResult_Request_<ContainerAllocator>;

  explicit Robot_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit Robot_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interface::action::Robot_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interface::action::Robot_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interface::action::Robot_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interface::action::Robot_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interface::action::Robot_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interface::action::Robot_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interface__action__Robot_GetResult_Request
    std::shared_ptr<action_interface::action::Robot_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interface__action__Robot_GetResult_Request
    std::shared_ptr<action_interface::action::Robot_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Robot_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const Robot_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Robot_GetResult_Request_

// alias to use template instance with default allocator
using Robot_GetResult_Request =
  action_interface::action::Robot_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_interface


// Include directives for member types
// Member 'result'
// already included above
// #include "action_interface/action/detail/robot__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__action_interface__action__Robot_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__action_interface__action__Robot_GetResult_Response __declspec(deprecated)
#endif

namespace action_interface
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Robot_GetResult_Response_
{
  using Type = Robot_GetResult_Response_<ContainerAllocator>;

  explicit Robot_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit Robot_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    action_interface::action::Robot_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const action_interface::action::Robot_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interface::action::Robot_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interface::action::Robot_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interface::action::Robot_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interface::action::Robot_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interface::action::Robot_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interface::action::Robot_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interface__action__Robot_GetResult_Response
    std::shared_ptr<action_interface::action::Robot_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interface__action__Robot_GetResult_Response
    std::shared_ptr<action_interface::action::Robot_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Robot_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Robot_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Robot_GetResult_Response_

// alias to use template instance with default allocator
using Robot_GetResult_Response =
  action_interface::action::Robot_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_interface


// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__action_interface__action__Robot_GetResult_Event __attribute__((deprecated))
#else
# define DEPRECATED__action_interface__action__Robot_GetResult_Event __declspec(deprecated)
#endif

namespace action_interface
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Robot_GetResult_Event_
{
  using Type = Robot_GetResult_Event_<ContainerAllocator>;

  explicit Robot_GetResult_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit Robot_GetResult_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<action_interface::action::Robot_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<action_interface::action::Robot_GetResult_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<action_interface::action::Robot_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<action_interface::action::Robot_GetResult_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<action_interface::action::Robot_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<action_interface::action::Robot_GetResult_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<action_interface::action::Robot_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<action_interface::action::Robot_GetResult_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interface::action::Robot_GetResult_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interface::action::Robot_GetResult_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interface::action::Robot_GetResult_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interface::action::Robot_GetResult_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_GetResult_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_GetResult_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_GetResult_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_GetResult_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interface::action::Robot_GetResult_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interface::action::Robot_GetResult_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interface__action__Robot_GetResult_Event
    std::shared_ptr<action_interface::action::Robot_GetResult_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interface__action__Robot_GetResult_Event
    std::shared_ptr<action_interface::action::Robot_GetResult_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Robot_GetResult_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const Robot_GetResult_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Robot_GetResult_Event_

// alias to use template instance with default allocator
using Robot_GetResult_Event =
  action_interface::action::Robot_GetResult_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_interface

namespace action_interface
{

namespace action
{

struct Robot_GetResult
{
  using Request = action_interface::action::Robot_GetResult_Request;
  using Response = action_interface::action::Robot_GetResult_Response;
  using Event = action_interface::action::Robot_GetResult_Event;
};

}  // namespace action

}  // namespace action_interface


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "action_interface/action/detail/robot__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__action_interface__action__Robot_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__action_interface__action__Robot_FeedbackMessage __declspec(deprecated)
#endif

namespace action_interface
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Robot_FeedbackMessage_
{
  using Type = Robot_FeedbackMessage_<ContainerAllocator>;

  explicit Robot_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit Robot_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    action_interface::action::Robot_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const action_interface::action::Robot_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interface::action::Robot_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interface::action::Robot_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interface::action::Robot_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interface::action::Robot_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interface::action::Robot_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interface::action::Robot_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interface::action::Robot_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interface::action::Robot_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interface__action__Robot_FeedbackMessage
    std::shared_ptr<action_interface::action::Robot_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interface__action__Robot_FeedbackMessage
    std::shared_ptr<action_interface::action::Robot_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Robot_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const Robot_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Robot_FeedbackMessage_

// alias to use template instance with default allocator
using Robot_FeedbackMessage =
  action_interface::action::Robot_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace action_interface

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace action_interface
{

namespace action
{

struct Robot
{
  /// The goal message defined in the action definition.
  using Goal = action_interface::action::Robot_Goal;
  /// The result message defined in the action definition.
  using Result = action_interface::action::Robot_Result;
  /// The feedback message defined in the action definition.
  using Feedback = action_interface::action::Robot_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = action_interface::action::Robot_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = action_interface::action::Robot_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = action_interface::action::Robot_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct Robot Robot;

}  // namespace action

}  // namespace action_interface

#endif  // ACTION_INTERFACE__ACTION__DETAIL__ROBOT__STRUCT_HPP_
