cmake_minimum_required(VERSION 3.25)
project(Ex__5)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(Ex__5
        "Ex. 5.cpp"
        worker.cpp
        worker.h
        "../Ex. 4/person.h"
        "../Ex. 4/person.cpp"
        "../Ex. 3/date.h")
