#ifndef ASIGNATURAS_H
#define ASIGNATURAS_H

#include "asignatura.h"

// ==================== Asignaturas (Diccionario) =================

const int MAX_ASIG = 30;

typedef struct {
    boolean existe;
    Asignatura info;
} Celda;

typedef Celda Asignaturas[MAX_ASIG];

// ================= PRIMITIVAS ==================
void make(Asignaturas& A);
boolean member(Asignaturas A, int numAsig);
void insert(Asignaturas& A, Asignatura a);
Asignatura find(Asignaturas A, int numAsig);
void modify(Asignaturas& A, Asignatura a, int numAsig);
void delete_(Asignaturas& A, int numAsig);

// ================= EXTENSIONES =================
void listar(Asignaturas A);

#endif