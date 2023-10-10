cmake_minimum_required(VERSION 3.21)
project(proyectoII)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proyectoII

        main.cpp
        README.md
        validaciones.cpp
        validaciones.h)
