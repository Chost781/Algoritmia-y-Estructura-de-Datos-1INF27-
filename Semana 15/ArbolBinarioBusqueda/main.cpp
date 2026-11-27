//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"

using namespace std;

NodoABB * buscaNodo(NodoABB *parbol, ElementoABB ele) {
    if (parbol==nullptr) return nullptr;
    else {
        if (parbol->elemento.numero==ele.numero)
            return parbol;
        else {
                if (parbol->elemento.numero<ele.numero)
                    parbol=parbol->derecha;
                else
                    parbol=parbol->izquierda;
                return(buscaNodo(parbol,ele));
        }
    }
}

void zigzag(ABB arbol) {
    Cola cola;
    if (esArbolVacio(arbol))return;
    construir(cola);
    NodoABB * parbol;
    parbol=arbol.raiz;
    while (parbol!=nullptr) {
        cout<<parbol->elemento.numero<<" ";
        if (parbol->izquierda!=nullptr)
            encolar(cola,{parbol->izquierda->elemento.numero});
        if (parbol->derecha!=nullptr) {
            parbol=parbol->derecha;
        }
        else {
            //cout <<"paso1";
            if (not esColaVacia(cola)){
                ElementoCola aux;
                aux=desencolar(cola);
                parbol=buscaNodo(arbol.raiz,{aux.codigo});
                //cout <<"paso 2";
            }
            else
                parbol=nullptr;
        }
    }
}

void zigzag_inv(ABB arbol) {
    Cola cola;
    Pila pila;
    if (esArbolVacio(arbol))return;
    construir(cola);
    construir(pila);
    NodoABB * parbol;
    parbol=arbol.raiz;
    while (parbol!=nullptr) {
        //cout<<parbol->elemento.numero<<" ";
        apilar(pila,{parbol->elemento.numero});
        if (parbol->izquierda!=nullptr)
            encolar(cola,{parbol->izquierda->elemento.numero});
        if (parbol->derecha!=nullptr) {
            parbol=parbol->derecha;
        }
        else {
            if (not esColaVacia(cola)){
                ElementoCola aux;
                aux=desencolar(cola);
                parbol=buscaNodo(arbol.raiz,{aux.codigo});
            }
            else
                parbol=nullptr;
        }
    }
    while (not esPilaVacia(pila)) {
        ElementoPila aux;
        aux=desapilar(pila);
        cout <<aux.numero <<" ";
    }
}


void amplitud(ABB arbol) {
    Cola cola;
    NodoABB *parbol;

    if (esArbolVacio(arbol)) return;
    construir(cola);
    parbol = arbol.raiz;
    encolar(cola,{parbol->elemento.numero});
    while (not esColaVacia(cola)) {
        ElementoCola aux;
        aux=desencolar(cola);
        cout << aux.codigo<<" ";
        parbol = buscaNodo(arbol.raiz,{aux.codigo});
        if (parbol->izquierda)
            encolar(cola,{parbol->izquierda->elemento.numero});
        if (parbol->derecha)
            encolar(cola,{parbol->derecha->elemento.numero});

    }

}

NodoABB *busca(ABB arbol,int dato) {
    if (esArbolVacio(arbol)) return nullptr;
    else {
        NodoABB *parbol=arbol.raiz;
        while (parbol) {
            if (parbol->elemento.numero == dato) return parbol;
            else {
                if (parbol->elemento.numero<dato)
                    parbol=parbol->derecha;
                else
                    parbol=parbol->izquierda;
            }
        }
        return nullptr;
    }
}

void postordeniterativo(ABB arbol) {
    NodoABB *parbol;
    Pila pila;
    int ultimo=INT_MIN;
    if (esArbolVacio(arbol)) return;
    construir(pila);
    parbol=arbol.raiz;
    while (true) {
        while (parbol) {
            apilar(pila,{parbol->elemento.numero});
            parbol=parbol->izquierda;
        }
        int top=cima(pila).numero;
        parbol=busca(arbol,top);
        if (parbol->derecha and ultimo!=parbol->derecha->elemento.numero) {
            parbol=parbol->derecha;
        }
        else {
            ultimo=desapilar(pila).numero;
            cout << ultimo << "    ";
            parbol=nullptr;
        }
        if (esPilaVacia(pila) ) break;
    }
}

int main(int argc, char **argv) {

    ABB arbol,arboldia;
    construir(arbol);

    insertar(arbol,{15});
    insertar(arbol,{5});
    insertar(arbol,{20});
    insertar(arbol,{10});
    insertar(arbol,{2});
    insertar(arbol,{18});
    amplitud(arbol);

    construir(arboldia);
    insertar(arboldia,{100});
    insertar(arboldia,{50});
    insertar(arboldia,{150});
    insertar(arboldia,{25});
    insertar(arboldia,{75});
    insertar(arboldia,{125});
    insertar(arboldia,{175});
    insertar(arboldia,{40});
    insertar(arboldia,{200});
    cout<<endl;
    zigzag(arboldia);
    cout<<endl;
    zigzag_inv(arboldia);
    cout << endl;
    recorrerPostOrden(arbol);
    cout<<endl;
    postordeniterativo(arbol);
    cout<<endl;

    return 0;
}