//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal 

#ifndef LISTASIMPLEMENTEENLAZADA_FUNCIONESLISTA_H
#define LISTASIMPLEMENTEENLAZADA_FUNCIONESLISTA_H

void construir(struct Lista & listaTAD);
bool esListaVacia(const struct Lista & listaTAD);
void insertarAlInicio(struct Lista & listaTAD, const struct ElementoLista & elemento);
void insertarAlFinal(struct Lista & listaTAD, const struct ElementoLista & elemento);
struct NodoLista * obtenerUltimoNodo(const struct Lista & listaTAD);
void insertarEnOrden(struct Lista & listaTAD, const struct ElementoLista & elemento);
struct NodoLista * obtenerNodoAnterior(const struct Lista & lista, const struct ElementoLista & elemento);
void eliminaNodo(struct Lista & listaTAD, const struct ElementoLista & elemento);
void destruir(struct Lista & listaTAD) ;
void imprimir(const struct Lista & listaTAD);

#endif //LISTASIMPLEMENTEENLAZADA_FUNCIONESLISTA_H