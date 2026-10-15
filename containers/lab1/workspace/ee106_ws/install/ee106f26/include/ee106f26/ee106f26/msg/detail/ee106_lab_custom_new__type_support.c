// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ee106f26:msg/EE106LabCustomNew.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ee106f26/msg/detail/ee106_lab_custom_new__rosidl_typesupport_introspection_c.h"
#include "ee106f26/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ee106f26/msg/detail/ee106_lab_custom_new__functions.h"
#include "ee106f26/msg/detail/ee106_lab_custom_new__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ee106f26__msg__EE106LabCustomNew__rosidl_typesupport_introspection_c__EE106LabCustomNew_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ee106f26__msg__EE106LabCustomNew__init(message_memory);
}

void ee106f26__msg__EE106LabCustomNew__rosidl_typesupport_introspection_c__EE106LabCustomNew_fini_function(void * message_memory)
{
  ee106f26__msg__EE106LabCustomNew__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ee106f26__msg__EE106LabCustomNew__rosidl_typesupport_introspection_c__EE106LabCustomNew_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ee106f26__msg__EE106LabCustomNew, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "int_data1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ee106f26__msg__EE106LabCustomNew, int_data1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "int_data2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ee106f26__msg__EE106LabCustomNew, int_data2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ee106f26__msg__EE106LabCustomNew__rosidl_typesupport_introspection_c__EE106LabCustomNew_message_members = {
  "ee106f26__msg",  // message namespace
  "EE106LabCustomNew",  // message name
  3,  // number of fields
  sizeof(ee106f26__msg__EE106LabCustomNew),
  false,  // has_any_key_member_
  ee106f26__msg__EE106LabCustomNew__rosidl_typesupport_introspection_c__EE106LabCustomNew_message_member_array,  // message members
  ee106f26__msg__EE106LabCustomNew__rosidl_typesupport_introspection_c__EE106LabCustomNew_init_function,  // function to initialize message memory (memory has to be allocated)
  ee106f26__msg__EE106LabCustomNew__rosidl_typesupport_introspection_c__EE106LabCustomNew_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ee106f26__msg__EE106LabCustomNew__rosidl_typesupport_introspection_c__EE106LabCustomNew_message_type_support_handle = {
  0,
  &ee106f26__msg__EE106LabCustomNew__rosidl_typesupport_introspection_c__EE106LabCustomNew_message_members,
  get_message_typesupport_handle_function,
  &ee106f26__msg__EE106LabCustomNew__get_type_hash,
  &ee106f26__msg__EE106LabCustomNew__get_type_description,
  &ee106f26__msg__EE106LabCustomNew__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ee106f26
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ee106f26, msg, EE106LabCustomNew)() {
  ee106f26__msg__EE106LabCustomNew__rosidl_typesupport_introspection_c__EE106LabCustomNew_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!ee106f26__msg__EE106LabCustomNew__rosidl_typesupport_introspection_c__EE106LabCustomNew_message_type_support_handle.typesupport_identifier) {
    ee106f26__msg__EE106LabCustomNew__rosidl_typesupport_introspection_c__EE106LabCustomNew_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ee106f26__msg__EE106LabCustomNew__rosidl_typesupport_introspection_c__EE106LabCustomNew_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
