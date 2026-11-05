//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal 

#ifndef ARBOLBINARIOBUSQUEDA_FUNCIONESARBOLBINARIOBUSQUEDA_H
#define ARBOLBINARIOBUSQUEDA_FUNCIONESARBOLBINARIOBUSQUEDA_H

void construir(struct ArbolBinarioBusqueda &arbol) ;
bool esArbolVacio(const struct ArbolBinarioBusqueda &nodo);
bool esNodoVacio(const struct NodoArbolBinarioBusqueda *nodo);
void plantarArbolBinario(struct ArbolBinarioBusqueda &arbol, const struct ArbolBinarioBusqueda &izquierda,
               const struct ElementoArbolBinarioBusqueda &elemento, const struct ArbolBinarioBusqueda &derecha) ;
void plantarNodoArbolBinario(struct NodoArbolBinarioBusqueda *&nodo, struct NodoArbolBinarioBusqueda *izquierda,
    const struct ElementoArbolBinarioBusqueda &elemento, struct NodoArbolBinarioBusqueda *derecha);

void imprimirNodo(struct NodoArbolBinarioBusqueda *raiz);
void imprimir(const struct ArbolBinarioBusqueda &arbol);

void recorrerPreOrden(const struct ArbolBinarioBusqueda &arbol) ;
void recorrerPreOrdenRecursivo(struct NodoArbolBinarioBusqueda *nodo);
void recorrerEnOrden(const struct ArbolBinarioBusqueda &arbol) ;
void recorrerEnOrdenRecursivo(struct NodoArbolBinarioBusqueda *nodo);
void recorrerPostOrden(const struct ArbolBinarioBusqueda &arbol) ;
void recorrerPostOrdenRecursivo(struct NodoArbolBinarioBusqueda *nodo) ;

int numeroHojas(const struct ArbolBinarioBusqueda &arbol);
int numeroHojasRecursivo(struct NodoArbolBinarioBusqueda *nodo) ;
int numeroNodos(const struct ArbolBinarioBusqueda &arbol);
int numeroNodosRecursivo(struct NodoArbolBinarioBusqueda *nodo) ;
int altura(const struct ArbolBinarioBusqueda & arbol);
int alturaRecursivo(struct NodoArbolBinarioBusqueda * nodo);
int maximo(int a, int b);
bool esEquilibrado(const struct ArbolBinarioBusqueda & arbol);
bool esEquilibradoRecursivo(struct NodoArbolBinarioBusqueda * nodo);
void destruirArbolBinario(struct ArbolBinarioBusqueda & arbol);
void destruirRecursivo(struct NodoArbolBinarioBusqueda * nodo);

void insertar(struct ArbolBinarioBusqueda & arbol, const struct ElementoArbolBinarioBusqueda & elemento);
void insertarRecursivo(struct NodoArbolBinarioBusqueda *& raiz, const struct ElementoArbolBinarioBusqueda & elemento);
bool buscar(const struct ArbolBinarioBusqueda & arbol, const struct ElementoArbolBinarioBusqueda & elemento);
bool buscarRecursivo(struct NodoArbolBinarioBusqueda * nodo, const struct ElementoArbolBinarioBusqueda & elemento);
int comparaElementos(int elementoA, int elementoB);

struct NodoArbolBinarioBusqueda * minimoArbol(struct NodoArbolBinarioBusqueda * nodo);
struct NodoArbolBinarioBusqueda * eliminarRecursivo(struct NodoArbolBinarioBusqueda * nodo, const struct ElementoArbolBinarioBusqueda & elemento);
void eliminar(struct ArbolBinarioBusqueda & arbol, const struct ElementoArbolBinarioBusqueda & elemento);

#endif //ARBOLBINARIOBUSQUEDA_FUNCIONESARBOLBINARIOBUSQUEDA_H