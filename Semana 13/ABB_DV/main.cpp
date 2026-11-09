//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"

using namespace std;

void insertadv(NodoABB *&raiz, int *arr,int ini,int fin) {
    if (ini>fin)return;
    int med=(ini+fin)/2;
    insertarRecursivo(raiz,{arr[med]});
    insertadv(raiz,arr,ini,med-1);
    insertadv(raiz,arr,med+1,fin);
}

void insertaarreglodv(ABB &arbol, int arr[], int n) {
    insertadv(arbol.raiz,arr,0,n-1);
}

int main(int argc, char **argv) {

    ABB arbol;
    int arr[]={2,4,6,8,10,12,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    construir(arbol);
    insertaarreglodv(arbol, arr, n);
    recorrerEnOrden(arbol);


    return 0;
}