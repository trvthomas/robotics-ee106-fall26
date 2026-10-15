// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ee106f26:msg/EE106LabCustomNew.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ee106f26/msg/ee106_lab_custom_new.hpp"


#ifndef EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM_NEW__BUILDER_HPP_
#define EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM_NEW__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ee106f26/msg/detail/ee106_lab_custom_new__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ee106f26
{

namespace msg
{

namespace builder
{

class Init_EE106LabCustomNew_int_data2
{
public:
  explicit Init_EE106LabCustomNew_int_data2(::ee106f26::msg::EE106LabCustomNew & msg)
  : msg_(msg)
  {}
  ::ee106f26::msg::EE106LabCustomNew int_data2(::ee106f26::msg::EE106LabCustomNew::_int_data2_type arg)
  {
    msg_.int_data2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ee106f26::msg::EE106LabCustomNew msg_;
};

class Init_EE106LabCustomNew_int_data1
{
public:
  explicit Init_EE106LabCustomNew_int_data1(::ee106f26::msg::EE106LabCustomNew & msg)
  : msg_(msg)
  {}
  Init_EE106LabCustomNew_int_data2 int_data1(::ee106f26::msg::EE106LabCustomNew::_int_data1_type arg)
  {
    msg_.int_data1 = std::move(arg);
    return Init_EE106LabCustomNew_int_data2(msg_);
  }

private:
  ::ee106f26::msg::EE106LabCustomNew msg_;
};

class Init_EE106LabCustomNew_header
{
public:
  Init_EE106LabCustomNew_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EE106LabCustomNew_int_data1 header(::ee106f26::msg::EE106LabCustomNew::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_EE106LabCustomNew_int_data1(msg_);
  }

private:
  ::ee106f26::msg::EE106LabCustomNew msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ee106f26::msg::EE106LabCustomNew>()
{
  return ee106f26::msg::builder::Init_EE106LabCustomNew_header();
}

}  // namespace ee106f26

#endif  // EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM_NEW__BUILDER_HPP_
