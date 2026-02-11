cmake_minimum_required(VERSION 3.30)
project(lab06)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab06 main.cpp
        ComplexNumber.cpp
        ComplexNumber.h
        Operations.cpp
        Operations.h
        Tests.cpp
        Tests.h)
