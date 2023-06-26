cmake_minimum_required(VERSION 3.25)
project(Ex__6)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(Ex__6
        administrator.h
        "Ex. 6.cpp"
        "../Ex. 3/date.h"
        "../Ex. 4/person.h"
        "../Ex. 4/person.cpp"
        "../Ex. 5/employee.h"
        "../Ex. 5/employee.cpp"
        employee_manager.cpp
        employee_manager.h
        worker.h)
