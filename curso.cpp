#include "curso.h"

void crearCurso(Curso& c) {
    printf("\nIngrese numero de asignatura: ");
    scanf("%d", &c.numAsignatura);

    printf("Ingrese nombre de la asignatura: ");
    strcrear(c.nombreAsignatura);
    scan(c.nombreAsignatura);

    printf("Ingrese fecha de fin (dia mes anio): ");
    cargarFecha(c.fechaFin);

    printf("Ingrese nota: ");
    scanf("%d", &c.nota);
}

int obtenerNumAsignatura(Curso c) { return c.numAsignatura; }

void obtenerNombreAsigantura(Curso c, string& s) {
    strcrear(s);
    strcop(s, c.nombreAsignatura);
}

Fecha obtenerFechaFin(Curso c) { return c.fechaFin; }

int obtenerNota(Curso c) { return c.nota; }

boolean estaAprobado(Curso c) {
    if (c.nota >= 6) {
        return TRUE;
    }
    return FALSE;
}
