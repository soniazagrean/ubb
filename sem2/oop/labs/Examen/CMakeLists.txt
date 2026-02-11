cmake_minimum_required(VERSION 3.30)
project(Examen)

set(CMAKE_CXX_STANDARD 20)

add_executable(Examen main.cpp
        Program.h
        Repository.h
        Validator.h
        Service.h
        UI.h
        Tests.cpp
        Tests.h
)
