//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal 

#ifndef ARBOLBINARIO_FUNCIONESARBOLBINARIO_H
#define ARBOLBINARIO_FUNCIONESARBOLBINARIO_H

void construir(struct AB &arbol);
bool esArbolVacio(const struct AB &nodo);
bool esNodoVacio(const struct NodoAB *nodo);
void plantarArbolBinario(struct AB &arbol, const struct AB &izquierda,
                         const struct ElementoAB &elemento, const struct AB &derecha);
void plantarNodoArbolBinario(struct NodoAB *&nodo, struct NodoAB *izquierda,
                             const struct ElementoAB &elemento, struct NodoAB *derecha);

void imprimirNodo(struct NodoArbol *raiz);
void imprimir(const struct AB &arbol);

void recorrerPreOrden(const struct AB &arbol);
void recorrerPreOrdenRecursivo(struct NodoAB *nodo);
void recorrerEnOrden(const struct AB &arbol);
void recorrerEnOrdenRecursivo(struct NodoAB *nodo);
void recorrerPostOrden(const struct AB &arbol);
void recorrerPostOrdenRecursivo(struct NodoAB *nodo);

int numeroHojas(const struct AB &arbol);
int numeroHojasRecursivo(struct NodoAB *nodo);
int numeroNodos(const struct AB &arbol);
int numeroNodosRecursivo(struct NodoAB *nodo);
int altura(const struct AB & arbol);
int alturaRecursivo(struct NodoAB * nodo);
int maximo(int a, int b);
bool esEquilibrado(const struct AB & arbol);
bool esEquilibradoRecursivo(struct NodoAB * nodo);
void destruirArbolBinario(struct AB & arbol);
void destruirRecursivo(struct NodoAB * nodo);
#endif //ARBOLBINARIO_FUNCIONESARBOLBINARIO_H
