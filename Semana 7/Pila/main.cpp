//Fecha:  lunes 01 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;

void pasapila(Pila &pila1,Pila &pila2) {
    ElementoPila valor,aux;

    while (not esPilaVacia(pila1)) {
        valor=desapilar(pila1);
        int cont=0;
        while (not esPilaVacia(pila1)) {
            apilar(pila2,valor);
            valor=desapilar(pila1);
            cont++;
        }
        while (cont>0 and
            not esPilaVacia(pila2)) {
            aux=desapilar(pila2);
            apilar(pila1,aux);
            cont--;
        }
        apilar(pila2,valor);
    }

}
void submarino(char*ordenes,int n) {
    Pila aux;
    ElementoPila ele;
    construir(aux);
    for (int i=0;i<=n;i++) {
        ele.numero=i+1;
        apilar(aux,ele);
        if (i==n or ordenes[i]=='S') {
            while (not esPilaVacia(aux))
                cout<<desapilar(aux).numero;
        }
    }

}


int main(int argc, char ** argv) {
    char ordenes[]={'B','B','S'};
    int n=sizeof(ordenes)/sizeof(ordenes[0]);
    submarino(ordenes,n);

    /////////////////////////////////////////
    Pila pila1,pila2;
    ElementoPila ele;

    construir(pila1);
    construir(pila2);
    ele.numero=20;
    apilar(pila1,ele);
    ele.numero=15;
    apilar(pila1,ele);
    ele.numero=10;
    apilar(pila1,ele);
    imprimir(pila1);
    pasapila(pila1,pila2);
    imprimir(pila1);
    imprimir(pila2);

    return 0;
}
