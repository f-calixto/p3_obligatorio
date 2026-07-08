#ifndef CURSO_H
#define CURSO_H

#include "boolean.h"
#include "fecha.h"
#include "string.h"

typedef struct {
    int numAsignatura;
    string nombreAsignatura;
    Fecha fechaFin;
    int nota;
} Curso;

void crearCurso(Curso& c, int num, string nombre, string fecha, int nota);

int obtenerNumAsignatura(Curso c);
string obtenerNombreAsigantura(Curso c);
string obtenerFechaFin(Curso c);
int obtenerNota(Curso c);

boolean estaAprobado(Curso c);

#endif