#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to ee106f26__msg__EE106LabCustom

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EE106LabCustom {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub int_data: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub float_data: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub string_data: std::string::String,

}



impl Default for EE106LabCustom {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::EE106LabCustom::default())
  }
}

impl rosidl_runtime_rs::Message for EE106LabCustom {
  type RmwMsg = super::msg::rmw::EE106LabCustom;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        int_data: msg.int_data,
        float_data: msg.float_data,
        string_data: msg.string_data.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      int_data: msg.int_data,
      float_data: msg.float_data,
        string_data: msg.string_data.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      int_data: msg.int_data,
      float_data: msg.float_data,
      string_data: msg.string_data.to_string(),
    }
  }
}


