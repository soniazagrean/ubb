cmake_minimum_required(VERSION 3.30)
project(LabComplexNum)

set(CMAKE_CXX_STANDARD 20)

add_executable(LabComplexNum main.cpp
        ComplexNumber.cpp
        ComplexNumber.h
        Tests.cpp
        Tests.h
)
