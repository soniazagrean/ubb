cmake_minimum_required(VERSION 3.30)
project(Set)

set(CMAKE_CXX_STANDARD 20)

add_executable(Set main.cpp
        Set.cpp
        Set.h
        SetIterator.cpp
        SetIterator.h)
