cmake_minimum_required(VERSION 3.10)

project(libprop)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wno-strict-overflow")

if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE Debug CACHE STRING
    "Choose the type of build, options are: None Debug Release RelWithDebInfo
MinSizeRel."
    FORCE )
endif()

string(TOUPPER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE)
message(STATUS "Configuring build type: ${CMAKE_BUILD_TYPE}")

include_directories(include)

file(GLOB SRC_FILES "src/*.cpp")
file(GLOB TEST_SRC_FILES "test/*.cpp")

add_library(libprop ${SRC_FILES})
add_executable(testlibprop ${TEST_SRC_FILES})

# link testlibprop.o with libprop.a file
target_link_libraries(testlibprop libprop)

