cmake_minimum_required(VERSION 3.30)
project(SortedBagBST)

set(CMAKE_CXX_STANDARD 20)

add_executable(SortedBagBST main.cpp
        SortedBag.cpp
        SortedBag.h
        SortedBagIterator.cpp
        SortedBagIterator.h
        ExtendedTest.cpp
        ExtendedTest.h
        Node.cpp
        Node.h)
