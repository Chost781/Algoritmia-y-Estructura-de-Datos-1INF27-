cmake_minimum_required(VERSION 4.0)
project(ListaSimplementeEnlazada)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListaSimplementeEnlazada main.cpp
        BibliotecaLista/Lista.h
        BibliotecaLista/funcionesLista.cpp
        BibliotecaLista/funcionesLista.h
        BibliotecaLista/ElementoLista.h
        BibliotecaLista/NodoLista.h)
