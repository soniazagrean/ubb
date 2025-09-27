cmake_minimum_required(VERSION 3.30)
project(QueueFull)

set(CMAKE_CXX_STANDARD 20)

add_executable(QueueFull main.cpp
        stl/QueueStl.cpp
        stl/QueueStl.h
        sll/QueueSLL.cpp
        sll/QueueSLL.h)
