cmake_minimum_required(VERSION 3.30)
project(SortedBag)

set(CMAKE_CXX_STANDARD 20)

add_executable(SortedBag main.cpp
        SortedBag.cpp
        SortedBag.h
        SortedBagIterator.cpp
        SortedBagIterator.h)
