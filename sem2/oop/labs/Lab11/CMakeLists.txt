cmake_minimum_required(VERSION 3.30)
project(Lab11)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab11 main.cpp
        Product.cpp
        Product.h
        Repository.cpp
        Repository.h
        Service.cpp
        Service.h
        UI.cpp
        UI.h
        RepoFile.cpp
        RepoFile.h
        Validator.cpp
        Validator.h
        Tests.cpp
        Tests.h)
