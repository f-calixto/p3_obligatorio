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

void crearCurso(Curso& c);
int obtenerNumAsignatura(Curso c);
void obtenerNombreAsigantura(Curso c, string& s);
Fecha obtenerFechaFin(Curso c);
int obtenerNota(Curso c);
boolean estaAprobado(Curso c);

#endif