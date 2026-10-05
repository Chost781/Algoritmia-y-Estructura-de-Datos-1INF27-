cmake_minimum_required(VERSION 4.0)
project(Cola)

set(CMAKE_CXX_STANDARD 20)

add_executable(Cola main.cpp
        BibliotecaCola/funcionesCola.cpp
        BibliotecaCola/funcionesCola.h
        BibliotecaCola/NodoCola.h
        BibliotecaCola/Cola.h
        BibliotecaCola/ElementoCola.h
        funciones.cpp
        funciones.h
)
