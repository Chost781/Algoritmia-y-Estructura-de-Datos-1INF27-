//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal 

#ifndef ARBOLBINARIOBUSQUEDA_NODOARBOLBINARIOBUSQUEDA_H
#define ARBOLBINARIOBUSQUEDA_NODOARBOLBINARIOBUSQUEDA_H
#include "ElementoArbolBinarioBusqueda.h"
struct NodoABB {
    struct ElementoABB elemento;
    struct NodoABB * izquierda;
    struct NodoABB * derecha;
};
#endif //ARBOLBINARIOBUSQUEDA_NODOARBOLBINARIOBUSQUEDA_H