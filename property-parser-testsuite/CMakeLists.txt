cmake_minimum_required(VERSION 3.15)
project(PropertyParser)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PropertyParser main.cpp simpleLTLProp.cpp ParserUtils.cpp global_defs.h prob-models/ProbModel.cpp prob-models/ProbModel.h)
