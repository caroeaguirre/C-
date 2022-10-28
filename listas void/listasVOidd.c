#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include "listasVOidd.h"

struct NodoE {
    void  * dato;
    Nodo prox;
};

struct listaE{
    Nodo primero; //Igual
    Nodo ultimo;  //Opción
    int tam;  //igual
    int tamDelDatoEnBytes; ///NUEVO!!!!!
};


///Constructor del nodo
Nodo crearNodo (Lista lista, void * dato) {

    Nodo aux =  malloc(sizeof (struct NodoE));

    //if (!aux) return -1;

    ///aux->dato = dato

    aux->dato = malloc(lista->tamDelDatoEnBytes);

    if (!aux->dato) {
        free(aux);
        return aux;
    }

   ///Analizar
    memcpy(aux->dato, dato, lista->tamDelDatoEnBytes);

    ///temp->data = data !!!!

    return aux;
}


///Constructor de la lista
Lista crearLista( int tamDelDatoEnBytes) {

    Lista lista = malloc(sizeof(struct listaE));


    //creo la lista en null, entonces el primero y el ultimo apuntan a nada
    lista->primero = lista->ultimo = NULL;
    lista->tam = 0;
    lista->tamDelDatoEnBytes = tamDelDatoEnBytes;

    return lista;
}


//lista vacia
int estaVacia ( Lista lista) {
    if (!lista)
        return 1;
    return (lista->tam == 0);
}



int obtenerTam ( Lista lista) {
    if (!lista)
        return -1;
    return lista->tam;
}

void* obtenerDato (Lista lista, int pos) {
    if (!lista || pos < 0 || lista->tam <= 0 || pos >= lista->tam)
        return NULL;

    if (pos == 0)
        return lista->primero->dato;

    if (pos == lista->tam - 1)
        return lista->ultimo->dato;

    Nodo f = NULL;
    for ( int i = 0; i < pos; i++) {
        if (i == 0)
            f = lista->primero;
        else
            f = f->prox;
    }

    return f->prox->dato;
}

void *obtenerPrimerDato( Lista lista) {
    if (!lista)
        return NULL;
    return lista->primero->dato;
}

void *obtenerUltimoDato( Lista lista) {
    if (!lista)
        return NULL;
    return lista->ultimo->dato;
}


int obtenerDatoEnParametro ( Lista lista, int pos, void *backup) {
    if (!lista || pos < 0 || lista->tam <= 0 || pos >= lista->tam) // lista vazia ou posição nula
        return -1;

    if (pos == 0) {
        memcpy(backup, lista->primero->dato, lista->tamDelDatoEnBytes);
        return 1;
    }

    if (pos == lista->tam - 1) {
        memcpy(backup, lista->primero->dato, lista->tamDelDatoEnBytes);
        return 1;
    }

    Nodo f;
    for (int i = 0; i < pos; i++) {
        if (i == 0)
            f = lista->primero;
        else
            f = f->prox;
    }
    //backup=aux->prox->dato
    memcpy(backup, f->prox->dato, lista->tamDelDatoEnBytes);
    return 1;
}

int insertarInicio (Lista lista, void *dato) {
    Nodo aux;
    if (!(aux = crearNodo(lista, dato)))
        return -1;

    if (lista->tam == 0) {
        lista->primero = lista->ultimo = aux;
        aux->prox = NULL;
        lista->tam++;
        return 1;
    }
    //el priximo del nuevo es el que estaba antes en el primer lugar
    aux->prox = lista->primero;
    lista->primero = aux;
    lista->tam++;

    return 1;
}

int insertarFinal (Lista lista, void *dato) {
    Nodo aux;
    if (!(aux = crearNodo(lista, dato)))
        return -1;

    if (lista->tam == 0) {
        lista->primero = lista->ultimo = aux;
        aux->prox = NULL;
        lista->tam++;
        return 1;
    } else {
        //el siguiente del ultimo nodo ahora apunta al nuevo nodo
        lista->ultimo->prox = aux;
        lista->ultimo = aux;
        lista->ultimo->prox = NULL;
    }

    lista->tam++;
    return 1;
}

int removerInicio (Lista lista, void *backup) {
	if (lista->tam == 0)
		return -1;
    else if (lista->tam == 1) {
        memcpy(backup, lista->primero->dato, lista->tamDelDatoEnBytes);
        liberarlista(lista); // Portanto, apenas limpe a lista!
    } else {
        //un nodo auxiliar que apunte al proximo del primero para no perderlo
        Nodo aux = lista->primero->prox;
        memcpy(backup, lista->primero->dato, lista->tamDelDatoEnBytes);

        free(lista->primero->dato);
        free(lista->primero);
        lista->primero = aux;
        lista->tam--;
    }
    return 1;
}

