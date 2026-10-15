// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ee106f26:msg/EE106LabCustom.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ee106f26/msg/ee106_lab_custom.hpp"


#ifndef EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM__STRUCT_HPP_
#define EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ee106f26__msg__EE106LabCustom __attribute__((deprecated))
#else
# define DEPRECATED__ee106f26__msg__EE106LabCustom __declspec(deprecated)
#endif

namespace ee106f26
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EE106LabCustom_
{
  using Type = EE106LabCustom_<ContainerAllocator>;

  explicit EE106LabCustom_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->int_data = 0l;
      this->float_data = 0.0f;
      this->string_data = "";
    }
  }

  explicit EE106LabCustom_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    string_data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->int_data = 0l;
      this->float_data = 0.0f;
      this->string_data = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _int_data_type =
    int32_t;
  _int_data_type int_data;
  using _float_data_type =
    float;
  _float_data_type float_data;
  using _string_data_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _string_data_type string_data;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__int_data(
    const int32_t & _arg)
  {
    this->int_data = _arg;
    return *this;
  }
  Type & set__float_data(
    const float & _arg)
  {
    this->float_data = _arg;
    return *this;
  }
  Type & set__string_data(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->string_data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ee106f26::msg::EE106LabCustom_<ContainerAllocator> *;
  using ConstRawPtr =
    const ee106f26::msg::EE106LabCustom_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ee106f26::msg::EE106LabCustom_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ee106f26::msg::EE106LabCustom_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ee106f26::msg::EE106LabCustom_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ee106f26::msg::EE106LabCustom_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ee106f26::msg::EE106LabCustom_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ee106f26::msg::EE106LabCustom_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ee106f26::msg::EE106LabCustom_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ee106f26::msg::EE106LabCustom_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ee106f26__msg__EE106LabCustom
    std::shared_ptr<ee106f26::msg::EE106LabCustom_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ee106f26__msg__EE106LabCustom
    std::shared_ptr<ee106f26::msg::EE106LabCustom_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EE106LabCustom_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->int_data != other.int_data) {
      return false;
    }
    if (this->float_data != other.float_data) {
      return false;
    }
    if (this->string_data != other.string_data) {
      return false;
    }
    return true;
  }
  bool operator!=(const EE106LabCustom_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EE106LabCustom_

// alias to use template instance with default allocator
using EE106LabCustom =
  ee106f26::msg::EE106LabCustom_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ee106f26

#endif  // EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM__STRUCT_HPP_
