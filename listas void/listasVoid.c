#include <stdio.h>
#include <stdlib.h>
#include"string.h"
#include"listasVoid.h"

struct NodoE {
    void * dato;
    Nodo prox;

};

struct listaE{

    Nodo inicio;
    int tam;
    int tamDelDato;

};

///constructor del nodo
Nodo crearNodo(Lista lista, void * dato){

    Nodo aux = malloc(sizeof(struct NodoE));

    aux->dato= malloc(lista->tamDelDato);
    //reservo memoria para el dato, ya que no se con q dato estoy trabajando

    if (!aux->dato){

        free(aux);

        return aux;
    }

    memcpy(aux->dato, dato, lista->tamDelDato);
    //aux->dato=dato;
    //guarda la info del seg parametro en el primero, guarla la info que ocupa esta cant de bytes.
    return aux;
}

Lista crearLista(int tamDelDato){

    Lista lista = malloc(sizeof(struct listaE));

    lista->inicio=NULL;
    lista->tam=0;
    lista->tamDelDato=tamDelDato;

    return lista;

}

int estaVacia(Lista lista){

     if (lista->inicio=NULL){
        return 1;
        }

     return lista->tam=0;

}

int obtenerTam(Lista lista){

    if (!lista)
        return -1;

    return lista->tam;
}

void* obtenerDato(Lista lista, int pos){

    if (pos ==0){
        return lista->inicio->dato;
    }

    Nodo aux = NULL;

    for (int i =0;i<pos;i++){
        if (i==0){
            aux=lista->inicio;
        }
        else {
            aux=aux->prox;
        }
    }
    return aux->prox->dato;
}

void * obtenerPrimerDato(Lista lista){

    if (!lista)
        return NULL;

    return lista->inicio->dato;
}

void* obtenerUltimoDato(Lista lista){

    int tam = obtenerTam(lista);

    return obtenerDato(lista, tam);
}

int obtenerDatoEnParametro(Lista lista, int pos, void*datoBackUp){

   // if (!lista || pos =0| lista->tam <=0 || pos == lista->tam)
      //  return -1

    Nodo aux;

    for (int i =0;i<pos;i++){

        if (i==0){
            aux= lista->inicio;
        }
        else {
        aux=aux->prox;
    }
    }
    //podria ir hasta la pos y de ahi hacer directamente aux->dato
    memcpy(datoBackUp, aux->prox->dato, lista->tamDelDato);
    return 1;
}

int insertarInicio(Lista lista, void*dato){

    Nodo aux;

    if (lista->tam==0){
        lista->inicio=aux;
        aux->prox=NULL;
        lista->tam++;
    }

    aux->prox=lista->inicio;
    lista->inicio = aux;
    lista->tam++;

    return 1;
}
int insertar(Lista lista, void*dato, int pos){


    if (!lista || pos < 0 || pos > lista->tam) // lista nula ou posição inválida
        return -1;

    if (pos == 0) // Insere na primeira posição
        return insertarInicio(lista, dato);

    // Insere no meio

    Nodo f = NULL;
    for ( int i = 0; i < pos; i++) {
        if (i == 0)
            f = lista->inicio;
        else
            f = f->prox;
    }
    // Nesse momento 'f' aponta para a posição anterior à que será inserido o elemento

    Nodo temp;
    if (!(temp = crearNodo(lista, dato)))
        return -1;

    temp->prox = f->prox;
    f->prox = temp;
    lista->tam++;
    return 1;
}
int insertarFinal(Lista lista, void*dato){

    Nodo aux;

    if (lista->tam == 0) {
        lista->inicio = aux;
        aux->prox = NULL;
        lista->tam++;
        return 1;
    } else {
        while (aux->prox!=NULL){
            aux=aux->prox;

        }
        aux->prox->dato=aux;
        aux->prox->prox=NULL;

        lista->tam++;

        return 1;
    }

    lista->tam++;

    return 1;

}

int removerInicio(Lista lista, void*backup){

    if(estaVacia(lista)){

        return -1;
    }
    Nodo aux = lista->inicio->prox;

    memcpy(backup, lista->inicio->dato, lista->tamDelDato);

    free(lista->inicio->dato);
    free(lista->inicio);
    lista->inicio=aux;
    lista->tam--;

    return 1;
}

int remover(Lista lista, void*backup, int pos){

    Nodo aux = lista->inicio;
    Nodo ant;

    if (pos==0){

        removerInicio(lista, backup);
    }
    else {
        for (int i=0;i<pos; i++){
            ant = aux;
            aux=aux->prox;
            }

        ant->prox=aux->prox;
        memcpy(backup, aux->prox->dato, lista->tamDelDato);

        free(aux->prox->dato);
        free(aux->prox);
        aux->prox=ant;
    }
    lista->tam--;

    return 1;
}


