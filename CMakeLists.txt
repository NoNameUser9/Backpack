cmake_minimum_required(VERSION 3.26)
project(Backpack)

set(CMAKE_CXX_STANDARD 23 BUILD_SHARED_LIBS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8")

add_executable(Backpack main.c++
        item.c++
        item.h++
        backpack.h++
        backpack.h++
        backpack.c++)
