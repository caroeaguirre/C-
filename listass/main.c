#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{


    //faltan las comprobaciones en casi todas las funciones y procedimientos, pero porque hice algo improvisado y rapido

    listaEnc lista1 = crearLista();

    insertarInicio(lista1, 11);

    agregarFinal(lista1, 43);

    agregarFinal(lista1, 54);

    agregarFinal(lista1, 22);
    agregarFinal(lista1, 35);

    //envio el elemtno, se va acrear un nodo, pero yo no lo hago, se hace automaticamente.

    imprimirLista(lista1);

    system("pause");

    int borre;

    eliminarElemento(lista1, &borre, 1);

    busquedaBinaria(lista1, 35);

    imprimirLista(lista1);

    //buscarElemento(lista1,11);
    //ordenarLista(lista1);

    imprimirLista(lista1);
    return 0;
}
