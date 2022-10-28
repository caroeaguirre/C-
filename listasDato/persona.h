#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

struct PersonaE;

typedef struct PersonaE * Persona;

Persona crearPersona(char n[30], int e, int dni);

void mostrarPersona(Persona p);

char * getNombre(Persona p);

int getDni(Persona p);

int getEdad(Persona p);

void setNombre(Persona p, char nombreN[30]);

void setDni(Persona p, int dniN);

void setEdad(Persona p, int eN);



#endif // PERSONA_H_INCLUDED
