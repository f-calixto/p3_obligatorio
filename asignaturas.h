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
// Inicializa el diccionario poniendo todas las celdas en FALSE
void make(Asignaturas &A);

// Devuelve TRUE si la asignatura existe en esa posición del diccionario arreglo A
boolean member(Asignaturas A, int numAsig);

// Precondición: la asignatura a insertar no existe en diccionario A
void insert(Asignaturas &A, Asignatura a);

// Precondición: la asignatura existe en el diccionario A
Asignatura find(Asignaturas A, int numAsig);

// Precondición: la asigantura a sustituir existe en diccionario A
void modify(Asignaturas &A, Asignatura a, int numAsig);

// Precondición: la asignatura existe en diccionario A
void delete_(Asignaturas& A, int numAsig);

// ================= EXTENSIONES =================
void listar(Asignaturas A);

#endif
