//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal 

#ifndef ARBOLBINARIOBUSQUEDA_NODOARBOLBINARIOBUSQUEDA_H
#define ARBOLBINARIOBUSQUEDA_NODOARBOLBINARIOBUSQUEDA_H
#include "ElementoArbolBinarioBusqueda.h"
struct NodoArbolBinarioBusqueda {
    struct ElementoArbolBinarioBusqueda elemento;
    struct NodoArbolBinarioBusqueda * izquierda;
    struct NodoArbolBinarioBusqueda * derecha;
};
#endif //ARBOLBINARIOBUSQUEDA_NODOARBOLBINARIOBUSQUEDA_H