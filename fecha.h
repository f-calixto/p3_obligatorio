#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <stdio.h>

#include "boolean.h"

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

void cargarFecha(Fecha& fecha);
void mostrarFecha(Fecha fecha);

int obtenerDia(Fecha fecha);
int obtenerMes(Fecha fecha);
int obtenerAnio(Fecha fecha);
boolean esIgualOMayor(Fecha f1, Fecha f2);
boolean esValida(Fecha fecha);

#endif  // FECHA_H_INCLUDED
