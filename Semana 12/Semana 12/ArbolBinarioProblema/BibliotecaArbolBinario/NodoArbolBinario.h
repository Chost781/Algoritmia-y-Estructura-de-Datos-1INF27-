//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal 

#ifndef ARBOLBINARIO_NODOARBOLBINARIO_H
#define ARBOLBINARIO_NODOARBOLBINARIO_H
#include "ElementoArbolBinario.h"
struct NodoAB {
    struct ElementoAB elemento;
    struct NodoAB * izquierda;
    struct NodoAB * derecha;
};
#endif //ARBOLBINARIO_NODOARBOLBINARIO_H