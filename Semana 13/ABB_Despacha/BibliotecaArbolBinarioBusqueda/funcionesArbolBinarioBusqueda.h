//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal 

#ifndef ARBOLBINARIOBUSQUEDA_FUNCIONESARBOLBINARIOBUSQUEDA_H
#define ARBOLBINARIOBUSQUEDA_FUNCIONESARBOLBINARIOBUSQUEDA_H

void construir(struct ABB &arbol) ;
bool esArbolVacio(const struct ABB &nodo);
bool esNodoVacio(const struct NodoABB *nodo);
void plantarArbolBinario(struct ABB &arbol, const struct ABB &izquierda,
               const struct ElementoABB &elemento, const struct ABB &derecha) ;
void plantarNodoArbolBinario(struct NodoABB *&nodo, struct NodoABB *izquierda,
    const struct ElementoABB &elemento, struct NodoABB *derecha);

void imprimirNodo(struct NodoABB *raiz);
void imprimir(const struct ABB &arbol);

void recorrerPreOrden(const struct ABB &arbol) ;
void recorrerPreOrdenRecursivo(struct NodoABB *nodo);
void recorrerEnOrden(const struct ABB &arbol) ;
void recorrerEnOrdenRecursivo(struct NodoABB *nodo);
void recorrerPostOrden(const struct ABB &arbol) ;
void recorrerPostOrdenRecursivo(struct NodoABB *nodo) ;

int numeroHojas(const struct ABB &arbol);
int numeroHojasRecursivo(struct NodoABB *nodo) ;
int numeroNodos(const struct ABB &arbol);
int numeroNodosRecursivo(struct NodoABB *nodo) ;
int altura(const struct ABB & arbol);
int alturaRecursivo(struct NodoABB * nodo);
int maximo(int a, int b);
bool esEquilibrado(const struct ABB & arbol);
bool esEquilibradoRecursivo(struct NodoABB * nodo);
void destruirArbolBinario(struct ABB & arbol);
void destruirRecursivo(struct NodoABB * nodo);

void insertar(struct ABB & arbol, const struct ElementoABB & elemento);
void insertarRecursivo(struct NodoABB *& raiz, const struct ElementoABB & elemento);
bool buscar(const struct ABB & arbol, const struct ElementoABB & elemento);
bool buscarRecursivo(struct NodoABB * nodo, const struct ElementoABB & elemento);
int comparaElementos(int elementoA, int elementoB);

struct NodoABB * minimoArbol(struct NodoABB * nodo);
struct NodoABB * eliminarRecursivo(struct NodoABB * nodo, const struct ElementoABB & elemento);
void eliminar(struct ABB & arbol, const struct ElementoABB & elemento);
struct NodoABB * eliminarRecursivo(struct NodoABB * nodo,
                                  const struct ElementoABB & elemento);
#endif //ARBOLBINARIOBUSQUEDA_FUNCIONESARBOLBINARIOBUSQUEDA_H