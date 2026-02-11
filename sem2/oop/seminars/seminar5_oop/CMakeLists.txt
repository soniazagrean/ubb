cmake_minimum_required(VERSION 3.30)
project(seminar5OOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(seminar5OOP main.cpp
        produs.h
        produs_dulce.cpp
        produs_dulce.h
        ProdusSarat.cpp
        ProdusSarat.h
        Tests.cpp
        Tests.h
        repository.cpp
        repository.h
        RepositoryTests.cpp
        RepositoryTests.h
        ProductException.cpp
        ProductException.h
        InvalidDescriptionException.cpp
        InvalidDescriptionException.h
        InvalidPriceException.cpp
        InvalidPriceException.h
        Controller.cpp
        Controller.h
        UI.cpp
        UI.h)
