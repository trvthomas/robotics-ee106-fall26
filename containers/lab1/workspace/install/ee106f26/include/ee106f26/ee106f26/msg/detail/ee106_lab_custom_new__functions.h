// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ee106f26:msg/EE106LabCustomNew.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ee106f26/msg/ee106_lab_custom_new.h"


#ifndef EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM_NEW__FUNCTIONS_H_
#define EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM_NEW__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "ee106f26/msg/rosidl_generator_c__visibility_control.h"

#include "ee106f26/msg/detail/ee106_lab_custom_new__struct.h"

/// Initialize msg/EE106LabCustomNew message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ee106f26__msg__EE106LabCustomNew
 * )) before or use
 * ee106f26__msg__EE106LabCustomNew__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ee106f26
bool
ee106f26__msg__EE106LabCustomNew__init(ee106f26__msg__EE106LabCustomNew * msg);

/// Finalize msg/EE106LabCustomNew message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ee106f26
void
ee106f26__msg__EE106LabCustomNew__fini(ee106f26__msg__EE106LabCustomNew * msg);

/// Create msg/EE106LabCustomNew message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ee106f26__msg__EE106LabCustomNew__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ee106f26
ee106f26__msg__EE106LabCustomNew *
ee106f26__msg__EE106LabCustomNew__create(void);

/// Destroy msg/EE106LabCustomNew message.
/**
 * It calls
 * ee106f26__msg__EE106LabCustomNew__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ee106f26
void
ee106f26__msg__EE106LabCustomNew__destroy(ee106f26__msg__EE106LabCustomNew * msg);

/// Check for msg/EE106LabCustomNew message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ee106f26
bool
ee106f26__msg__EE106LabCustomNew__are_equal(const ee106f26__msg__EE106LabCustomNew * lhs, const ee106f26__msg__EE106LabCustomNew * rhs);

/// Copy a msg/EE106LabCustomNew message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ee106f26
bool
ee106f26__msg__EE106LabCustomNew__copy(
  const ee106f26__msg__EE106LabCustomNew * input,
  ee106f26__msg__EE106LabCustomNew * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_ee106f26
const rosidl_type_hash_t *
ee106f26__msg__EE106LabCustomNew__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_ee106f26
const rosidl_runtime_c__type_description__TypeDescription *
ee106f26__msg__EE106LabCustomNew__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_ee106f26
const rosidl_runtime_c__type_description__TypeSource *
ee106f26__msg__EE106LabCustomNew__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_ee106f26
const rosidl_runtime_c__type_description__TypeSource__Sequence *
ee106f26__msg__EE106LabCustomNew__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/EE106LabCustomNew messages.
/**
 * It allocates the memory for the number of elements and calls
 * ee106f26__msg__EE106LabCustomNew__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ee106f26
bool
ee106f26__msg__EE106LabCustomNew__Sequence__init(ee106f26__msg__EE106LabCustomNew__Sequence * array, size_t size);

/// Finalize array of msg/EE106LabCustomNew messages.
/**
 * It calls
 * ee106f26__msg__EE106LabCustomNew__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ee106f26
void
ee106f26__msg__EE106LabCustomNew__Sequence__fini(ee106f26__msg__EE106LabCustomNew__Sequence * array);

/// Create array of msg/EE106LabCustomNew messages.
/**
 * It allocates the memory for the array and calls
 * ee106f26__msg__EE106LabCustomNew__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ee106f26
ee106f26__msg__EE106LabCustomNew__Sequence *
ee106f26__msg__EE106LabCustomNew__Sequence__create(size_t size);

/// Destroy array of msg/EE106LabCustomNew messages.
/**
 * It calls
 * ee106f26__msg__EE106LabCustomNew__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ee106f26
void
ee106f26__msg__EE106LabCustomNew__Sequence__destroy(ee106f26__msg__EE106LabCustomNew__Sequence * array);

/// Check for msg/EE106LabCustomNew message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ee106f26
bool
ee106f26__msg__EE106LabCustomNew__Sequence__are_equal(const ee106f26__msg__EE106LabCustomNew__Sequence * lhs, const ee106f26__msg__EE106LabCustomNew__Sequence * rhs);

/// Copy an array of msg/EE106LabCustomNew messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ee106f26
bool
ee106f26__msg__EE106LabCustomNew__Sequence__copy(
  const ee106f26__msg__EE106LabCustomNew__Sequence * input,
  ee106f26__msg__EE106LabCustomNew__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM_NEW__FUNCTIONS_H_
