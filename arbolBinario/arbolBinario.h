#ifndef ARBOLBINARIO_H_INCLUDED
#define ARBOLBINARIO_H_INCLUDED

struct nodoE;

typedef struct nodoE * nodo;

nodo crearNodo(int dato);

void insertar(nodo nod, int dato);
void preorden(nodo nod);
void inorden(nodo nod);
void postorden(nodo nod);

nodo buscar(nodo nod, int dato);

int calcularAltura(nodo raiz);

#endif // ARBOLBINARIO_H_INCLUDED
