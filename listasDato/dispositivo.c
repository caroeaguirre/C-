#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dispositivo.h"
#include "persona.h"


struct DispositivoEstructura{

    char tipo[15];
    char marca[15];
    float precio;
    persona duenio;


};

dispositivo crearDispositivo(char t[15], char m[15], float p){

    dispositivo x = malloc(sizeof(struct DispositivoEstructura));

    strcpy(x->marca, m);
    strcpy(x->tipo, t);
    x->precio=p;
    x->duenio=crearPersonaxTeclado();

    return x;

}

void mostrarDispositivo(dispositivo x){

    printf("-----> TIPO: %s\n", x->tipo);
    printf("-----> MARCA: %s\n", x->marca);
    printf("-----> PRECIO: %.2f\n", x->precio);

}

void mostrarDispositivos(dispositivo v[], int t){

    for (int i=0;i<t;i++){

        if (getPrecio(v[i])!= -1){

            mostrarDispositivo(v[i]);
        }
    }
}



void agregarDispositivo(dispositivo v[], int t, dispositivo x){

    int i = buscarPosVacia(v, t);

    if (i!=-9){

        v[i]=x;
    }else{
        printf("\nya no hay espacio para un nuevo dispositivo\n");
    }
}

void iniciarDispositvos(dispositivo v[], int t){

    for (int i=0;i<t;i++){
            v[i]=crearDispositivo(" ", " ", -1);
    }
}

float getPrecio(dispositivo x){

    return x->precio;
}
int buscarPosVacia(dispositivo v[], int t){

    int pos = -9;
    int i = 0;

    while(pos==-9 && i<t){

        if (v[i]->precio==-1){
            pos = i;
        }
        i++;
    }
    return pos;
}
