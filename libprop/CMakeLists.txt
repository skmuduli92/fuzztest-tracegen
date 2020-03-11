cmake_minimum_required(VERSION 3.10)

project(libprop)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wno-strict-overflow")


# Setting up google test

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

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_library(libprop ${SRC_FILES})

# Finding  googltest framework installed in the system
enable_testing()

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

include_directories(cmake-build-debug/googletest-src/googletest/include)
include_directories(cmake-build-debug/googletest-src/googlemock/include)

# google test setup done

add_executable(testlibprop ${TEST_SRC_FILES})
add_test(NAME testlibprop COMMAND testlibprop)

target_link_libraries(testlibprop libprop gtest pthread)

