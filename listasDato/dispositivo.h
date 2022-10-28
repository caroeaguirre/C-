#ifndef DISPOSITIVO_H_INCLUDED
#define DISPOSITIVO_H_INCLUDED

struct DispositivoEstructura;

typedef struct DispositivoEstructura * dispositivo;

dispositivo crearDispositivo(char t[15], char m[15], float p);

void mostrarDispositivo(dispositivo x);

void mostrarDispositivos(dispositivo v[], int t);

int buscarPosVacia(dispositivo v[], int t);

void agregarDispositivo(dispositivo v[], int t, dispositivo x);

void iniciarDispositvos(dispositivo v[], int t);

//GETS
float getPrecio(dispositivo x);

//SETS

#endif // DISPOSITIVO_H_INCLUDED
