#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "ee106f26__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ee106f26__msg__EE106LabCustom() -> *const std::ffi::c_void;
}

#[link(name = "ee106f26__rosidl_generator_c")]
extern "C" {
    fn ee106f26__msg__EE106LabCustom__init(msg: *mut EE106LabCustom) -> bool;
    fn ee106f26__msg__EE106LabCustom__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<EE106LabCustom>, size: usize) -> bool;
    fn ee106f26__msg__EE106LabCustom__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<EE106LabCustom>);
    fn ee106f26__msg__EE106LabCustom__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<EE106LabCustom>, out_seq: *mut rosidl_runtime_rs::Sequence<EE106LabCustom>) -> bool;
}

// Corresponds to ee106f26__msg__EE106LabCustom
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EE106LabCustom {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int_data: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float_data: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_data: rosidl_runtime_rs::String,

}



impl Default for EE106LabCustom {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ee106f26__msg__EE106LabCustom__init(&mut msg as *mut _) {
        panic!("Call to ee106f26__msg__EE106LabCustom__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for EE106LabCustom {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ee106f26__msg__EE106LabCustom__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ee106f26__msg__EE106LabCustom__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ee106f26__msg__EE106LabCustom__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for EE106LabCustom {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for EE106LabCustom where Self: Sized {
  const TYPE_NAME: &'static str = "ee106f26/msg/EE106LabCustom";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ee106f26__msg__EE106LabCustom() }
  }
}


#[link(name = "ee106f26__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ee106f26__msg__EE106LabCustomNew() -> *const std::ffi::c_void;
}

#[link(name = "ee106f26__rosidl_generator_c")]
extern "C" {
    fn ee106f26__msg__EE106LabCustomNew__init(msg: *mut EE106LabCustomNew) -> bool;
    fn ee106f26__msg__EE106LabCustomNew__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<EE106LabCustomNew>, size: usize) -> bool;
    fn ee106f26__msg__EE106LabCustomNew__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<EE106LabCustomNew>);
    fn ee106f26__msg__EE106LabCustomNew__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<EE106LabCustomNew>, out_seq: *mut rosidl_runtime_rs::Sequence<EE106LabCustomNew>) -> bool;
}

// Corresponds to ee106f26__msg__EE106LabCustomNew
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EE106LabCustomNew {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int_data1: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int_data2: i32,

}



impl Default for EE106LabCustomNew {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ee106f26__msg__EE106LabCustomNew__init(&mut msg as *mut _) {
        panic!("Call to ee106f26__msg__EE106LabCustomNew__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for EE106LabCustomNew {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ee106f26__msg__EE106LabCustomNew__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ee106f26__msg__EE106LabCustomNew__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ee106f26__msg__EE106LabCustomNew__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for EE106LabCustomNew {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for EE106LabCustomNew where Self: Sized {
  const TYPE_NAME: &'static str = "ee106f26/msg/EE106LabCustomNew";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ee106f26__msg__EE106LabCustomNew() }
  }
}


