cmake_minimum_required(VERSION 3.30)
project(StackFull)

set(CMAKE_CXX_STANDARD 20)

add_executable(StackFull main.cpp
        vectorSTL/StackStl.tpp
        vectorSTL/StackStl.h
        SLL/StackSLL.tpp
        SLL/StackSLL.h
        dynamic/StackDynamic.tpp
        dynamic/StackDynamic.h
)
