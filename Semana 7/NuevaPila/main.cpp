//Fecha:  lunes 01 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/NuevaPila.h"
using namespace std;

void nuevoconstruir(NuevaPila &pila) {
    construir(pila.principal);
    construir(pila.extra);
}

void nuevoapilar(NuevaPila &npila,ElementoPila ele) {
    apilar(npila.principal,ele);
    if (esPilaVacia(npila.extra))apilar(npila.extra,ele);
    else {
        if (ele.numero<cima(npila.extra).numero)
            apilar(npila.extra,ele);
        else
            apilar(npila.extra,cima(npila.extra));
    }
}
ElementoPila nuevodesapilar(NuevaPila &npila) {
    desapilar(npila.extra);
    return desapilar(npila.principal);
}
 ElementoPila minimo(NuevaPila &npila) {
    desapilar(npila.principal);
    return desapilar(npila.extra);
}

void nuevoimprimir(NuevaPila pila) {
    cout << "Principal:";
    imprimir(pila.principal);
    cout <<"Extra:";
    imprimir(pila.extra);
}

int main(int argc, char ** argv) {
    NuevaPila pila;
    ElementoPila ele;

    nuevoconstruir(pila);
    ele.numero=202411;
    nuevoapilar(pila,ele);
    ele.numero=202502;
    nuevoapilar(pila,ele);
    ele.numero=202410;
    nuevoapilar(pila,ele);
    ele.numero=202509;
    nuevoapilar(pila,ele);
    nuevoimprimir(pila);

    cout<<minimo(pila).numero<<endl;

    return 0;
}
