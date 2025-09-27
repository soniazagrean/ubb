cmake_minimum_required(VERSION 3.30)
project(MoneyCollection)

set(CMAKE_CXX_STANDARD 20)

add_executable(MoneyCollection main.cpp
        Collection.cpp
        Collection.h
        Transaction.cpp
        Transaction.h
        ATM.cpp
        ATM.h)
