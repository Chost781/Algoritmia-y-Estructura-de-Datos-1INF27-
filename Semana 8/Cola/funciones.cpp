//Fecha:  martes 30 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
#include <fstream>
using namespace std;

void ordenarColaIterativo(struct Cola & cola, int n) {

    struct ElementoCola aux, menor;
    int k = 0;
    for (int i = 1; i <= n; i++) {
        menor = desencolar(cola);
        for (int j = 1; j < n - i + 1; j++) {
            aux = desencolar(cola);

            if (aux.codigo < menor.codigo) {
                encolar(cola, menor);
                menor = aux;
            }else
                encolar(cola, aux);
        }
        for (int m=0; m < k; m++) {
            aux = desencolar(cola);
            encolar(cola, aux);
        }
        k++;
        encolar(cola, menor);
    }
}