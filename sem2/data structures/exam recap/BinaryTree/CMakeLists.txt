cmake_minimum_required(VERSION 3.30)
project(BinaryTree)

set(CMAKE_CXX_STANDARD 20)

add_executable(BinaryTree main.cpp
        BT.cpp
        BT.h
        Node.cpp
        Node.h)
