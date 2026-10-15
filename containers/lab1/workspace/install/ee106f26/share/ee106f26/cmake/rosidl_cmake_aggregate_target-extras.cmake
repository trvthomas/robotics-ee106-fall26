# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target ee106f26::ee106f26
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${ee106f26_TARGETS}.
if(ee106f26_TARGETS AND NOT TARGET ee106f26::ee106f26)
  add_library(ee106f26::ee106f26 INTERFACE IMPORTED)
  set_target_properties(ee106f26::ee106f26 PROPERTIES
    INTERFACE_LINK_LIBRARIES "${ee106f26_TARGETS}")
endif()
