#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct NodoE{

    int item;
    No prox; // "no" ya es un puntero.

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

No crearNodo(int item, No prox){

    No no = malloc(sizeof(struct NodoE));

    no->item=item;
    no->prox=prox;

    return no;
}

int insertarInicio(listaEnc lista, int item){
    No noNuevo=crearNodo(item, lista->inicio); //xq ahora el item nuevo lo puse/inserte en el inicio y el prox es el que antes era el q estaba en el inicio

    lista->inicio=noNuevo;
    lista->tam++;

    return 1;

}

int removerInicio(listaEnc lista, int * item){

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

int agregarFinal(listaEnc lista, int item){
//hacer que si no hay elementos que diga que la lista no fue inciada
    No aux = lista->inicio;

    while (aux->prox!=NULL){
        aux=aux->prox;
    }
    aux->prox=crearNodo(item, NULL);

    lista->tam++;

    return 1;
}

int insertar(listaEnc lista, int item, int pos) {

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

//porque la variable donde la guardo es un puntero, entonces le mando la direccion de memoria, porque un puntero
//es eso, apunta a la direc de memoria de donde esta la variable, entonces puntero a la direc de mi variable.
    printf("{");

    for (int i=0;i<tamLista;i++){

        int item;
        getElemento(lista, &item,i);
        printf(" %d ",item);
    }
    printf("}\n");
}

int eliminarElemento(listaEnc lista, int *item, int pos){

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

int getElemento(listaEnc lista, int * item, int pos){

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

int buscarElemento(listaEnc lista, int busco){

    No aux = lista->inicio;
    int cantElementos;
    int pos=-1;

    getTam(lista, &cantElementos);

    for (int i=0; i<cantElementos;i++){
        if(aux->item!=busco){
            aux=aux->prox;
        }
    else{
        if (aux->item==busco);
        pos=i;
    }
    }

    if (pos!=-1){
    printf("\nel valor que busca esta en la posicion %d de la lista.", pos);
    }
    else {
        printf("el valor no se encuentra en la lista");
    }

    return 1;
}

int ordenarLista(listaEnc lista){

    No act, ant;
    ant = lista->inicio;
    int tmp;

    while (ant->prox!=NULL){
          act=ant->prox;
        while (act!=NULL){
            if (ant->item > act->item){
                tmp=ant->item;
                ant->item=act->item;
                act->item=tmp;
            }
            act=act->prox;
        }
        ant=ant->prox;
    }
    return 1;
}

int busquedaBinaria(listaEnc lista, int busco){

    ordenarLista(lista);

    int inf, tam, mitad;

    int  encontre=-1;

    int item;

    getTam(lista,&tam);

    while (inf<=tam){

        mitad=(inf+tam)/2;

        getElemento(lista, &item, mitad);

        if(item==busco){

            encontre=1;

            break;
        }

       if (item>busco){

        tam=mitad;
        mitad=(inf+tam)/2;
       }

       if (item<busco){

        inf=mitad;
        mitad=(inf+tam)/2;

       }

    }

    if (encontre==1){

        printf("el valor fue encontrado en la posicion %d", mitad);
    }
      return 1;
}
