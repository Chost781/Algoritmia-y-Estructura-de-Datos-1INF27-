//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "Cola.h"
#include "funcionesCola.h"
using namespace std;

void construir(struct Cola & colaTAD){
    colaTAD.ini = nullptr;
    colaTAD.pri = nullptr;
    colaTAD.fin = nullptr;
    colaTAD.longitud = 0;
}

/*devuelve la longitud de la cola*/
int longitud(const struct Cola & colaTAD) {
    return colaTAD.longitud;
}
// para no malograr desarrollaremos uno encolar con priori



void encolar(struct Cola &colaTAD, const struct ElementoCola & elemento){
    struct NodoCola *nuevo;
    nuevo = new NodoCola{};
    nuevo->elemento = elemento;
    if(esColaVacia(colaTAD)){
        colaTAD.ini = nuevo;
        colaTAD.fin = nuevo;
    }
    else {
        colaTAD.fin->siguiente = nuevo;
        colaTAD.fin = nuevo;
    }
    colaTAD.longitud++;
}

void encolarprio(struct Cola &colaTAD, const struct ElementoCola & elemento){
    struct NodoCola *nuevo;
    nuevo = new NodoCola{};
    nuevo->elemento = elemento;

    if(esColaVacia(colaTAD)){
        colaTAD.ini = nuevo;
        colaTAD.fin = nuevo;
        if (nuevo->elemento.priori==1)
            colaTAD.pri = nuevo;
    }
    else {
        if (nuevo->elemento.priori==1) {
            if (colaTAD.pri==nullptr) {
                nuevo->siguiente=colaTAD.ini;
                colaTAD.ini=nuevo;
            }
            else {
                nuevo->siguiente=colaTAD.pri->siguiente;
                colaTAD.pri->siguiente=nuevo;
                if (colaTAD.pri==colaTAD.fin)
                    colaTAD.fin=nuevo;
            }
            colaTAD.pri = nuevo;
        }
        else {
            colaTAD.fin->siguiente=nuevo;
            colaTAD.fin = nuevo;
        }
    }
    colaTAD.longitud++;
}


// se realizara una pequeña adaptacion
struct ElementoCola desencolar(struct Cola & colaTAD){
    struct NodoCola * pSale;
    struct ElementoCola elemento;
    pSale = colaTAD.ini;
    colaTAD.ini = colaTAD.ini->siguiente;
    elemento = pSale->elemento;
    colaTAD.longitud--;
    delete pSale;
    return elemento;
}

bool esColaVacia(const struct Cola & colaTAD){
    return colaTAD.ini == nullptr;
}

void imprimir(const struct Cola & colaTAD) {
    if (esColaVacia(colaTAD)) {
        cout << "La cola esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoCola * recorrido = colaTAD.ini;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despues del inicio*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout <<recorrido->elemento.priori <<"-"<< recorrido->elemento.codigo;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}