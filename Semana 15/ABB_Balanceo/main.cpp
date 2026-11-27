//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <functional>
#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaCola/Cola.h"
#include "BibliotecaPila/Pila.h"

using namespace std;

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

void imprimediagonal(ABB arbol) {
    NodoABB *parbol;
    Cola cola;
    if (esArbolVacio(arbol)) return;
    parbol= arbol.raiz;
    construir(cola);
    encolar(cola,{parbol->elemento.numero});
    while (not esColaVacia(cola)) {
        ElementoCola aux;
        aux=desencolar(cola);
        parbol=busca(arbol,aux.codigo);
        while (parbol) {
            if (parbol->izquierda!=nullptr)
                encolar(cola,{parbol->izquierda->elemento.numero});
            cout << parbol->elemento.numero <<" ";
            parbol=parbol->derecha;
        }
    }
}

NodoABB *sumarec(NodoABB *parbola,NodoABB *parbolb) {
    if (parbola == nullptr and parbolb==nullptr)
        return nullptr;
    int suma=0;
    if (parbola!=nullptr) suma+=parbola->elemento.numero;
    if (parbolb!=nullptr) suma+=parbolb->elemento.numero;
    NodoABB *aux;
    plantarNodoArbolBinario(aux,nullptr,{suma},nullptr);
    aux->izquierda = sumarec((parbola!=nullptr)?parbola->izquierda:nullptr,(parbolb!=nullptr)?parbolb->izquierda:nullptr);
    aux->derecha = sumarec((parbola!=nullptr)?parbola->derecha:nullptr,(parbolb!=nullptr)?parbolb->derecha:nullptr);

    return aux;
}
void sumaabb(ABB arbola,ABB arbolb,ABB &arbolsuma) {
    arbolsuma.raiz=sumarec(arbola.raiz,arbolb.raiz);
}

void insertainorder(struct NodoABB *nodo,int *arr) {
    static int n=0;
    if (not esNodoVacio(nodo)) {
        insertainorder(nodo->izquierda,arr);
        arr[n]=nodo->elemento.numero;
        n++;
        insertainorder(nodo->derecha,arr);
    }
}

void insertaDV(ABB &arbol,int *arr,int ini,int fin) {
    if (ini>fin) return;
    if (ini==fin) {
        insertar(arbol,{arr[ini]});
        return;
    }
    int medio=(ini+fin)/2;
    insertar(arbol,{arr[medio]});
    insertaDV(arbol,arr,ini,medio-1);
    insertaDV(arbol,arr,medio+1,fin);
}

void recorrepreorden(ABB arbol) {
    Pila pila;

    if (esArbolVacio(arbol)) return;
    construir(pila);
    apilar(pila,{arbol.raiz->elemento.numero});
    while (not esPilaVacia(pila)) {
        int valor=desapilar(pila).numero;
        cout << valor <<"    ";
        NodoABB*parbol=busca(arbol,valor);
        if (parbol->derecha!=nullptr)
            apilar(pila,{parbol->derecha->elemento.numero});
        if (parbol->izquierda!=nullptr)
            apilar(pila,{parbol->izquierda->elemento.numero});
    }
}


int main(int argc, char **argv) {
    ABB arbol;
    construir(arbol);
    insertar(arbol,{100});
    insertar(arbol,{50});
    insertar(arbol,{150});
    insertar(arbol,{25});
    insertar(arbol,{75});
    insertar(arbol,{125});
    insertar(arbol,{175});
    insertar(arbol,{40});
    insertar(arbol,{200});
    recorrerPreOrden(arbol);
    cout << endl;
    imprimediagonal(arbol);
/////////////////////////////////////////////////////////////////
    ABB arbola,arbolb,arbolsuma;
    construir(arbola);
    construir(arbolb);
    construir(arbolsuma);
    insertar(arbola,{5});
    insertar(arbola,{2});
    insertar(arbola,{7});
    insertar(arbola,{1});
    insertar(arbola,{3});
    insertar(arbola,{6});
    insertar(arbola,{12});
    insertar(arbola,{4});

    insertar(arbolb,{3});
    insertar(arbolb,{1});
    insertar(arbolb,{5});
    insertar(arbolb,{2});
    insertar(arbolb,{4});
    insertar(arbolb,{6});
    insertar(arbolb,{7});

    sumaabb(arbola,arbolb,arbolsuma);
    cout << endl;
    recorrerPreOrden(arbolsuma);
    ABB arbolc;
    construir(arbolc);
    insertar(arbolc,{2});
    insertar(arbolc,{1});
    insertar(arbolc,{5});
    insertar(arbolc,{3});
    insertar(arbolc,{7});
    insertar(arbolc,{4});
    insertar(arbolc,{6});
    insertar(arbolc,{12});
    cout <<endl<<"Sin balanceo" <<endl;
    recorrerPreOrden(arbolc);

    if (esEquilibrado(arbolc)) cout << endl <<"Soy equilibrado"<<endl;
    else cout << endl <<"No soy equilibrado"<<endl;

    int arr[100]{};
    insertainorder(arbolc.raiz,arr);
    int n=numeroNodos(arbolc);
    ABB arbolbalan;
    construir(arbolbalan);
    insertaDV(arbolbalan,arr,0,n-1);
    cout << endl;
    recorrerPreOrden(arbolbalan);
    if (esEquilibrado(arbolbalan)) cout << endl <<"Soy equilibrado"<<endl;
    else cout << endl <<"No soy equilibrado"<<endl;
    cout <<endl;
    recorrepreorden(arbolbalan);

    return 0;
}