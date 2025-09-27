cmake_minimum_required(VERSION 3.30)
project(priority_queue)

set(CMAKE_CXX_STANDARD 20)

add_executable(priority_queue main.cpp
        BinaryHeap.cpp
        BinaryHeap.h)
