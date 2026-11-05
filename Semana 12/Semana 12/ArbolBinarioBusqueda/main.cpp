//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"

using namespace std;
/*
 * IMPLEMENTACION DEL TAD ARBOL BINARIO BUSQUEDA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-2
 */
int main(int argc, char **argv) {

    /* ABB*/
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);

    insertar(arbol, {100});
    insertar(arbol, {50});
    insertar(arbol, {150});
    insertar(arbol, {125});
    insertar(arbol, {175});
    insertar(arbol, {200});
    insertar(arbol, {25});
    insertar(arbol, {75});

    cout << "Recorrer en Orden: " << endl;
    //    25   50   75  100  125  150  175  200
    recorrerEnOrden(arbol); cout<<endl;

    cout << "Recorrer en Pre: " << endl;
    //    100   50   25   75  150  125  175  200
    recorrerPreOrden(arbol);  cout<<endl;

    cout << "Recorrer en Post: " << endl;
    //    25   75   50  125  200  175  150  100
    recorrerPostOrden(arbol); cout<<endl;

    /*Función de busqueda*/
    cout<<"Se encuentra 125 en arbol: "<<buscar(arbol, {125})<<endl;

    eliminar(arbol, {175});
    eliminar(arbol, {25});
    eliminar(arbol, {150});
    eliminar(arbol, {100});

    cout << "Recorrer en Orden despues del borrado: " << endl;
    //     50   75  125  200
    recorrerEnOrden(arbol); cout<<endl;

    destruirArbolBinario(arbol);

    return 0;
}