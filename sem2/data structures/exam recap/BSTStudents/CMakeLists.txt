cmake_minimum_required(VERSION 3.30)
project(BSTStudents)

set(CMAKE_CXX_STANDARD 20)

add_executable(BSTStudents main.cpp
        BT.cpp
        BT.h
        BST.cpp
        BST.h
        Student.h)
