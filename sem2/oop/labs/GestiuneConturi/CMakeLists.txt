cmake_minimum_required(VERSION 3.30)
project(GestiuneConturi)

set(CMAKE_CXX_STANDARD 20)

add_executable(GestiuneConturi main.cpp
        Repository.cpp
        Repository.h
        Transaction.cpp
        Transaction.h
        Service.cpp
        Service.h
        Tests.cpp
        Tests.h
        UI.cpp
        UI.h)
