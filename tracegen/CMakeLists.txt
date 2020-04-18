project(ProbModel)

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
add_library(probmodel STATIC probmodel.cpp tracegen.cpp)

target_include_directories(probmodel PUBLIC .)

