cmake_minimum_required(VERSION 3.30)
project(MultimeOrdonataArray)

set(CMAKE_CXX_STANDARD 20)

add_executable(MultimeOrdonataArray main.cpp
        MultimeOrdonata.cpp
        MultimeOrdonata.h
        MultimeOrdonataIterator.cpp
        MultimeOrdonataIterator.h)
