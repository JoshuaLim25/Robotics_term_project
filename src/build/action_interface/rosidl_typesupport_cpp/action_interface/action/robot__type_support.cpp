// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from action_interface:action/Robot.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "action_interface/action/detail/robot__functions.h"
#include "action_interface/action/detail/robot__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace action_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Robot_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Robot_Goal_type_support_ids_t;

static const _Robot_Goal_type_support_ids_t _Robot_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Robot_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Robot_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Robot_Goal_type_support_symbol_names_t _Robot_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interface, action, Robot_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interface, action, Robot_Goal)),
  }
};

typedef struct _Robot_Goal_type_support_data_t
{
  void * data[2];
} _Robot_Goal_type_support_data_t;

static _Robot_Goal_type_support_data_t _Robot_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Robot_Goal_message_typesupport_map = {
  2,
  "action_interface",
  &_Robot_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_Robot_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_Robot_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Robot_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Robot_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &action_interface__action__Robot_Goal__get_type_hash,
  &action_interface__action__Robot_Goal__get_type_description,
  &action_interface__action__Robot_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interface::action::Robot_Goal>()
{
  return &::action_interface::action::rosidl_typesupport_cpp::Robot_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interface, action, Robot_Goal)() {
  return get_message_type_support_handle<action_interface::action::Robot_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interface/action/detail/robot__functions.h"
// already included above
// #include "action_interface/action/detail/robot__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Robot_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Robot_Result_type_support_ids_t;

static const _Robot_Result_type_support_ids_t _Robot_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Robot_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Robot_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Robot_Result_type_support_symbol_names_t _Robot_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interface, action, Robot_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interface, action, Robot_Result)),
  }
};

typedef struct _Robot_Result_type_support_data_t
{
  void * data[2];
} _Robot_Result_type_support_data_t;

static _Robot_Result_type_support_data_t _Robot_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Robot_Result_message_typesupport_map = {
  2,
  "action_interface",
  &_Robot_Result_message_typesupport_ids.typesupport_identifier[0],
  &_Robot_Result_message_typesupport_symbol_names.symbol_name[0],
  &_Robot_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Robot_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Robot_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &action_interface__action__Robot_Result__get_type_hash,
  &action_interface__action__Robot_Result__get_type_description,
  &action_interface__action__Robot_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interface::action::Robot_Result>()
{
  return &::action_interface::action::rosidl_typesupport_cpp::Robot_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interface, action, Robot_Result)() {
  return get_message_type_support_handle<action_interface::action::Robot_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interface/action/detail/robot__functions.h"
// already included above
// #include "action_interface/action/detail/robot__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Robot_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Robot_Feedback_type_support_ids_t;

static const _Robot_Feedback_type_support_ids_t _Robot_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Robot_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Robot_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Robot_Feedback_type_support_symbol_names_t _Robot_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interface, action, Robot_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interface, action, Robot_Feedback)),
  }
};

typedef struct _Robot_Feedback_type_support_data_t
{
  void * data[2];
} _Robot_Feedback_type_support_data_t;

static _Robot_Feedback_type_support_data_t _Robot_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Robot_Feedback_message_typesupport_map = {
  2,
  "action_interface",
  &_Robot_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_Robot_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_Robot_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Robot_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Robot_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &action_interface__action__Robot_Feedback__get_type_hash,
  &action_interface__action__Robot_Feedback__get_type_description,
  &action_interface__action__Robot_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interface::action::Robot_Feedback>()
{
  return &::action_interface::action::rosidl_typesupport_cpp::Robot_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interface, action, Robot_Feedback)() {
  return get_message_type_support_handle<action_interface::action::Robot_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interface/action/detail/robot__functions.h"
// already included above
// #include "action_interface/action/detail/robot__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Robot_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Robot_SendGoal_Request_type_support_ids_t;

static const _Robot_SendGoal_Request_type_support_ids_t _Robot_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Robot_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Robot_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Robot_SendGoal_Request_type_support_symbol_names_t _Robot_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interface, action, Robot_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interface, action, Robot_SendGoal_Request)),
  }
};

typedef struct _Robot_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _Robot_SendGoal_Request_type_support_data_t;

static _Robot_SendGoal_Request_type_support_data_t _Robot_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Robot_SendGoal_Request_message_typesupport_map = {
  2,
  "action_interface",
  &_Robot_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Robot_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Robot_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Robot_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Robot_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &action_interface__action__Robot_SendGoal_Request__get_type_hash,
  &action_interface__action__Robot_SendGoal_Request__get_type_description,
  &action_interface__action__Robot_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interface::action::Robot_SendGoal_Request>()
{
  return &::action_interface::action::rosidl_typesupport_cpp::Robot_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interface, action, Robot_SendGoal_Request)() {
  return get_message_type_support_handle<action_interface::action::Robot_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interface/action/detail/robot__functions.h"
// already included above
// #include "action_interface/action/detail/robot__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Robot_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Robot_SendGoal_Response_type_support_ids_t;

static const _Robot_SendGoal_Response_type_support_ids_t _Robot_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Robot_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Robot_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Robot_SendGoal_Response_type_support_symbol_names_t _Robot_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interface, action, Robot_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interface, action, Robot_SendGoal_Response)),
  }
};

