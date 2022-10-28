#include <stdio.h>
#include <stdlib.h>

#include "listasDato.h"

struct NodoE{

    Dato item;
    No prox;

};

struct ListaEncE{

    int tam;
    No inicio;   //una lista es un puntero al primer nodo.

};

listaEnc crearLista(){

    listaEnc listaNueva = malloc(sizeof(struct ListaEncE));

    listaNueva->tam=0;
    listaNueva->inicio= NULL;

    return listaNueva;
}

Dato crearDato(){

    Dato dato = malloc(sizeof(struct DatoE));

    return dato;
}

No crearNodo(Dato item, No prox){

    No no = malloc(sizeof(struct NodoE));

    no->item=item;
    no->prox=prox;

    return no;
}

int insertarInicio(listaEnc lista, Dato item){
    No noNuevo=crearNodo(item, lista->inicio);

    lista->inicio=noNuevo;
    lista->tam++;

    return 1;

}

int removerInicio(listaEnc lista, Dato * item){

    if(estaVacia(lista)){

        return -1;
    }
    No aux = lista->inicio;

    *item=aux->item;
    free(aux);
    aux=NULL;

    return 1;
    }


int estaVacia(listaEnc lista){

    if(lista->inicio==NULL){

        return 1;}

    return 0;
}

int agregarFinal(listaEnc lista, Dato item){
//hacer que si no hay elementos que diga que la lista no fue inciada
    No aux;
    aux = lista->inicio;

    while (aux->prox!=NULL){
        aux=aux->prox;
    }
    aux->prox=crearNodo(item, NULL);

    lista->tam++;

    return 1;
}

int insertar(listaEnc lista, Dato item, int pos) {

    if (lista == NULL)
        return -1;

    if (pos < 0 || pos > lista->tam){
        return -1;}

    No nuevoNodo;
    if (pos == 0) {
        return insertarInicio(lista, item);
    } else {

        No aux;
        aux = lista->inicio;
        for(int i = 0; i < pos - 1; i++) {
            aux = aux->prox;
        }

        nuevoNodo = crearNodo(item, aux->prox);
        if (nuevoNodo== NULL)
            return -1;
        aux->prox = nuevoNodo;
    }
    lista->tam++;
    return 1;
}

void imprimirLista(listaEnc lista){

    int tamLista;

    getTam(lista,&tamLista);

    printf("{");

    for (int i=0;i<tamLista;i++){

        Dato item;
        getElemento(lista, &item, i);

        mostrarPersona(item->persona);
        //printf(" %d ",item);
    }
    printf("\n}");
}


int eliminarElemento(listaEnc lista, Dato *item, int pos){

    if (pos < 0 || pos >= lista->tam){
        return -1;}

    No auxBorrar;
    No ant;

    if (pos == 0){
        removerInicio(lista,item);
    }else {
    auxBorrar=lista->inicio;
    ant=NULL;
    for (int i=0;i<pos;i++){
        ant=auxBorrar;
        auxBorrar=auxBorrar->prox;
        }
    ant->prox=auxBorrar->prox;
    *item = auxBorrar->item;
    free(auxBorrar);
    auxBorrar=NULL;
    }
    lista->tam--;

    return 1;
}

int getElemento(listaEnc lista, Dato * item, int pos){

    No aux;

    aux=lista->inicio;

    for (int i=0;i<pos;i++){

        aux=aux->prox;
    }
    *item=aux->item;

    return 1;
}

int getTam(listaEnc lista, int * tam){

    *tam=lista->tam;

    return 1;

}

