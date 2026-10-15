// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ee106f26:msg/EE106LabCustom.idl
// generated code does not contain a copyright notice
#include "ee106f26/msg/detail/ee106_lab_custom__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `string_data`
#include "rosidl_runtime_c/string_functions.h"

bool
ee106f26__msg__EE106LabCustom__init(ee106f26__msg__EE106LabCustom * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    ee106f26__msg__EE106LabCustom__fini(msg);
    return false;
  }
  // int_data
  // float_data
  // string_data
  if (!rosidl_runtime_c__String__init(&msg->string_data)) {
    ee106f26__msg__EE106LabCustom__fini(msg);
    return false;
  }
  return true;
}

void
ee106f26__msg__EE106LabCustom__fini(ee106f26__msg__EE106LabCustom * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // int_data
  // float_data
  // string_data
  rosidl_runtime_c__String__fini(&msg->string_data);
}

bool
ee106f26__msg__EE106LabCustom__are_equal(const ee106f26__msg__EE106LabCustom * lhs, const ee106f26__msg__EE106LabCustom * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // int_data
  if (lhs->int_data != rhs->int_data) {
    return false;
  }
  // float_data
  if (lhs->float_data != rhs->float_data) {
    return false;
  }
  // string_data
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->string_data), &(rhs->string_data)))
  {
    return false;
  }
  return true;
}

bool
ee106f26__msg__EE106LabCustom__copy(
  const ee106f26__msg__EE106LabCustom * input,
  ee106f26__msg__EE106LabCustom * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // int_data
  output->int_data = input->int_data;
  // float_data
  output->float_data = input->float_data;
  // string_data
  if (!rosidl_runtime_c__String__copy(
      &(input->string_data), &(output->string_data)))
  {
    return false;
  }
  return true;
}

ee106f26__msg__EE106LabCustom *
ee106f26__msg__EE106LabCustom__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ee106f26__msg__EE106LabCustom * msg = (ee106f26__msg__EE106LabCustom *)allocator.allocate(sizeof(ee106f26__msg__EE106LabCustom), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ee106f26__msg__EE106LabCustom));
  bool success = ee106f26__msg__EE106LabCustom__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ee106f26__msg__EE106LabCustom__destroy(ee106f26__msg__EE106LabCustom * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ee106f26__msg__EE106LabCustom__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ee106f26__msg__EE106LabCustom__Sequence__init(ee106f26__msg__EE106LabCustom__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ee106f26__msg__EE106LabCustom * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(ee106f26__msg__EE106LabCustom)) {
      return false;
    }
    data = (ee106f26__msg__EE106LabCustom *)allocator.zero_allocate(size, sizeof(ee106f26__msg__EE106LabCustom), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ee106f26__msg__EE106LabCustom__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ee106f26__msg__EE106LabCustom__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ee106f26__msg__EE106LabCustom__Sequence__fini(ee106f26__msg__EE106LabCustom__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ee106f26__msg__EE106LabCustom__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ee106f26__msg__EE106LabCustom__Sequence *
ee106f26__msg__EE106LabCustom__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ee106f26__msg__EE106LabCustom__Sequence * array = (ee106f26__msg__EE106LabCustom__Sequence *)allocator.allocate(sizeof(ee106f26__msg__EE106LabCustom__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ee106f26__msg__EE106LabCustom__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ee106f26__msg__EE106LabCustom__Sequence__destroy(ee106f26__msg__EE106LabCustom__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ee106f26__msg__EE106LabCustom__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ee106f26__msg__EE106LabCustom__Sequence__are_equal(const ee106f26__msg__EE106LabCustom__Sequence * lhs, const ee106f26__msg__EE106LabCustom__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ee106f26__msg__EE106LabCustom__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ee106f26__msg__EE106LabCustom__Sequence__copy(
  const ee106f26__msg__EE106LabCustom__Sequence * input,
  ee106f26__msg__EE106LabCustom__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(ee106f26__msg__EE106LabCustom)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(ee106f26__msg__EE106LabCustom);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ee106f26__msg__EE106LabCustom * data =
      (ee106f26__msg__EE106LabCustom *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ee106f26__msg__EE106LabCustom__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ee106f26__msg__EE106LabCustom__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ee106f26__msg__EE106LabCustom__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
