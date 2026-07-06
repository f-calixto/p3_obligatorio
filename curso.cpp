#include "curso.h"

///Crea un curso
void crearCurso(Curso &c, Asignatura asig, Fecha fec, int nota)
{
    c.materia = asig;
    c.fechaFinalizacion = fec;
    c.calificacion = nota;
}



///Mostrar curso
void imprimirCurso(Curso c)
{
    printf("\nAsignatura curso: \n");
    imprimirAsignatura(c.materia);

    printf("\nFecha finalizacion curso: \n");
    MostrarFecha(c.fechaFinalizacion);

    printf("Calificacion: %d ", c.calificacion);
    if (esCursoAprobado(c) == TRUE)
    {
        printf("(APROBADO)\n");
    }
    else
    {
        printf("(REPROBADO/RECUSA)\n");
    }
}



                    ///SELCTORAS CURSO///
void obtenerAsignaturaCurso(Curso c, Asignatura &asig)
{
    asig = c.materia;
}


void obtenerFechaCurso(Curso c, Fecha &fec)
{
    fec = c.fechaFinalizacion;
}


int obtenerCalificacion(Curso c)
{
    return c.calificacion;
}

///devuelve si el curso esta aprobado (si c.calificacion >=6)
boolean esCursoAprobado(Curso c)
{
    if (c.calificacion >= 6)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
                    ///SELCTORAS CURSO///
