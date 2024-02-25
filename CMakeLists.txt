cmake_minimum_required(VERSION 3.26)
project(Backpack)

set(CMAKE_CXX_STANDARD 23)

add_executable(Backpack main.cpp
        Item.c++
        Item.h++
        backpack.c++
        backpack.h++
        backpack.h++)
