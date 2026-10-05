//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
#include "funciones.h"
using namespace std;
/*
 * IMPLEMENTACION DEL TAD COLA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-2
 */
int main(int argc, char **argv) {
    struct Cola cola;
    struct ElementoCola elemento;
    construir(cola);

    cout << "La cola esta vacia: " << esColaVacia(cola) << endl;
    /*Encolamos elementos en la Cola*/
    for (int i = 20; i > 3; i-= 3) {
        elemento.codigo = i;
        encolar(cola, elemento);
    }

    imprimir(cola);
    /*Desencolamos elementos de la cola*/
    // while(not esColaVacia(cola)){
    //     elemento = desencolar(cola);
    //     cout<<"Desencolando: "<<elemento.codigo <<endl;
    // }
    // imprimir(cola);
    int n = longitud(cola);
    ordenarColaIterativo(cola, n);
    imprimir(cola);
    return 0;
}
