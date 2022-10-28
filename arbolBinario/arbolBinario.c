#include <stdio.h>
#include <stdlib.h>

#include "arbolBinario.h"

struct nodoE{

    int dato;
    nodo izquierdo;
    nodo derecho;
};

nodo crearNodo(int dato){

    nodo nuevoNodo = malloc(sizeof(struct nodoE));

    nuevoNodo->dato=dato;
    nuevoNodo->derecho = NULL;
    nuevoNodo->izquierdo = NULL;
    return nuevoNodo;

}

void insertar(nodo nod, int dato){

   if (dato>nod->dato){
        if (nod->derecho==NULL){
            nod->derecho = crearNodo(dato);
        }
   else {
        insertar(nod->derecho, dato);
   }
   }else {
    if (nod->izquierdo==NULL){
        nod->izquierdo=crearNodo(dato);
    }
   else{
        insertar(nod->izquierdo, dato);
        }
   }
}
void preorden(nodo nod){

    if (nod!=NULL){
        printf(" %d ",nod->dato);
        preorden(nod->izquierdo);
        preorden(nod->derecho);
    }
}
void inorden(nodo nod){
    if (nod!=NULL){
        inorden(nod->izquierdo);
        printf(" %d ", nod->dato);
        inorden(nod->derecho);
    }
}
void postorden(nodo nod){
    if (nod!=NULL){
        postorden(nod->izquierdo);
        postorden(nod->derecho);
        printf(" %d ", nod->dato);
    }
}

nodo buscar(nodo nod, int dato){

    if (nod ==NULL){
        return NULL;
    }

    if (nod->dato == dato){
        return nod;
    }

    else if (dato > nod->dato){
        printf("no esta el %d != %d --> DERECHA ", dato, nod->dato);
        return buscar(nod->derecho, dato);
    }else {
        printf("no esta el %d != %d --> IZQUIERDA ", dato, nod->dato);
        return buscar(nod->izquierdo, dato);
    }
}

int calcularAltura(nodo raiz){

    int altDer=0;
    int altIzq=0;
    if (raiz==NULL){
        return NULL;
    }
    altDer=calcularAltura(raiz->derecho);
    altIzq=calcularAltura(raiz->izquierdo);

    if(altDer>altIzq){
        return altDer+1;
    }
    else{
        return altIzq+1;
    }
}
