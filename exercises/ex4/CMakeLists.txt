cmake_minimum_required(VERSION 3.25)
project(ex4)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(ex4 ex4.cpp person.cpp)
