cmake_minimum_required(VERSION 4.0)
project(ArbolBinarioBusqueda)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArbolBinarioBusqueda main.cpp
        BibliotecaArbolBinarioBusqueda/ElementoArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/NodoArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h
)
