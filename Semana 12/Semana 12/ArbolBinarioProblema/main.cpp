//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaArbolBinario/ArbolBinario.h"
#include "BibliotecaArbolBinario/funcionesArbolBinario.h"
using namespace std;

NodoAB* creanodo(ElementoAB valor) {
    NodoAB *nuevo = new struct NodoAB;
    nuevo->derecha = nullptr;
    nuevo->izquierda = nullptr;
    nuevo->elemento = valor;
    return nuevo;
}
void inserta_izq(NodoAB*raiz,ElementoAB valor) {
    NodoAB *nodo=creanodo(valor);
    raiz->izquierda=nodo;
}
void inserta_der(NodoAB*raiz,ElementoAB valor) {
    NodoAB *nodo=creanodo(valor);
    raiz->derecha=nodo;
}

void insertanivel(NodoAB *raiz,int *paq,int n,int ini) {
    if (ini==n) return;
    inserta_izq(raiz,{0,paq[ini]});
    insertanivel(raiz->izquierda,paq,n,ini+1);

    inserta_der(raiz,{1,paq[ini]});
    insertanivel(raiz->derecha,paq,n,ini+1);
}


void creaarbol(AB &arbol, int *paq,int n) {
    plantarNodoArbolBinario(arbol.raiz,nullptr,{0,0},nullptr);
    insertanivel(arbol.raiz,paq,n,0);
}



int main(int argc, char **argv) {
    AB arbol;
    int pesos[]={10,50};
    int n=sizeof(pesos)/sizeof(pesos[0]);
    construir(arbol);
    creaarbol(arbol,pesos,n);
    recorrerPostOrden(arbol);

    return 0;
}
