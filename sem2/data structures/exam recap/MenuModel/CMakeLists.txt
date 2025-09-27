cmake_minimum_required(VERSION 3.30)
project(MenuModel)

set(CMAKE_CXX_STANDARD 20)

add_executable(MenuModel main.cpp
        Map.cpp
        Map.h)
