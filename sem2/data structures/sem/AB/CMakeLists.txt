cmake_minimum_required(VERSION 3.30)
project(AB)

set(CMAKE_CXX_STANDARD 20)

add_executable(AB main.cpp
        AB.tpp
        AB.h
        Masina.cpp
        Masina.h
)
