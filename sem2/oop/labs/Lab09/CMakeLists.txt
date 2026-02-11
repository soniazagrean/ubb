cmake_minimum_required(VERSION 3.30)
project(Lab09)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab09 main.cpp
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
)
