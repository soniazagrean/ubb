cmake_minimum_required(VERSION 3.30)
project(SortedBagSLL)

set(CMAKE_CXX_STANDARD 20)

add_executable(SortedBagSLL main.cpp
        SortedBag.cpp
        SortedBag.h
        SortedBagIterator.cpp
        SortedBagIterator.h
        ShortTest.cpp
        ShortTest.h
        ExtendedTest.cpp
        ExtendedTest.h
        Node.cpp
        Node.h)
