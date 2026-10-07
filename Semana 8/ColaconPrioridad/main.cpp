//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
#include "funciones.h"
using namespace std;

void ordenarec(Cola& cola,int n) {
    int cont=1;
    if (n==0) return;
    int max=desencolar(cola).codigo;
    while (cont<n) {
        int aux=desencolar(cola).codigo;
        if (aux>max) {
            encolar(cola,{max});
            max=aux;
        }
        else
            encolar(cola,{aux});
        cont++;
    }
    ordenarec(cola,n-1);
    encolar(cola,{max});
}


int main(int argc, char **argv) {
    Cola cola1;
    ElementoCola ele;

    construir(cola1);
    encolar(cola1,{7});
    encolar(cola1,{2});
    encolar(cola1,{1});
    encolar(cola1,{13});
    encolar(cola1,{12});

    imprimir(cola1);
    ordenarec(cola1,longitud(cola1));
    imprimir(cola1);
    return 0;
}
