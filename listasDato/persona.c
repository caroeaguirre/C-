#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

struct PersonaE{

    char nombre[30];
    int edad;
    int dni;

};

Persona crearPersona(char n[30], int e, int dni){

    Persona p = malloc(sizeof(struct PersonaE));

    p->dni=dni;
    p->edad=e;
    strcpy(p->nombre,n);

    return p;
}

void mostrarPersona(Persona p){

    printf("\n\n ---- PERSONA ---- \n");

    printf("\nNOMBRE: %s", p->nombre);
    printf("\nEDAD: %d", p->edad);
    printf("\nDNI: %d", p->dni);

}

char * getNombre(Persona p){

    return p->nombre;
}

int getDni(Persona p){
    return p->dni;
}

int getEdad(Persona p){

    return p->edad;
}

void setNombre(Persona p, char nombreN[30]){

    strcpy(p->nombre, nombreN);
}

void setDni(Persona p, int dniN){

    p->dni=dniN;
}

void setEdad(Persona p, int eN){
    p->edad=eN;
}
