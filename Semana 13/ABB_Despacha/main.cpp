//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"

using namespace std;

void despacha(NodoABB *&raiz,int cantidad) {
    if (cantidad==0) return;
    if (raiz==nullptr and cantidad>0)  {
        cout <<"No hay stock para despachar"<<endl;
        cout <<"Faltan "<<cantidad<<endl;
        return;
    }
    NodoABB * izq=minimoArbol(raiz);
    if (cantidad>=izq->elemento.stock) {
        int faltante=cantidad-izq->elemento.stock;
        raiz=eliminarRecursivo(raiz,izq->elemento);
        despacha(raiz,faltante);
    }
    else
        izq->elemento.stock-=cantidad;
}

void despachaTAD(ABB &arbol,int cantidad) {
    if (cantidad==0) return;
    if (esArbolVacio(arbol) and cantidad>0)  {
        cout <<"No hay stock para despachar"<<endl;
        cout <<"Faltan "<<cantidad<<endl;
        return;
    }
    NodoABB * izq=minimoArbol(arbol.raiz);
    if (cantidad>=izq->elemento.stock) {
        int faltante=cantidad-izq->elemento.stock;
        eliminar(arbol,izq->elemento);
        despachaTAD(arbol,faltante);
    }
    else
        izq->elemento.stock-=cantidad;
}

int main(int argc, char **argv) {

    ABB arbol;
    int cant=700;
    construir(arbol);
    insertar(arbol,{20261101,100});
    // insertar(arbol,{20261015,50});
    // insertar(arbol,{20261018,50});
    // insertar(arbol,{20261109,100});
    // insertar(arbol,{20261220,100});
    recorrerEnOrden(arbol);
    cout<<endl;
    despachaTAD(arbol,cant);
    recorrerEnOrden(arbol);

    return 0;
}