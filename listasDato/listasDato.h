#ifndef LISTASDATO_H_INCLUDED
#define LISTASDATO_H_INCLUDED

#include "dato.h"

struct NodoE;

typedef struct NodoE * No;

struct listaEncE;

typedef struct ListaEncE * listaEnc;

Dato crearDato();

listaEnc crearLista();

No crearNodo(Dato item, No prox);

int insertarInicio(listaEnc lista, Dato item);

int agregarFinal(listaEnc lista, Dato item);

int insertar(listaEnc lista, Dato item, int pos);

int removerInicio(listaEnc lista, Dato * item);

int eliminarElemento(listaEnc lista, Dato *item, int pos);

void imprimirLista(listaEnc lista);

int estaVacia(listaEnc lista);

int getElemento(listaEnc lista, Dato * item, int pos);

int getTam(listaEnc lista, int * tam);



#endif // LISTASDATO_H_INCLUDED
