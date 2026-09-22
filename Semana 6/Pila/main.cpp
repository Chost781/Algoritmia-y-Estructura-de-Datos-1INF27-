//Fecha:  lunes 01 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;
/*
 * IMPLEMENTACION DEL TAD PILA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-2
 */
int main(int argc, char ** argv) {
    /*Funciones de Pila*/
    struct Pila pila;
    struct ElementoPila elemento{};
    construir(pila);
    /*Apilamos elementos en la pila*/
    for (int i = 1; i <= 10; i++) {
        elemento.numero = i;
        apilar(pila, elemento);
    }
    elemento = cima(pila);
    cout << "La cima es: " << elemento.numero << endl;
    cout << longitud(pila) << endl;
    imprimir(pila);

    /*Desapilamos elementos en la pila*/
    while (not esPilaVacia(pila)) {
        elemento = desapilar(pila);
        cout << "Desapilando: " << elemento.numero << endl;
    }
    imprimir(pila);
    return 0;
}
