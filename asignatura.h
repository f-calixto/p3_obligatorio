#ifndef ASIGNATURA_H_INCLUDED
#define ASIGNATURA_H_INCLUDED
#include "string.h"

typedef struct
{
    int numero;
    str nombre;
    int horas;
    boolean esOptativa;
} Asignatura;


///Crea una asignatura
void crearAsignatura(Asignatura &a ,int num, str nom, int hrs, boolean optativa);

///Operación auxiliar para asignatura
void imprimirAsignatura(Asignatura a);

        ///SELECTORAS ASIGNATURA
int obtenerNumero(Asignatura a);

void obtenerNombre(Asignatura a, str &nom);

int obtenerHoras(Asignatura a);

boolean esAsignaturaOptativa(Asignatura a);

#endif // ASIGNATURA_H_INCLUDED
