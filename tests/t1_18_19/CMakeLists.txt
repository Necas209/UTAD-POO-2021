cmake_minimum_required(VERSION 3.25)
project(t1_18_19)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(t1_18_19
        bank_account.h
        holder.h
        date.h
        t1_18_19.cpp)
