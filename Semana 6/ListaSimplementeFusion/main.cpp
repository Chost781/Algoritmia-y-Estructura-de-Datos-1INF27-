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
        prec=lista.ini;
        for (int j=i;j<n;j++) { //los saltitos
            pant=prec;
            prec=prec->sig;
        }
        prec->sig=pant; //la volteadita
        if (i==1)pini=prec;   //solo pasa una vez en la vida
    }
    lista.ini->sig=nullptr;
    lista.ini=pini;
}
NodoLista* inviertereal(NodoLista *plista) {
    if (plista==nullptr)return nullptr;
    if (plista->sig==nullptr)return plista;
    NodoLista *pini= inviertereal(plista->sig);
    plista->sig->sig=plista;
    return pini;
}

void invierterec(Lista  &lista) {
    NodoLista*pini=inviertereal(lista.ini);
    lista.ini->sig=nullptr;
    lista.ini=pini;
}

void mezclanodos(Lista &l1, Lista l2) {
    NodoLista *ini=nullptr,*fin=nullptr;

    while (not esListaVacia(l1) and
        not esListaVacia(l2)) {
        if (l1.ini->ele.cod<=l2.ini->ele.cod) {
            if (fin==nullptr) {
                ini=l1.ini;
                fin=l1.ini;
            }
            else {
                fin->sig=l1.ini;
                fin=l1.ini;
            }
            l1.ini=l1.ini->sig;
        }
        else {
            if (l1.ini->ele.cod>l2.ini->ele.cod) {
                if (fin==nullptr) {
                    ini=l2.ini;
                    fin=l2.ini;
                }
                else {
                    fin->sig=l2.ini;
                    fin=l2.ini;
                }
                l2.ini=l2.ini->sig;
            }
        }
    }
    if (not esListaVacia(l1)) {
        fin->sig=l1.ini;
        fin=l1.fin;
    }
    if (not esListaVacia(l2)) {
        fin->sig=l2.ini;
        fin=l2.fin;
    }
    l1.ini=ini;
    l1.fin=fin;
}

void fusion(Lista &l1, Lista l2) {
    if (not esListaVacia(l1) and not esListaVacia(l2))
    if (l1.fin->ele.cod<l2.ini->ele.cod) {
        l1.fin->sig=l2.ini;
        l1.fin = l2.fin;
    }
    else {
        if (l2.fin->ele.cod<l1.ini->ele.cod) {
            l2.fin->sig=l1.ini;
            l1.ini=l2.ini;
        }
        else
            mezclanodos(l1,l2);

    }

}


int main(int argc, char **argv) {
    Lista lista1,lista2,lista3;
    ElementoLista ele;
    construir(lista1); // no te olvides
    ele.cod=12;
    insertarAlInicio(lista1,ele);
    ele.cod=8;
    insertarAlInicio(lista1,ele);
    ele.cod=1;
    insertarAlInicio(lista1,ele);

    construir(lista2);
    ele.cod=24;
    insertarAlInicio(lista2,ele);
    ele.cod=15;
    insertarAlInicio(lista2,ele);
    ele.cod=14;
    insertarAlInicio(lista2,ele);
    ele.cod=8;
    insertarAlInicio(lista2,ele);
    ele.cod=2;
    insertarAlInicio(lista2,ele);

    imprimir(lista1);
    imprimir(lista2);

    fusion(lista1,lista2);
    imprimir(lista1);
    construir(lista3);
    fusion(lista1,lista3);

    return 0;
}
