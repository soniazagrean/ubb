cmake_minimum_required(VERSION 3.30)
project(seminar2_oop)

set(CMAKE_CXX_STANDARD 20)

add_executable(seminar2_oop main.cpp
        Student.cpp
        Student.h
        tests.cpp
        tests.h
        operations.cpp
        operations.h
        Repository.cpp
        Repository.h
        Service.cpp
        Service.h
        UI.cpp
        UI.h)