typedef struct _Robot_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _Robot_SendGoal_Response_type_support_data_t;

static _Robot_SendGoal_Response_type_support_data_t _Robot_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Robot_SendGoal_Response_message_typesupport_map = {
  2,
  "action_interface",
  &_Robot_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Robot_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Robot_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Robot_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Robot_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &action_interface__action__Robot_SendGoal_Response__get_type_hash,
  &action_interface__action__Robot_SendGoal_Response__get_type_description,
  &action_interface__action__Robot_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interface::action::Robot_SendGoal_Response>()
{
  return &::action_interface::action::rosidl_typesupport_cpp::Robot_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interface, action, Robot_SendGoal_Response)() {
  return get_message_type_support_handle<action_interface::action::Robot_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interface/action/detail/robot__functions.h"
// already included above
// #include "action_interface/action/detail/robot__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Robot_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Robot_SendGoal_Event_type_support_ids_t;

static const _Robot_SendGoal_Event_type_support_ids_t _Robot_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Robot_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Robot_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Robot_SendGoal_Event_type_support_symbol_names_t _Robot_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interface, action, Robot_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interface, action, Robot_SendGoal_Event)),
  }
};

typedef struct _Robot_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _Robot_SendGoal_Event_type_support_data_t;

static _Robot_SendGoal_Event_type_support_data_t _Robot_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Robot_SendGoal_Event_message_typesupport_map = {
  2,
  "action_interface",
  &_Robot_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Robot_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Robot_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Robot_SendGoal_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Robot_SendGoal_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &action_interface__action__Robot_SendGoal_Event__get_type_hash,
  &action_interface__action__Robot_SendGoal_Event__get_type_description,
  &action_interface__action__Robot_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interface::action::Robot_SendGoal_Event>()
{
  return &::action_interface::action::rosidl_typesupport_cpp::Robot_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interface, action, Robot_SendGoal_Event)() {
  return get_message_type_support_handle<action_interface::action::Robot_SendGoal_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "action_interface/action/detail/robot__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Robot_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Robot_SendGoal_type_support_ids_t;

static const _Robot_SendGoal_type_support_ids_t _Robot_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Robot_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Robot_SendGoal_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Robot_SendGoal_type_support_symbol_names_t _Robot_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interface, action, Robot_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interface, action, Robot_SendGoal)),
  }
};

typedef struct _Robot_SendGoal_type_support_data_t
{
  void * data[2];
} _Robot_SendGoal_type_support_data_t;

static _Robot_SendGoal_type_support_data_t _Robot_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Robot_SendGoal_service_typesupport_map = {
  2,
  "action_interface",
  &_Robot_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_Robot_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_Robot_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Robot_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Robot_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<action_interface::action::Robot_SendGoal_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<action_interface::action::Robot_SendGoal_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<action_interface::action::Robot_SendGoal_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<action_interface::action::Robot_SendGoal>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<action_interface::action::Robot_SendGoal>,
  &action_interface__action__Robot_SendGoal__get_type_hash,
  &action_interface__action__Robot_SendGoal__get_type_description,
  &action_interface__action__Robot_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<action_interface::action::Robot_SendGoal>()
{
  return &::action_interface::action::rosidl_typesupport_cpp::Robot_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interface/action/detail/robot__functions.h"
// already included above
// #include "action_interface/action/detail/robot__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Robot_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Robot_GetResult_Request_type_support_ids_t;

static const _Robot_GetResult_Request_type_support_ids_t _Robot_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Robot_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Robot_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Robot_GetResult_Request_type_support_symbol_names_t _Robot_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interface, action, Robot_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interface, action, Robot_GetResult_Request)),
  }
};

typedef struct _Robot_GetResult_Request_type_support_data_t
{
  void * data[2];
} _Robot_GetResult_Request_type_support_data_t;

static _Robot_GetResult_Request_type_support_data_t _Robot_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Robot_GetResult_Request_message_typesupport_map = {
  2,
  "action_interface",
  &_Robot_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Robot_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Robot_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Robot_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Robot_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &action_interface__action__Robot_GetResult_Request__get_type_hash,
  &action_interface__action__Robot_GetResult_Request__get_type_description,
  &action_interface__action__Robot_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interface::action::Robot_GetResult_Request>()
{
  return &::action_interface::action::rosidl_typesupport_cpp::Robot_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interface, action, Robot_GetResult_Request)() {
  return get_message_type_support_handle<action_interface::action::Robot_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interface/action/detail/robot__functions.h"
// already included above
// #include "action_interface/action/detail/robot__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Robot_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Robot_GetResult_Response_type_support_ids_t;

static const _Robot_GetResult_Response_type_support_ids_t _Robot_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Robot_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Robot_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Robot_GetResult_Response_type_support_symbol_names_t _Robot_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interface, action, Robot_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interface, action, Robot_GetResult_Response)),
  }
};

typedef struct _Robot_GetResult_Response_type_support_data_t
{
  void * data[2];
} _Robot_GetResult_Response_type_support_data_t;

