cmake_minimum_required(VERSION 3.25)
project(ex6)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(ex6
        ex6.cpp
        employee_manager.cpp
        administrator.h
        worker.h
        ../ex5/employee.cpp
        ../ex4/person.cpp)
