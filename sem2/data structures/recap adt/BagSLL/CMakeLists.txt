cmake_minimum_required(VERSION 3.30)
project(BagSLL)

set(CMAKE_CXX_STANDARD 20)

add_executable(BagSLL main.cpp
        Bag.cpp
        Bag.h
        BagIterator.cpp
        BagIterator.h
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        Node.cpp
        Node.h)
