cmake_minimum_required(VERSION 3.30)
project(SetSLL)

set(CMAKE_CXX_STANDARD 20)

add_executable(SetSLL main.cpp
        Set.cpp
        Set.h
        SetIterator.cpp
        SetIterator.h
        ShortTest.cpp
        ShortTest.h
        ExtendedTest.cpp
        ExtendedTest.h
        Node.cpp
        Node.h)
