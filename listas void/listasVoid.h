#ifndef LISTASVOID_H_INCLUDED
#define LISTASVOID_H_INCLUDED

struct NodoE;

typedef struct NodoE* Nodo;

struct listaE;

typedef struct listaE * Lista;


Nodo crearNodo(Lista lista, void *dato);
Lista crearLista(int tamDelDato);
int estaVacia(Lista lista);
int obtenerTam(Lista lista);

void* obtenerDato(Lista lista, int pos);
void* obtenerPrimerDato(Lista lista);
void* obtenerUltimoDato(Lista lista);

int obtenerDatoEnParametro(Lista lista, int pos, void* datoBackUp);
int insertar(Lista lista, void*dato, int pos);
int insertarInicio(Lista lista, void*dato);
int insertarFinal(Lista lista, void*dato);
int removerInicio(Lista lista, void*backup);
int removerFinal(Lista lista, void*backup);
int remover(Lista lista, void*backup, int pos);

#endif // LISTASVOID_H_INCLUDED
