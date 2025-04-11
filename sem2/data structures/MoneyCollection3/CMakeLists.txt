cmake_minimum_required(VERSION 3.30)
project(Lab03)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab03 main.cpp
        Collection.tpp
        Collection.h
        ATM.cpp
        ATM.h
        Transaction.cpp
        Transaction.h
        Set.tpp
        Set.h)
