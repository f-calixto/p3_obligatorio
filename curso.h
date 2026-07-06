#ifndef CURSO_H_INCLUDED
#define CURSO_H_INCLUDED

#include "asignatura.h"
#include "Fecha.h"

typedef struct
{
    Asignatura materia;
    Fecha fechaFinalizacion;
    int calificacion;
} Curso;


///Crea un curso
void crearCurso(Curso &c, Asignatura asig, Fecha fec, int nota);

///Mostrar curso
void imprimirCurso(Curso c);

            ///SELCTORAS CURSO///
void obtenerAsignaturaCurso(Curso c, Asignatura &asig);

void obtenerFechaCurso(Curso c, Fecha &fec);

int obtenerCalificacion(Curso c);

///devuelve si el curso esta aprobado (si calificacion >=6)
boolean esCursoAprobado(Curso c);

#endif // CURSO_H_INCLUDED
