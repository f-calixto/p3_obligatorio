#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "boolean.h"
#include <stdio.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

void CargarFecha (Fecha &f);

void MostrarFecha (Fecha f);

///dada una fecha f verifica si es una fecha valida o no
boolean ValidarFecha (Fecha f);

int DarDia (Fecha f);

int DarMes (Fecha f);

int DarAnio (Fecha f);

#endif // FECHA_H_INCLUDED
