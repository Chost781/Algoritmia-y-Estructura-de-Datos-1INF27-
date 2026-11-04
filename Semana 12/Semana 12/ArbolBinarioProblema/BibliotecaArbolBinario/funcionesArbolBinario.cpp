//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include <iomanip>
#include "funcionesArbolBinario.h"
#include "ArbolBinario.h"
using namespace std;

void construir(struct AB &arbol) {
    arbol.raiz = nullptr;
}

bool esArbolVacio(const struct AB &nodo) {
    return nodo.raiz == nullptr;
}

bool esNodoVacio(const struct NodoAB *nodo) {
    return nodo == nullptr;
}

void plantarArbolBinario(struct AB &arbol, const struct AB &izquierda,
                         const struct ElementoAB &elemento, const struct AB &derecha) {
    plantarNodoArbolBinario(arbol.raiz, izquierda.raiz, elemento, derecha.raiz);
}

void plantarNodoArbolBinario(struct NodoAB *&nodo, struct NodoAB *izquierda,
                             const struct ElementoAB &elemento, struct NodoAB *derecha) {
    struct NodoAB *nuevo = new struct NodoAB;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nodo = nuevo;
}

void imprimirNodo(struct NodoAB *raiz) {
    cout <<raiz->elemento.bin<<"-"<< raiz->elemento.numero<<"  ";
}

void recorrerPreOrden(const struct AB &arbol) {
    recorrerPreOrdenRecursivo(arbol.raiz);
}

void recorrerPreOrdenRecursivo(struct NodoAB *nodo) {
    if (not esNodoVacio(nodo)) {
        imprimirNodo(nodo);
        recorrerPreOrdenRecursivo(nodo->izquierda);
        recorrerPreOrdenRecursivo(nodo->derecha);
    }
}

void recorrerEnOrden(const struct AB &arbol) {
    recorrerEnOrdenRecursivo(arbol.raiz);
}

/*Va mostrar el árbol en orden */
void recorrerEnOrdenRecursivo(struct NodoAB *nodo) {
    if (not esNodoVacio(nodo)) {
        recorrerEnOrdenRecursivo(nodo->izquierda);
        imprimirNodo(nodo);
        recorrerEnOrdenRecursivo(nodo->derecha);
    }
}

void recorrerPostOrden(const struct AB &arbol) {
    recorrerPostOrdenRecursivo(arbol.raiz);
}

void recorrerPostOrdenRecursivo(struct NodoAB *nodo) {
    if (not esNodoVacio(nodo)) {
        recorrerPostOrdenRecursivo(nodo->izquierda);
        recorrerPostOrdenRecursivo(nodo->derecha);
        imprimirNodo(nodo);
    }
}

int numeroHojas(const struct AB &arbol) {
    return numeroHojasRecursivo(arbol.raiz);
}

int numeroHojasRecursivo(struct NodoAB *nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else if (esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 1;
    else
        return numeroHojasRecursivo(nodo->izquierda) + numeroHojasRecursivo(nodo->derecha);
}


int numeroNodos(const struct AB &arbol) {
    return numeroNodosRecursivo(arbol.raiz);
}

int numeroNodosRecursivo(struct NodoAB *nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else
        return 1 + numeroNodosRecursivo(nodo->izquierda) + numeroNodosRecursivo(nodo->derecha);
}

int altura(const struct AB & arbol){
       return alturaRecursivo(arbol.raiz);
}

int alturaRecursivo(struct NodoAB * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if(esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 1;
    else
        return 1 + maximo(alturaRecursivo(nodo->izquierda), alturaRecursivo(nodo->derecha));
}

int maximo(int a, int b){
    return a >= b ? a : b;
}

bool esEquilibrado(const struct AB & arbol){
    return esEquilibradoRecursivo(arbol.raiz);
}

bool esEquilibradoRecursivo(struct NodoAB * nodo){

    if(esNodoVacio(nodo))
        return true;
    else{
        int alturaHijoIzquierdo = alturaRecursivo(nodo->izquierda);
        int alturaHijoDerecho = alturaRecursivo(nodo->derecha);
        int diferencia = abs(alturaHijoIzquierdo - alturaHijoDerecho);
        return diferencia <=1 and esEquilibradoRecursivo(nodo->izquierda) and
                esEquilibradoRecursivo(nodo->derecha);
    }

}

void destruirArbolBinario(struct AB & arbol){
    destruirRecursivo(arbol.raiz);
    arbol.raiz = nullptr;
}

void destruirRecursivo(struct NodoAB * nodo){
    if(not (esNodoVacio(nodo))){
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo;
    }
}