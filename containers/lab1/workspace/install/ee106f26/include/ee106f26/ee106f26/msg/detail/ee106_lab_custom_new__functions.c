// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ee106f26:msg/EE106LabCustomNew.idl
// generated code does not contain a copyright notice
#include "ee106f26/msg/detail/ee106_lab_custom_new__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
ee106f26__msg__EE106LabCustomNew__init(ee106f26__msg__EE106LabCustomNew * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    ee106f26__msg__EE106LabCustomNew__fini(msg);
    return false;
  }
  // int_data1
  // int_data2
  return true;
}

void
ee106f26__msg__EE106LabCustomNew__fini(ee106f26__msg__EE106LabCustomNew * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // int_data1
  // int_data2
}

bool
ee106f26__msg__EE106LabCustomNew__are_equal(const ee106f26__msg__EE106LabCustomNew * lhs, const ee106f26__msg__EE106LabCustomNew * rhs)
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
  // int_data1
  if (lhs->int_data1 != rhs->int_data1) {
    return false;
  }
  // int_data2
  if (lhs->int_data2 != rhs->int_data2) {
    return false;
  }
  return true;
}

bool
ee106f26__msg__EE106LabCustomNew__copy(
  const ee106f26__msg__EE106LabCustomNew * input,
  ee106f26__msg__EE106LabCustomNew * output)
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
  // int_data1
  output->int_data1 = input->int_data1;
  // int_data2
  output->int_data2 = input->int_data2;
  return true;
}

ee106f26__msg__EE106LabCustomNew *
ee106f26__msg__EE106LabCustomNew__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ee106f26__msg__EE106LabCustomNew * msg = (ee106f26__msg__EE106LabCustomNew *)allocator.allocate(sizeof(ee106f26__msg__EE106LabCustomNew), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ee106f26__msg__EE106LabCustomNew));
  bool success = ee106f26__msg__EE106LabCustomNew__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ee106f26__msg__EE106LabCustomNew__destroy(ee106f26__msg__EE106LabCustomNew * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ee106f26__msg__EE106LabCustomNew__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ee106f26__msg__EE106LabCustomNew__Sequence__init(ee106f26__msg__EE106LabCustomNew__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ee106f26__msg__EE106LabCustomNew * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(ee106f26__msg__EE106LabCustomNew)) {
      return false;
    }
    data = (ee106f26__msg__EE106LabCustomNew *)allocator.zero_allocate(size, sizeof(ee106f26__msg__EE106LabCustomNew), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ee106f26__msg__EE106LabCustomNew__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ee106f26__msg__EE106LabCustomNew__fini(&data[i - 1]);
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
ee106f26__msg__EE106LabCustomNew__Sequence__fini(ee106f26__msg__EE106LabCustomNew__Sequence * array)
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
      ee106f26__msg__EE106LabCustomNew__fini(&array->data[i]);
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

ee106f26__msg__EE106LabCustomNew__Sequence *
ee106f26__msg__EE106LabCustomNew__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ee106f26__msg__EE106LabCustomNew__Sequence * array = (ee106f26__msg__EE106LabCustomNew__Sequence *)allocator.allocate(sizeof(ee106f26__msg__EE106LabCustomNew__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ee106f26__msg__EE106LabCustomNew__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ee106f26__msg__EE106LabCustomNew__Sequence__destroy(ee106f26__msg__EE106LabCustomNew__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ee106f26__msg__EE106LabCustomNew__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ee106f26__msg__EE106LabCustomNew__Sequence__are_equal(const ee106f26__msg__EE106LabCustomNew__Sequence * lhs, const ee106f26__msg__EE106LabCustomNew__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ee106f26__msg__EE106LabCustomNew__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ee106f26__msg__EE106LabCustomNew__Sequence__copy(
  const ee106f26__msg__EE106LabCustomNew__Sequence * input,
  ee106f26__msg__EE106LabCustomNew__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(ee106f26__msg__EE106LabCustomNew)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(ee106f26__msg__EE106LabCustomNew);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ee106f26__msg__EE106LabCustomNew * data =
      (ee106f26__msg__EE106LabCustomNew *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ee106f26__msg__EE106LabCustomNew__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ee106f26__msg__EE106LabCustomNew__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ee106f26__msg__EE106LabCustomNew__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