static _Robot_GetResult_Response_type_support_data_t _Robot_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Robot_GetResult_Response_message_typesupport_map = {
  2,
  "action_interface",
  &_Robot_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Robot_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Robot_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Robot_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Robot_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &action_interface__action__Robot_GetResult_Response__get_type_hash,
  &action_interface__action__Robot_GetResult_Response__get_type_description,
  &action_interface__action__Robot_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interface::action::Robot_GetResult_Response>()
{
  return &::action_interface::action::rosidl_typesupport_cpp::Robot_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interface, action, Robot_GetResult_Response)() {
  return get_message_type_support_handle<action_interface::action::Robot_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interface/action/detail/robot__functions.h"
// already included above
// #include "action_interface/action/detail/robot__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Robot_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Robot_GetResult_Event_type_support_ids_t;

static const _Robot_GetResult_Event_type_support_ids_t _Robot_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Robot_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Robot_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Robot_GetResult_Event_type_support_symbol_names_t _Robot_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interface, action, Robot_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interface, action, Robot_GetResult_Event)),
  }
};

typedef struct _Robot_GetResult_Event_type_support_data_t
{
  void * data[2];
} _Robot_GetResult_Event_type_support_data_t;

static _Robot_GetResult_Event_type_support_data_t _Robot_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Robot_GetResult_Event_message_typesupport_map = {
  2,
  "action_interface",
  &_Robot_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Robot_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Robot_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Robot_GetResult_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Robot_GetResult_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &action_interface__action__Robot_GetResult_Event__get_type_hash,
  &action_interface__action__Robot_GetResult_Event__get_type_description,
  &action_interface__action__Robot_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interface::action::Robot_GetResult_Event>()
{
  return &::action_interface::action::rosidl_typesupport_cpp::Robot_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interface, action, Robot_GetResult_Event)() {
  return get_message_type_support_handle<action_interface::action::Robot_GetResult_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "action_interface/action/detail/robot__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Robot_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Robot_GetResult_type_support_ids_t;

static const _Robot_GetResult_type_support_ids_t _Robot_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Robot_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Robot_GetResult_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Robot_GetResult_type_support_symbol_names_t _Robot_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interface, action, Robot_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interface, action, Robot_GetResult)),
  }
};

typedef struct _Robot_GetResult_type_support_data_t
{
  void * data[2];
} _Robot_GetResult_type_support_data_t;

static _Robot_GetResult_type_support_data_t _Robot_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Robot_GetResult_service_typesupport_map = {
  2,
  "action_interface",
  &_Robot_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_Robot_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_Robot_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Robot_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Robot_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<action_interface::action::Robot_GetResult_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<action_interface::action::Robot_GetResult_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<action_interface::action::Robot_GetResult_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<action_interface::action::Robot_GetResult>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<action_interface::action::Robot_GetResult>,
  &action_interface__action__Robot_GetResult__get_type_hash,
  &action_interface__action__Robot_GetResult__get_type_description,
  &action_interface__action__Robot_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<action_interface::action::Robot_GetResult>()
{
  return &::action_interface::action::rosidl_typesupport_cpp::Robot_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interface/action/detail/robot__functions.h"
// already included above
// #include "action_interface/action/detail/robot__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Robot_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Robot_FeedbackMessage_type_support_ids_t;

static const _Robot_FeedbackMessage_type_support_ids_t _Robot_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Robot_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Robot_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Robot_FeedbackMessage_type_support_symbol_names_t _Robot_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, action_interface, action, Robot_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, action_interface, action, Robot_FeedbackMessage)),
  }
};

typedef struct _Robot_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _Robot_FeedbackMessage_type_support_data_t;

static _Robot_FeedbackMessage_type_support_data_t _Robot_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Robot_FeedbackMessage_message_typesupport_map = {
  2,
  "action_interface",
  &_Robot_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_Robot_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_Robot_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Robot_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Robot_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &action_interface__action__Robot_FeedbackMessage__get_type_hash,
  &action_interface__action__Robot_FeedbackMessage__get_type_description,
  &action_interface__action__Robot_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<action_interface::action::Robot_FeedbackMessage>()
{
  return &::action_interface::action::rosidl_typesupport_cpp::Robot_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, action_interface, action, Robot_FeedbackMessage)() {
  return get_message_type_support_handle<action_interface::action::Robot_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "action_interface/action/detail/robot__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace action_interface
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t Robot_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL,
  &action_interface__action__Robot__get_type_hash,
  &action_interface__action__Robot__get_type_description,
  &action_interface__action__Robot__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace action_interface

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<action_interface::action::Robot>()
{
  using ::action_interface::action::rosidl_typesupport_cpp::Robot_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  Robot_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::action_interface::action::Robot::Impl::SendGoalService>();
  Robot_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::action_interface::action::Robot::Impl::GetResultService>();
  Robot_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::action_interface::action::Robot::Impl::CancelGoalService>();
  Robot_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::action_interface::action::Robot::Impl::FeedbackMessage>();
  Robot_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::action_interface::action::Robot::Impl::GoalStatusMessage>();
  return &Robot_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp
