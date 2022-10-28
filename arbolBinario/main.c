#include <stdio.h>
#include <stdlib.h>
#include "arbolBinario.h"

int main()
{
    nodo raiz = crearNodo(28);
    insertar(raiz, 11);
    insertar(raiz, 96);
    insertar(raiz, 21);
    insertar(raiz, 6);
    insertar(raiz, 97);
    insertar(raiz, 10);
    insertar(raiz, 1);
    insertar(raiz, 2);
    insertar(raiz, 30);


    printf("imprimir en PREORDEN\n");
    preorden(raiz);
    printf("\nimprimir en INORDEN\n");
    inorden(raiz);
    printf("\nimprimir en POSTORDEN\n");
    postorden(raiz);

    int altura;
    altura= calcularAltura(raiz);
    printf("\n\n --- ALTURA  %d -- ", altura);


    return 0;
}
