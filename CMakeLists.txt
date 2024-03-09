cmake_minimum_required(VERSION 3.26)
project(Backpack)

set(CMAKE_CXX_STANDARD 23 BUILD_SHARED_LIBS OFF)

add_executable(Backpack main.cpp
        item.c++
        item.h++
        backpack.h++
        backpack.h++
        backpack.cpp)
