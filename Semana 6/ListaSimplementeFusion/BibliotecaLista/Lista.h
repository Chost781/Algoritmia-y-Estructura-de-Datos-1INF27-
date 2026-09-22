//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal 

#ifndef LISTASIMPLEMENTEENLAZADA_LISTA_H
#define LISTASIMPLEMENTEENLAZADA_LISTA_H
#include "NodoLista.h"
struct Lista {
    struct NodoLista * ini;
    struct NodoLista * fin;
    int longitud;
};
#endif //LISTASIMPLEMENTEENLAZADA_LISTA_H