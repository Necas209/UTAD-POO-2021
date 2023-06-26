cmake_minimum_required(VERSION 3.25)
project(ex5)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(ex5
        ex5.cpp
        employee.cpp
        ../ex4/person.cpp)
