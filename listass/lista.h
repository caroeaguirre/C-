#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

struct NodoE;

typedef struct NodoE * No;

struct listaEncE;

typedef struct ListaEncE * listaEnc;

listaEnc crearLista();

No crearNodo(int item, No prox);

int insertarInicio(listaEnc lista, int item);

int agregarFinal(listaEnc lista, int item);

int insertar(listaEnc lista, int item, int pos);

int removerInicio(listaEnc lista, int * item);

int eliminarElemento(listaEnc lista, int *item, int pos);

void imprimirLista(listaEnc lista);

int estaVacia(listaEnc lista);

int getElemento(listaEnc lista, int * item, int pos);

int getTam(listaEnc lista, int * tam);

int buscarElemento(listaEnc lista, int busco);

int ordenarLista(listaEnc lista);

int busquedaBinaria(listaEnc lista, int busco);

#endif // LISTA_H_INCLUDED
