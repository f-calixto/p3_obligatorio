#ifndef ASIGNATURA_H
#define ASIGNATURA_H

// #include "boolean.h"  boolean ya viene incluido en string.h
#include "string.h"

typedef struct {
    int numero;
    string nombre;
    int horas;
    boolean esOptativa;
} Asignatura;

void crearAsignatura(Asignatura& a);
int obtenerNumero(Asignatura a);
void obtenerNombre(Asignatura a, string& s);
int obtenerHoras(Asignatura a);
boolean esOptativa(Asignatura a);
void asignarNumero(Asignatura& a, int nro);
void mostrarAsignatura(Asignatura a);

#endif
