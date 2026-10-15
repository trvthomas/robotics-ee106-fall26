// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ee106f26:msg/EE106LabCustom.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ee106f26/msg/ee106_lab_custom.h"


#ifndef EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM__STRUCT_H_
#define EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'string_data'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/EE106LabCustom in the package ee106f26.
typedef struct ee106f26__msg__EE106LabCustom
{
  std_msgs__msg__Header header;
  int32_t int_data;
  float float_data;
  rosidl_runtime_c__String string_data;
} ee106f26__msg__EE106LabCustom;

// Struct for a sequence of ee106f26__msg__EE106LabCustom.
typedef struct ee106f26__msg__EE106LabCustom__Sequence
{
  ee106f26__msg__EE106LabCustom * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ee106f26__msg__EE106LabCustom__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM__STRUCT_H_
