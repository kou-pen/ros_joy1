# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_ctrler_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED ctrler_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(ctrler_FOUND FALSE)
  elseif(NOT ctrler_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(ctrler_FOUND FALSE)
  endif()
  return()
endif()
set(_ctrler_CONFIG_INCLUDED TRUE)

# output package information
if(NOT ctrler_FIND_QUIETLY)
  message(STATUS "Found ctrler: 0.0.0 (${ctrler_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'ctrler' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${ctrler_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(ctrler_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${ctrler_DIR}/${_extra}")
endforeach()