int removerFinal (Lista lista, void *backup) {
    if (!lista)
        return -1;

    // Si la lista tiene solo un elemento
    if (lista->tam == 1) {
        memcpy(backup, lista->primero->dato, lista->tamDelDatoEnBytes);
        liberarlista(lista);
    }
    // si la lista tiene mas de un elemento
    else {
        Nodo anterior = NULL, ultimo = NULL; //ultimo es un nodo
        memcpy(backup, lista->ultimo->dato, lista->tamDelDatoEnBytes);

        // recorre la lista hasta encontrar el penultimo elemento
        for (anterior = lista->primero; anterior != lista->ultimo; anterior = anterior->prox)
            ultimo = anterior;

        // ultimo ahora apunta hacia el penuntilmo elemento

        free(lista->ultimo->dato); // remueve el dato del ultimo elemento
        free(lista->ultimo); // remuevo el ultimo elemento
        lista->ultimo = ultimo; // ahora el ultimo elemento se torna en 'ultimo'
        lista->ultimo->prox = NULL; // ultimo->prox = null ya que ahora es el fin
        lista->tam--;
    }
    return 1;
}

int insertar (Lista lista, void *dato, int pos) {

    if (!lista || pos < 0 || pos > lista->tam) // lista nula ou posição inválida
        return -1;

    if (pos == 0) // Insere na primeira posição
        return insertarInicio(lista, dato);

    if (pos == lista->tam) // Insere na última posição
        return removerFinal(lista, dato);

    // Insere no meio

    Nodo ant = NULL;
    for ( int i = 0; i < pos; i++) {
        if (i == 0)
            ant = lista->primero;
        else
            ant = ant->prox;
    }
    //en ese momento, ant apunta para la posicion anterior a la que sera insertado el elemento

    Nodo aux;
    if (!(aux = crearNodo(lista, dato)))
        return -1;
//el proximo del nuevo nodo apunta hacia dond apunta el q ahora esta atras de ese.
//el anterior en la pos del prox apunta a el nuevo nodo
    aux->prox = ant->prox;
    ant->prox = aux;
    lista->tam++;
    return 1;
}

int remover(Lista lista, int pos, void *backup) {

    if (!lista || lista->tam<= 0 || pos < 0 || pos >= lista->tam) // lista vazia ou nula ou posição inválida
        return -1;

    // Remove da última posição
    if (pos == lista->tam - 1)
        return removerFinal(lista, backup);

    // O usiário deseja remover um elemento do início
    if (pos == 0)
        return removerInicio(lista, backup);

    // Remover algum elemento no MEIO da lista
    Nodo anterior = NULL, aux;
    for (int i = 0; i < pos; i++) {
        if (i == 0)
            anterior = lista->primero;
        else
            anterior = anterior->prox;
    }
    // anterior apunta hacia el elemento que sera removido

    aux= anterior->prox->prox; // 'aux' apunta para el elemento posterior del que será removido
    memcpy(backup, anterior->prox->dato, lista->tamDelDatoEnBytes);

    free(anterior->prox->dato); // Remove el VALOR del elemento entre 'anterior' y 'aux', que pertence justamente al elemento que el usuário desea remover
    free(anterior->prox); // Remove el ELEMENTO entre 'f' e 'proximoCpy', que é justamente o elemento que o usuário deseja remover
    anterior->prox = aux; // Portanto lique 'f' em 'proximoCpy'
    lista->tam--;
    return 1;
}

void liberarlista (Lista lista) {
    if (!lista || lista->tam <= 0 || lista->primero == NULL)
        return;

    // 'curr' iniciará apontando para o primeiro elemento da lista e proximo para o segundo
    // (que pode ser nulo caso a lista possua apenas um elemento)

    Nodo proximo;
    for ( Nodo p = lista->primero; p != NULL;) {
        proximo = p->prox;
        free(p->dato);
        free(p);
        p = proximo;
    }

    lista->primero = NULL;
    lista->ultimo = NULL;
    lista->tam= 0;

}

int ordenarLista(Lista lista){

    Nodo act;
    Nodo ant;
    ant = lista->primero;
    act= NULL;
    void* tmp;

    while (ant->prox!=NULL){
          act=ant->prox;
        while (act!=NULL){
            if (ant->dato > act->dato){
                memcpy(tmp, ant->dato, lista->tamDelDatoEnBytes);
                //tmp=ant->dato;
                memcpy(ant->dato, act->dato, lista->tamDelDatoEnBytes);
                //ant->dato=act->dato;
                memcpy(act->dato, tmp, lista->tamDelDatoEnBytes);
                //act->dato=tmp;
            }

            act=act->prox;
        }
        ant=ant->prox;
    }
    return 1;
}

int buscarElemento(Lista lista, void* busco){

    Nodo aux = lista->primero;
    int cantElementos = obtenerTam(lista);
    int pos=-1;


    for (int i=0; i<cantElementos;i++){
        if(aux->dato==busco){
            pos=i;
        }
    else{
        aux=aux->prox;
    }
    }
    if (pos!=-1){
    printf("\nel valor que busca esta en la posicion %d de la lista.", pos);
    }
    else {
        printf("\nel valor no se encuentra en la lista");
    }

    return 1;
}


