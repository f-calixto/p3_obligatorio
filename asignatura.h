#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include "boolean.h"
#include "string.h"

typedef struct {
    int numero;
    string nombre;
    int horas;
    boolean optativa;
} Asignatura;

void crearAsignatura(Asignatura& a);
int obtenerNumero(Asignatura a);
string obtenerNombre(Asignatura a);
int obtenerHoras(Asignatura a);
boolean esOptativa(Asignatura a);

#endif