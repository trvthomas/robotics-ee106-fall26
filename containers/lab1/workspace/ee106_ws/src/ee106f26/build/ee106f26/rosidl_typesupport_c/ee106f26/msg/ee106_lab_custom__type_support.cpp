// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from ee106f26:msg/EE106LabCustom.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "ee106f26/msg/detail/ee106_lab_custom__struct.h"
#include "ee106f26/msg/detail/ee106_lab_custom__type_support.h"
#include "ee106f26/msg/detail/ee106_lab_custom__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace ee106f26
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _EE106LabCustom_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _EE106LabCustom_type_support_ids_t;

static const _EE106LabCustom_type_support_ids_t _EE106LabCustom_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _EE106LabCustom_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _EE106LabCustom_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _EE106LabCustom_type_support_symbol_names_t _EE106LabCustom_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ee106f26, msg, EE106LabCustom)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ee106f26, msg, EE106LabCustom)),
  }
};

typedef struct _EE106LabCustom_type_support_data_t
{
  void * data[2];
} _EE106LabCustom_type_support_data_t;

static _EE106LabCustom_type_support_data_t _EE106LabCustom_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _EE106LabCustom_message_typesupport_map = {
  2,
  "ee106f26",
  &_EE106LabCustom_message_typesupport_ids.typesupport_identifier[0],
  &_EE106LabCustom_message_typesupport_symbol_names.symbol_name[0],
  &_EE106LabCustom_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t EE106LabCustom_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_EE106LabCustom_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &ee106f26__msg__EE106LabCustom__get_type_hash,
  &ee106f26__msg__EE106LabCustom__get_type_description,
  &ee106f26__msg__EE106LabCustom__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace ee106f26

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, ee106f26, msg, EE106LabCustom)() {
  return &::ee106f26::msg::rosidl_typesupport_c::EE106LabCustom_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
