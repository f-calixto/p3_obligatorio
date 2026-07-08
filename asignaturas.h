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
// Precondición: el elemento a insertar no es miembro del diccionario.
void insert(Asignaturas& A, Asignatura a);
// Precondición: el elemento es miembro del diccionario.
Asignatura find(Asignaturas A, int numAsig);
// Precondición: el elemento a sustituir es miembro del diccionario.
void modify(Asignaturas& A, Asignatura a, int numAsig);
// Precondición: el elemento es miembro del diccionario.
void delete_(Asignaturas& A, int numAsig);

// ================= EXTENSIONES =================
void listar(Asignaturas A);

#endif