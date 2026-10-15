// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ee106f26:msg/EE106LabCustomNew.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ee106f26/msg/ee106_lab_custom_new.hpp"


#ifndef EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM_NEW__TRAITS_HPP_
#define EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM_NEW__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ee106f26/msg/detail/ee106_lab_custom_new__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace ee106f26
{

namespace msg
{

inline void to_flow_style_yaml(
  const EE106LabCustomNew & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: int_data1
  {
    out << "int_data1: ";
    rosidl_generator_traits::value_to_yaml(msg.int_data1, out);
    out << ", ";
  }

  // member: int_data2
  {
    out << "int_data2: ";
    rosidl_generator_traits::value_to_yaml(msg.int_data2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EE106LabCustomNew & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: int_data1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "int_data1: ";
    rosidl_generator_traits::value_to_yaml(msg.int_data1, out);
    out << "\n";
  }

  // member: int_data2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "int_data2: ";
    rosidl_generator_traits::value_to_yaml(msg.int_data2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EE106LabCustomNew & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ee106f26

namespace rosidl_generator_traits
{

[[deprecated("use ee106f26::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ee106f26::msg::EE106LabCustomNew & msg,
  std::ostream & out, size_t indentation = 0)
{
  ee106f26::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ee106f26::msg::to_yaml() instead")]]
inline std::string to_yaml(const ee106f26::msg::EE106LabCustomNew & msg)
{
  return ee106f26::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ee106f26::msg::EE106LabCustomNew>()
{
  return "ee106f26::msg::EE106LabCustomNew";
}

template<>
inline const char * name<ee106f26::msg::EE106LabCustomNew>()
{
  return "ee106f26/msg/EE106LabCustomNew";
}

template<>
struct has_fixed_size<ee106f26::msg::EE106LabCustomNew>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<ee106f26::msg::EE106LabCustomNew>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<ee106f26::msg::EE106LabCustomNew>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // EE106F26__MSG__DETAIL__EE106_LAB_CUSTOM_NEW__TRAITS_HPP_
