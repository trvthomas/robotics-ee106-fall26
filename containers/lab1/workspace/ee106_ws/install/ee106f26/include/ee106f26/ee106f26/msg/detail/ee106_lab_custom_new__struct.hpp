// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ee106f26:msg/EE106LabCustomNew.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ee106f26/msg/ee106_lab_custom_new.hpp"


#ifndef EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM_NEW__STRUCT_HPP_
#define EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM_NEW__STRUCT_HPP_

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
# define DEPRECATED__ee106f26__msg__EE106LabCustomNew __attribute__((deprecated))
#else
# define DEPRECATED__ee106f26__msg__EE106LabCustomNew __declspec(deprecated)
#endif

namespace ee106f26
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EE106LabCustomNew_
{
  using Type = EE106LabCustomNew_<ContainerAllocator>;

  explicit EE106LabCustomNew_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->int_data1 = 0l;
      this->int_data2 = 0l;
    }
  }

  explicit EE106LabCustomNew_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->int_data1 = 0l;
      this->int_data2 = 0l;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _int_data1_type =
    int32_t;
  _int_data1_type int_data1;
  using _int_data2_type =
    int32_t;
  _int_data2_type int_data2;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__int_data1(
    const int32_t & _arg)
  {
    this->int_data1 = _arg;
    return *this;
  }
  Type & set__int_data2(
    const int32_t & _arg)
  {
    this->int_data2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ee106f26::msg::EE106LabCustomNew_<ContainerAllocator> *;
  using ConstRawPtr =
    const ee106f26::msg::EE106LabCustomNew_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ee106f26::msg::EE106LabCustomNew_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ee106f26::msg::EE106LabCustomNew_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ee106f26::msg::EE106LabCustomNew_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ee106f26::msg::EE106LabCustomNew_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ee106f26::msg::EE106LabCustomNew_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ee106f26::msg::EE106LabCustomNew_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ee106f26::msg::EE106LabCustomNew_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ee106f26::msg::EE106LabCustomNew_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ee106f26__msg__EE106LabCustomNew
    std::shared_ptr<ee106f26::msg::EE106LabCustomNew_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ee106f26__msg__EE106LabCustomNew
    std::shared_ptr<ee106f26::msg::EE106LabCustomNew_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EE106LabCustomNew_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->int_data1 != other.int_data1) {
      return false;
    }
    if (this->int_data2 != other.int_data2) {
      return false;
    }
    return true;
  }
  bool operator!=(const EE106LabCustomNew_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EE106LabCustomNew_

// alias to use template instance with default allocator
using EE106LabCustomNew =
  ee106f26::msg::EE106LabCustomNew_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ee106f26

#endif  // EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM_NEW__STRUCT_HPP_
