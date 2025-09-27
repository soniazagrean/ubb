cmake_minimum_required(VERSION 3.30)
project(List)

set(CMAKE_CXX_STANDARD 20)

add_executable(List main.cpp
        IteratedList/IteratedList.tpp
        IteratedList/IteratedList.h
        IteratedList/IteratedListIterator.cpp
        IteratedList/IteratedListIterator.h
        IndexedList/IndexedList.cpp
        IndexedList/IndexedList.h
        IndexedList/IndexedListIterator.cpp
        IndexedList/IndexedListIterator.h
        Node.cpp
        Node.h
)
