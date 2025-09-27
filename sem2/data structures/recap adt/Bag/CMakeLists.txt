cmake_minimum_required(VERSION 3.30)
project(Bag)

set(CMAKE_CXX_STANDARD 20)

add_executable(Bag main.cpp
        Bag.cpp
        Bag.h
        BagIterator.cpp
        BagIterator.h)
