//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
#include  "BibliotecaLista/ElementoLista.h"

using namespace std;

void invierte(Lista  &lista) {
    NodoLista *prec,*pant,*pini;
    int n=lista.longitud;
    for (int i=1;i<n;i++) {
        prec=lista.inicio;
        for (int j=i;j<n;j++) { //los saltitos
            pant=prec;
            prec=prec->siguiente;
        }
        prec->siguiente=pant; //la volteadita
        if (i==1)pini=prec;   //solo pasa una vez en la vida
    }
    lista.inicio->siguiente=nullptr;
    lista.inicio=pini;
}
NodoLista* inviertereal(NodoLista *plista) {
    if (plista==nullptr)return nullptr;
    if (plista->siguiente==nullptr)return plista;
    NodoLista *pini= inviertereal(plista->siguiente);
    plista->siguiente->siguiente=plista;
    return pini;
}

void invierterec(Lista  &lista) {
    NodoLista*pini=inviertereal(lista.inicio);
    lista.inicio->siguiente=nullptr;
    lista.inicio=pini;
}


int main(int argc, char **argv) {
    Lista lista;
    ElementoLista ele;
    construir(lista); // no te olvides
    ele.codigo=12;
    insertarAlFinal(lista,ele);
    ele.codigo=10;
    insertarAlFinal(lista,ele);
    ele.codigo=16;
    insertarAlFinal(lista,ele);
    ele.codigo=14;
    insertarAlFinal(lista,ele);
    ele.codigo=18;
    insertarAlFinal(lista,ele);

    imprimir(lista);
    invierte(lista);
    imprimir(lista);
    invierterec(lista);
    imprimir(lista);

    return 0;
}
