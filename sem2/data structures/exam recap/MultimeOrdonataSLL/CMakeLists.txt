cmake_minimum_required(VERSION 3.30)
project(MultimeOrdonataSLL)

set(CMAKE_CXX_STANDARD 20)

add_executable(MultimeOrdonataSLL main.cpp
        MultimeOrdonata.cpp
        MultimeOrdonata.h
        MultimeOrdonataIterator.cpp
        MultimeOrdonataIterator.h
        Node.cpp
        Node.h)
