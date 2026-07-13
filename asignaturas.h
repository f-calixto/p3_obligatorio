#ifndef ASIGNATURAS_H
#define ASIGNATURAS_H

#include "asignatura.h"
#include "boolean.h"

// ==================== Asignaturas (Arreglo con Tope, act) =================

const int MAX_ASIG = 30;

typedef struct {
    Asignatura act[MAX_ASIG];
    int tope;
} Asignaturas;

// ================= PRIMITIVAS ==================
// Inicializa el diccionario poniendo el tope en 0
void make(Asignaturas &A);

// Devuelve TRUE si la asignatura existe recorriendo el arreglo hasta el tope
boolean member(Asignaturas A, int numAsig);

// Precondición: la asignatura a insertar no existe en diccionario A y tope < MAX_ASIG
void insert(Asignaturas &A, Asignatura a);

// Precondición: la asignatura existe en el diccionario A
Asignatura find(Asignaturas A, int numAsig);

// Precondición: la asignatura a sustituir existe en diccionario A
void modify(Asignaturas &A, Asignatura a, int numAsig);

// Precondición: la asignatura existe en diccionario A
void delete_(Asignaturas &A, int numAsig);

// ================= EXTENSIONES =================
void listar(Asignaturas A);

#endif
