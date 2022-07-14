// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from um7:srv/Reset.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "um7/srv/detail/reset__rosidl_typesupport_introspection_c.h"
#include "um7/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "um7/srv/detail/reset__functions.h"
#include "um7/srv/detail/reset__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Reset_Request__rosidl_typesupport_introspection_c__Reset_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  um7__srv__Reset_Request__init(message_memory);
}

void Reset_Request__rosidl_typesupport_introspection_c__Reset_Request_fini_function(void * message_memory)
{
  um7__srv__Reset_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Reset_Request__rosidl_typesupport_introspection_c__Reset_Request_message_member_array[3] = {
  {
    "zero_gyros",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(um7__srv__Reset_Request, zero_gyros),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "reset_ekf",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(um7__srv__Reset_Request, reset_ekf),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "set_mag_ref",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(um7__srv__Reset_Request, set_mag_ref),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Reset_Request__rosidl_typesupport_introspection_c__Reset_Request_message_members = {
  "um7__srv",  // message namespace
  "Reset_Request",  // message name
  3,  // number of fields
  sizeof(um7__srv__Reset_Request),
  Reset_Request__rosidl_typesupport_introspection_c__Reset_Request_message_member_array,  // message members
  Reset_Request__rosidl_typesupport_introspection_c__Reset_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  Reset_Request__rosidl_typesupport_introspection_c__Reset_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Reset_Request__rosidl_typesupport_introspection_c__Reset_Request_message_type_support_handle = {
  0,
  &Reset_Request__rosidl_typesupport_introspection_c__Reset_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_um7
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, um7, srv, Reset_Request)() {
  if (!Reset_Request__rosidl_typesupport_introspection_c__Reset_Request_message_type_support_handle.typesupport_identifier) {
    Reset_Request__rosidl_typesupport_introspection_c__Reset_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Reset_Request__rosidl_typesupport_introspection_c__Reset_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "um7/srv/detail/reset__rosidl_typesupport_introspection_c.h"
// already included above
// #include "um7/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "um7/srv/detail/reset__functions.h"
// already included above
// #include "um7/srv/detail/reset__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Reset_Response__rosidl_typesupport_introspection_c__Reset_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  um7__srv__Reset_Response__init(message_memory);
}

void Reset_Response__rosidl_typesupport_introspection_c__Reset_Response_fini_function(void * message_memory)
{
  um7__srv__Reset_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Reset_Response__rosidl_typesupport_introspection_c__Reset_Response_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(um7__srv__Reset_Response, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Reset_Response__rosidl_typesupport_introspection_c__Reset_Response_message_members = {
  "um7__srv",  // message namespace
  "Reset_Response",  // message name
  1,  // number of fields
  sizeof(um7__srv__Reset_Response),
  Reset_Response__rosidl_typesupport_introspection_c__Reset_Response_message_member_array,  // message members
  Reset_Response__rosidl_typesupport_introspection_c__Reset_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  Reset_Response__rosidl_typesupport_introspection_c__Reset_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Reset_Response__rosidl_typesupport_introspection_c__Reset_Response_message_type_support_handle = {
  0,
  &Reset_Response__rosidl_typesupport_introspection_c__Reset_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_um7
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, um7, srv, Reset_Response)() {
  if (!Reset_Response__rosidl_typesupport_introspection_c__Reset_Response_message_type_support_handle.typesupport_identifier) {
    Reset_Response__rosidl_typesupport_introspection_c__Reset_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Reset_Response__rosidl_typesupport_introspection_c__Reset_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "um7/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "um7/srv/detail/reset__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers um7__srv__detail__reset__rosidl_typesupport_introspection_c__Reset_service_members = {
  "um7__srv",  // service namespace
  "Reset",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // um7__srv__detail__reset__rosidl_typesupport_introspection_c__Reset_Request_message_type_support_handle,
  NULL  // response message
  // um7__srv__detail__reset__rosidl_typesupport_introspection_c__Reset_Response_message_type_support_handle
};

static rosidl_service_type_support_t um7__srv__detail__reset__rosidl_typesupport_introspection_c__Reset_service_type_support_handle = {
  0,
  &um7__srv__detail__reset__rosidl_typesupport_introspection_c__Reset_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, um7, srv, Reset_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, um7, srv, Reset_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_um7
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, um7, srv, Reset)() {
  if (!um7__srv__detail__reset__rosidl_typesupport_introspection_c__Reset_service_type_support_handle.typesupport_identifier) {
    um7__srv__detail__reset__rosidl_typesupport_introspection_c__Reset_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)um7__srv__detail__reset__rosidl_typesupport_introspection_c__Reset_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, um7, srv, Reset_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, um7, srv, Reset_Response)()->data;
  }

  return &um7__srv__detail__reset__rosidl_typesupport_introspection_c__Reset_service_type_support_handle;
}
