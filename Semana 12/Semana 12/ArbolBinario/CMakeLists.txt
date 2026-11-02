cmake_minimum_required(VERSION 4.0)
project(ArbolBinario)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArbolBinario main.cpp
        BibliotecaArbolBinario/ElementoArbolBinario.h
        BibliotecaArbolBinario/ArbolBinario.h
        BibliotecaArbolBinario/NodoArbolBinario.h
        BibliotecaArbolBinario/funcionesArbolBinario.cpp
        BibliotecaArbolBinario/funcionesArbolBinario.h)
