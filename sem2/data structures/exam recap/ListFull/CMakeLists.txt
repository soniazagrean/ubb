cmake_minimum_required(VERSION 3.30)
project(ListFull)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListFull main.cpp
        dynamic/ListDynamic.cpp
        dynamic/ListDynamic.h
        sll/ListSLL.cpp
        sll/ListSLL.h
        dynamic/ListDynamicIterator.cpp
        dynamic/ListDynamicIterator.h
        sll/ListSLLIterator.cpp
        sll/ListSLLIterator.h
        Stack.cpp
        Stack.h
        Queue.cpp
        Queue.h
        PriorityQueue.cpp
        PriorityQueue.h
)
