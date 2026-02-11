cmake_minimum_required(VERSION 3.30)
project(ModelSubiect)

set(CMAKE_CXX_STANDARD 20)

add_executable(ModelSubiect main.cpp
        MijlocDeTransport.cpp
        MijlocDeTransport.h
        Repository.cpp
        Repository.h
        Service.cpp
        Service.h
        UI.cpp
        UI.h
        Tests.cpp
        Tests.h
)
