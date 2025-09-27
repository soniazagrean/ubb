cmake_minimum_required(VERSION 3.30)
project(MapBst)

set(CMAKE_CXX_STANDARD 20)

add_executable(MapBst main.cpp
        MapBst.cpp
        MapBst.h
        MapStl.cpp
        MapStl.h)
