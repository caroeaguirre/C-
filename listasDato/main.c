#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "dato.h"
#include "listasDato.h"

int main()
{
    Persona p1 = crearPersona("Carolina", 19, 44366782);
    Persona p2 = crearPersona("Franco", 19, 44302429);

   Dato d = crearDato();

   listaEnc lista1 = crearLista();

   d->persona = p1;
   insertarInicio(lista1,d);

    Dato d1=crearDato();

   d1->persona=p2;
   insertarInicio(lista1, d1);

   imprimirLista(lista1);


    return 0;
}



 //cree un dato. el dato tiene atributos tipo persona, entoces digo que el dato persona es igual a la persona que cree.
