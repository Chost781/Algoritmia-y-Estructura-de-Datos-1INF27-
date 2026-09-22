//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

void construir(struct Lista & listaTAD) {
    listaTAD.ini = nullptr;
    listaTAD.fin = nullptr; //adaptado por RC
    listaTAD.longitud = 0;
}

bool esListaVacia(const struct Lista & listaTAD) {
    return listaTAD.ini == nullptr;
}

/*Inserta los elementos al inicio de la lista*/
void insertarAlInicio(struct Lista & listaTAD, const struct ElementoLista & elemento) {
    struct NodoLista * nuevo;
    nuevo = new struct NodoLista;
    nuevo->ele = elemento;
    nuevo->sig = listaTAD.ini;
    if (esListaVacia(listaTAD)) listaTAD.fin=nuevo; //RC
    listaTAD.ini = nuevo;
    listaTAD.longitud++;
}
//
// /*Inserta un elemento siempre al final de la lista*/
// void insertarAlFinal(struct Lista & listaTAD, const struct ElementoLista & elemento) {
//
//     struct NodoLista * ultimoNodoLista = obtenerUltimoNodo(listaTAD);
//     struct NodoLista * nuevo;
//     nuevo = new struct NodoLista;
//     nuevo->elemento = elemento;
//     nuevo->siguiente = nullptr;
//
//     if (ultimoNodoLista == nullptr) /*Si la lista está vacía*/
//         listaTAD.ini = nuevo; /*se inserta en la cabeza de la lista*/
//     else //La lista ya tiene NodoListas
//         ultimoNodoLista->siguiente = nuevo;
//     listaTAD.longitud++;
// }
//
// /*Obtiene el último NodoLista de la lista*/
// struct NodoLista * obtenerUltimoNodo(const struct Lista & listaTAD) {
//     struct NodoLista * ultimo = nullptr;
//     struct NodoLista* recorrido = listaTAD.ini;
//
//     while (recorrido != nullptr) {
//         ultimo = recorrido;
//         recorrido = recorrido->siguiente;
//     }
//     return ultimo;
// }
//
// void insertarEnOrden(struct Lista & listaTAD, const struct ElementoLista & elemento) {
//
//     struct NodoLista *nuevo, *recorrido = listaTAD.ini, * anterior = nullptr;
//     nuevo = new struct NodoLista;
//     nuevo->elemento = elemento;
//     while(recorrido){
//         if(recorrido->elemento.cod > elemento.cod) break;
//         anterior = recorrido;
//         recorrido = recorrido->siguiente;
//     }
//     nuevo->siguiente = recorrido;
//     if(anterior == nullptr) listaTAD.ini = nuevo;
//     else anterior->siguiente = nuevo;
//     listaTAD.longitud++;
// }

void eliminaNodo(struct Lista & listaTAD, const struct ElementoLista & elemento) {
    struct NodoLista * ultimo = nullptr;
    struct NodoLista * recorrido = listaTAD.ini;
    /*Avanzo hasta encontrar el elemento*/
    /*Si no lo encuentra no elimina nada*/
    while ((recorrido != nullptr) and (recorrido->ele.cod != elemento.cod)) {
        ultimo = recorrido;
        recorrido = recorrido->sig;
    }

    if (recorrido != nullptr) {
        if (ultimo == nullptr) /*Estoy al inicio de la lista*/
            listaTAD.ini = recorrido->sig;
        else
            ultimo->sig = recorrido->sig;
        delete recorrido; /*libera la memoria*/
    }
    listaTAD.longitud--;
}

void destruir(struct Lista & listaTAD) {
    /*recorrido apunta al inicio del tad*/
    struct NodoLista * recorrido = listaTAD.ini;

    while (recorrido != nullptr) {
        /*NodoLista auxiliar que va servir para eliminar los NodoListas*/
        struct NodoLista * NodoListaAEliminar = recorrido;
        recorrido = recorrido->sig;
        delete NodoListaAEliminar;
    }
    /*la lista queda vacia*/
    listaTAD.ini = nullptr;
    listaTAD.longitud = 0;
}

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprimir(const struct Lista & listaTAD) {

    if (esListaVacia(listaTAD)) {
        cout << "La lista esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoLista * recorrido = listaTAD.ini;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despuÃ©s de la cabeza*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->ele.cod;
            recorrido = recorrido->sig;
        }
        cout << "]" << endl;
    }
}