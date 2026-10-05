cmake_minimum_required(VERSION 4.0)
project(Pila)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pila main.cpp
        BibliotecaPila/Pila.h
        BibliotecaPila/funcionesPila.cpp
        BibliotecaPila/funcionesPila.h
        BibliotecaPila/NodoPila.h
        BibliotecaPila/ElementoPila.h)
