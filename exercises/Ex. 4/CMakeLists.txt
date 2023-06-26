cmake_minimum_required(VERSION 3.25)
project(Ex__4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Ex__4
        "Ex. 4.cpp"
        person.h
        person.cpp
        "../Ex. 3/date.h")
