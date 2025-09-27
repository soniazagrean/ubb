cmake_minimum_required(VERSION 3.30)
project(HeapBST)

set(CMAKE_CXX_STANDARD 20)

add_executable(HeapBST main.cpp
        PriorityQueue.cpp
        PriorityQueue.h
        BT.cpp
        BT.h
        BST.cpp
        BST.h)
