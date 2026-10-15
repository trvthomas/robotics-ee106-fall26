// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ee106f26:msg/EE106LabCustom.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ee106f26/msg/ee106_lab_custom.hpp"


#ifndef EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM__BUILDER_HPP_
#define EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ee106f26/msg/detail/ee106_lab_custom__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ee106f26
{

namespace msg
{

namespace builder
{

class Init_EE106LabCustom_string_data
{
public:
  explicit Init_EE106LabCustom_string_data(::ee106f26::msg::EE106LabCustom & msg)
  : msg_(msg)
  {}
  ::ee106f26::msg::EE106LabCustom string_data(::ee106f26::msg::EE106LabCustom::_string_data_type arg)
  {
    msg_.string_data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ee106f26::msg::EE106LabCustom msg_;
};

class Init_EE106LabCustom_float_data
{
public:
  explicit Init_EE106LabCustom_float_data(::ee106f26::msg::EE106LabCustom & msg)
  : msg_(msg)
  {}
  Init_EE106LabCustom_string_data float_data(::ee106f26::msg::EE106LabCustom::_float_data_type arg)
  {
    msg_.float_data = std::move(arg);
    return Init_EE106LabCustom_string_data(msg_);
  }

private:
  ::ee106f26::msg::EE106LabCustom msg_;
};

class Init_EE106LabCustom_int_data
{
public:
  explicit Init_EE106LabCustom_int_data(::ee106f26::msg::EE106LabCustom & msg)
  : msg_(msg)
  {}
  Init_EE106LabCustom_float_data int_data(::ee106f26::msg::EE106LabCustom::_int_data_type arg)
  {
    msg_.int_data = std::move(arg);
    return Init_EE106LabCustom_float_data(msg_);
  }

private:
  ::ee106f26::msg::EE106LabCustom msg_;
};

class Init_EE106LabCustom_header
{
public:
  Init_EE106LabCustom_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EE106LabCustom_int_data header(::ee106f26::msg::EE106LabCustom::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_EE106LabCustom_int_data(msg_);
  }

private:
  ::ee106f26::msg::EE106LabCustom msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ee106f26::msg::EE106LabCustom>()
{
  return ee106f26::msg::builder::Init_EE106LabCustom_header();
}

}  // namespace ee106f26

#endif  // EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM__BUILDER_HPP_
