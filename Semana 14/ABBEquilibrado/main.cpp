//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
#define N 10
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

void llenaarreglo(struct NodoABB *nodo,int *arr) {
    static int n=0;
    if (not esNodoVacio(nodo)) {
        llenaarreglo(nodo->izquierda,arr);
        arr[n]=nodo->elemento.numero;
        n++;
        llenaarreglo(nodo->derecha,arr);
    }
}

void llenaarbol(ABB &arbol,int *arr,int ini,int fin) {
    if (ini>fin)return;
    if (ini==fin) {
        insertar(arbol,{arr[ini]});
        return;
    }
    int medio=(ini+fin)/2;
    insertar(arbol,{arr[medio]});
    llenaarbol(arbol,arr,ini,medio-1);
    llenaarbol(arbol,arr,medio+1,fin);
}

NodoABB * sumaABBrec(NodoABB* parbola, NodoABB* parbolb) {
    if (parbola==nullptr and parbolb==nullptr)
        return nullptr;
    int suma=0;
    if (parbola!=nullptr)
        suma+=parbola->elemento.numero;
    if (parbolb!=nullptr)
        suma+=parbolb->elemento.numero;
    NodoABB *nuevo;
    plantarNodoArbolBinario(nuevo,nullptr,{suma},nullptr);
    nuevo->izquierda=sumaABBrec((parbola!=nullptr)?parbola->izquierda:nullptr,
        (parbolb!=nullptr)?parbolb->izquierda:nullptr);
    nuevo->derecha=sumaABBrec((parbola!=nullptr)?parbola->derecha:nullptr,
        (parbolb!=nullptr)?parbolb->derecha:nullptr);

    return nuevo;
}

void sumaarboles(ABB arbola,ABB arbolb,ABB &arbolsuma) {
    arbolsuma.raiz=sumaABBrec(arbola.raiz, arbolb.raiz);

}


int main(int argc, char **argv) {
    int arr[N]{};
    ABB arbol,arbolA,arbolB,ArbolSuma;
    construir(arbol);
    construir(arbolA);
    construir(arbolB);
    construir(ArbolSuma);
    insertar(arbol,{2});
    insertar(arbol,{5});
    insertar(arbol,{1});
    insertar(arbol,{3});
    insertar(arbol,{7});
    insertar(arbol,{4});
    insertar(arbol,{6});
    insertar(arbol,{12});
    recorrerPreOrden(arbol);
    llenaarreglo(arbol.raiz,arr);
    int n=numeroNodos(arbol);
    llenaarbol(arbolA,arr,0,n-1);
    cout << endl;
    recorrerPreOrden(arbolA);
    if (esEquilibrado(arbolA))
        cout << endl << "Soy Equilibrado";
    else
        cout<< endl << "No soy Equilibrado ;( pipipi";

    insertar(arbolB,{3});
    insertar(arbolB,{1});
    insertar(arbolB,{5});
    insertar(arbolB,{2});
    insertar(arbolB,{4});
    insertar(arbolB,{6});
    insertar(arbolB,{7});
    cout << endl;
    recorrerPreOrden(arbolB);
    cout << endl;
    sumaarboles(arbolA,arbolB,ArbolSuma);
    recorrerPreOrden(ArbolSuma);

    return 0;
}