# generated from
# rosidl_cmake/cmake/template/rosidl_cmake_export_typesupport_targets.cmake.in

set(_exported_typesupport_targets
  "__rosidl_typesupport_introspection_c:custom_interfaces_vision__rosidl_typesupport_introspection_c;__rosidl_typesupport_introspection_cpp:custom_interfaces_vision__rosidl_typesupport_introspection_cpp")

# populate custom_interfaces_vision_TARGETS_<suffix>
if(NOT _exported_typesupport_targets STREQUAL "")
  # loop over typesupport targets
  foreach(_tuple ${_exported_typesupport_targets})
    string(REPLACE ":" ";" _tuple "${_tuple}")
    list(GET _tuple 0 _suffix)
    list(GET _tuple 1 _target)

    set(_target "custom_interfaces_vision::${_target}")
    if(NOT TARGET "${_target}")
      # the exported target must exist
      message(WARNING "Package 'custom_interfaces_vision' exports the typesupport target '${_target}' which doesn't exist")
    else()
      list(APPEND custom_interfaces_vision_TARGETS${_suffix} "${_target}")
    endif()
  endforeach()
endif()
