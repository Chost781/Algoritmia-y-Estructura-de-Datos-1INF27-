//Fecha:  lunes 01 Setiembre 2025
//Autor: Ana Roncal

#include <iostream>
#include <fstream>
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

/*constructor de Pila*/
void construir(struct Pila & pilaTAD) {
    pilaTAD.inicio = nullptr;
    pilaTAD.longitud = 0;
}

/*Determina si la pila esta vacía*/
bool esPilaVacia(const struct Pila & pilaTAD) {
    return pilaTAD.inicio == nullptr;
}

int longitud(const struct Pila & pilaTAD) {
    return pilaTAD.longitud;
}

struct ElementoPila cima(const struct Pila & pilaTAD) {

    if (esPilaVacia(pilaTAD)) {
        cout << "La pila esta vacia por lo tanto no posee cima" << endl;
        exit(12); // valor de salida que indica que existe un error
    }
    return pilaTAD.inicio->elemento;
}

/* Push, añade un elemento a la parte superior de la pila */
void apilar(struct Pila & pilaTAD, const struct ElementoPila & elemento) {
    struct NodoPila *nuevo;
    nuevo = new NodoPila;
    nuevo->elemento = elemento;
    nuevo->siguiente = pilaTAD.inicio;
    pilaTAD.inicio = nuevo;
    pilaTAD.longitud++;
}

/* Pop, elimina un elemento de la parte superior de la pila*/
struct ElementoPila desapilar(struct Pila & pilaTAD) {
    struct NodoPila * nodoSale;
    struct ElementoPila elemento;
    elemento = pilaTAD.inicio->elemento;
    nodoSale = pilaTAD.inicio;
    pilaTAD.inicio = pilaTAD.inicio->siguiente;
    pilaTAD.longitud--;
    delete nodoSale;
    return elemento;
}

void imprimir(const struct Pila & pilaTAD) {
    if (esPilaVacia(pilaTAD)) {
        cout << "La pila esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoPila * recorrido = pilaTAD.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas después del inicio*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.numero;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}

void destruir(struct Pila & pilaTAD) {
    /*recorrido apunta al inicio del tad*/
    struct NodoPila * recorrido = pilaTAD.inicio;

    while (recorrido != nullptr) {
        /*NodoLista auxiliar que va servir para eliminar los NodoListas*/
        struct NodoPila * NodoListaAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete NodoListaAEliminar;
    }
    /*la lista queda vacia*/
    pilaTAD.inicio = nullptr;
    pilaTAD.longitud = 0;
}
