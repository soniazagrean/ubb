cmake_minimum_required(VERSION 3.30)
project(SortedSetSLL)

set(CMAKE_CXX_STANDARD 20)

add_executable(SortedSetSLL main.cpp
        SortedSet.cpp
        SortedSet.h
        SortedSetIterator.cpp
        SortedSetIterator.h
        ShortTest.cpp
        ShortTest.h
        ExtendedTest.cpp
        ExtendedTest.h
        Node.cpp
        Node.h)
