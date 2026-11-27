//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include <iomanip>
#include <fstream>
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolBinarioBusqueda.h"

using namespace std;

void insertar(struct ABB & arbol, const struct ElementoABB & elemento) {
    insertarRecursivo(arbol.raiz, elemento);
}
void insertarRecursivo(struct NodoABB *& raiz, const struct ElementoABB & elemento){
    if(esNodoVacio(raiz))
        plantarNodoArbolBinario(raiz, nullptr, elemento, nullptr);
    else
        if(raiz->elemento.numero > elemento.numero)
            insertarRecursivo(raiz->izquierda, elemento);
        else
            if(raiz->elemento.numero < elemento.numero)
                insertarRecursivo(raiz->derecha, elemento);
            else
                cout << "El elemento " << elemento.numero << "Ya se encuentra en el arbol" << endl;
}

int comparaElementos(int elementoA, int elementoB){
    if(elementoA == elementoB) return 0;
    else if(elementoA < elementoB) return -1;
    else if(elementoA > elementoB) return 1;
}

bool buscarRecursivo(struct NodoABB * nodo, const struct ElementoABB & elemento){
    if(esNodoVacio(nodo))
        return false;
    if(comparaElementos(nodo->elemento.numero, elemento.numero) == 0)
        return true;
    if(comparaElementos(nodo->elemento.numero, elemento.numero) == 1)
        return buscarRecursivo(nodo->izquierda, elemento);
    else
        if(comparaElementos(nodo->elemento.numero, elemento.numero) == -1)
            return buscarRecursivo(nodo->derecha, elemento);
}

bool buscar(const struct ABB & arbol, const struct ElementoABB & elemento){
    return buscarRecursivo(arbol.raiz, elemento);
}

struct NodoABB * minimoArbol(struct NodoABB * nodo){
    if(esNodoVacio(nodo))
        return nodo;
    if(esNodoVacio(nodo->izquierda))
        return nodo;
    return minimoArbol(nodo->izquierda);
}

struct NodoABB * eliminarRecursivo(struct NodoABB * nodo,
                                  const struct ElementoABB & elemento){
    if(esNodoVacio(nodo))
        return nodo;
    //buscamos el nodo a eliminar
    if(nodo->elemento.numero > elemento.numero)
        nodo->izquierda = eliminarRecursivo(nodo->izquierda, elemento);
    else
        if(nodo->elemento.numero < elemento.numero)
            nodo->derecha = eliminarRecursivo(nodo->derecha, elemento);
        else
            /*encontrÃ³ el elemento*/
                if(esNodoVacio(nodo->izquierda)){
                    struct NodoABB * hijo = nodo->derecha;
                    delete nodo;
                    return hijo;
                }
                else
                    if(esNodoVacio(nodo->derecha)){
                        struct NodoABB * hijo = nodo->izquierda;
                        delete nodo;
                        return hijo;
                    }
                    else{
                        /* dos hijos*/
                        struct NodoABB * minNodo = minimoArbol(nodo->derecha);
                        nodo->elemento = minNodo->elemento;
                        nodo->derecha = eliminarRecursivo(nodo->derecha, minNodo->elemento);
                    }

    return nodo;

}

void eliminar(struct ABB & arbol, const struct ElementoABB & elemento){
    arbol.raiz = eliminarRecursivo(arbol.raiz, elemento);
}

/*FUNCIONES DE ARBOL BINARIO
 *QUE TAMBIEN USA UN
 *ARBOL BINARIO DE BUSQUEDA*/

void construir(struct ABB &arbol) {
    arbol.raiz = nullptr;
}

bool esArbolVacio(const struct ABB &nodo) {
    return nodo.raiz == nullptr;
}

bool esNodoVacio(const struct NodoABB *nodo) {
    return nodo == nullptr;
}

void plantarArbolBinario(struct ABB &arbol, const struct ABB &izquierda,
               const struct ElementoABB &elemento, const struct ABB &derecha) {

    plantarNodoArbolBinario(arbol.raiz, izquierda.raiz, elemento, derecha.raiz);
}

void plantarNodoArbolBinario(struct NodoABB *&nodo, struct NodoABB *izquierda,
    const struct ElementoABB &elemento, struct NodoABB *derecha) {
    struct NodoABB *nuevo = new struct NodoABB;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nodo = nuevo;
}

void imprimirNodo(struct NodoABB *raiz) {
    cout << setw(5) << raiz->elemento.numero;
}

void recorrerPreOrden(const struct ABB &arbol) {
    recorrerPreOrdenRecursivo(arbol.raiz);
}

void recorrerPreOrdenRecursivo(struct NodoABB *nodo) {
    if (not esNodoVacio(nodo)) {
        imprimirNodo(nodo);
        recorrerPreOrdenRecursivo(nodo->izquierda);
        recorrerPreOrdenRecursivo(nodo->derecha);
    }
}

void recorrerEnOrden(const struct ABB &arbol) {
    recorrerEnOrdenRecursivo(arbol.raiz);
}

/*Va mostrar el Ã¡rbol en orden */
void recorrerEnOrdenRecursivo(struct NodoABB *nodo) {
    if (not esNodoVacio(nodo)) {
        recorrerEnOrdenRecursivo(nodo->izquierda);
        imprimirNodo(nodo);
        recorrerEnOrdenRecursivo(nodo->derecha);
    }
}

void recorrerPostOrden(const struct ABB &arbol) {
    recorrerPostOrdenRecursivo(arbol.raiz);
}

void recorrerPostOrdenRecursivo(struct NodoABB *nodo) {
    if (not esNodoVacio(nodo)) {
        recorrerPostOrdenRecursivo(nodo->izquierda);
        recorrerPostOrdenRecursivo(nodo->derecha);
        imprimirNodo(nodo);
    }
}

int numeroHojas(const struct ABB &arbol) {
    return numeroHojasRecursivo(arbol.raiz);
}

int numeroHojasRecursivo(struct NodoABB *nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else if (esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 1;
    else
        return numeroHojasRecursivo(nodo->izquierda) + numeroHojasRecursivo(nodo->derecha);
}


int numeroNodos(const struct ABB &arbol) {
    return numeroNodosRecursivo(arbol.raiz);
}

int numeroNodosRecursivo(struct NodoABB *nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else
        return 1 + numeroNodosRecursivo(nodo->izquierda) + numeroNodosRecursivo(nodo->derecha);
}

int altura(const struct ABB & arbol){
       return alturaRecursivo(arbol.raiz);
}

int alturaRecursivo(struct NodoABB * nodo){
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

bool esEquilibrado(const struct ABB & arbol){
    return esEquilibradoRecursivo(arbol.raiz);
}

bool esEquilibradoRecursivo(struct NodoABB * nodo){
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

void destruirArbolBinario(struct ABB & arbol){
    destruirRecursivo(arbol.raiz);
    arbol.raiz = nullptr;
}

void destruirRecursivo(struct NodoABB * nodo){
    if(not (esNodoVacio(nodo))){
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo;
    }
}