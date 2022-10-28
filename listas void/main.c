#include <stdio.h>
#include <stdlib.h>
#include "listasVOidd.h"



void mostrarLista(Lista lista);

int main()
{
    Lista listaEnteros = crearLista(sizeof(int));

    int x = 10;

    insertarInicio(listaEnteros, &x);

    x=20;
    insertarInicio(listaEnteros, &x);

    x=2;
    insertar(listaEnteros, &x, 1);

    x=7;
    insertarFinal(listaEnteros, &x);

    mostrarLista(listaEnteros);


    ordenarLista(listaEnteros);

    //mostrarLista(listaEnteros);

    return 0;
}

void mostrarLista(Lista lista){

    int tam=obtenerTam(lista);
    printf("\n");
    for (int i=0;i<tam;i++){

        int info = *((int*) obtenerDato(lista, i));
        printf("  -- %d --  ", info);

    }
}
