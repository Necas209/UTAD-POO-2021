cmake_minimum_required(VERSION 3.25)
project(t2_17_18)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(t2_17_18
        hired_employee.h
        employee.h
        staff.h
        t2_17_18.cpp)
