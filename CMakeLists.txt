cmake_minimum_required(VERSION 3.19.4)

project(hello)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB SRC "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(hello ${SRC})
