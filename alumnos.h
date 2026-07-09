#ifndef ALUMNOS_a
#define ALUMNOS_a

#include "alumno.h"

// ===================== Alumnos (Diccionario) =================

// Habrán +-100 alumnos, asumimos una distribución equitativa
// de la clave y apuntamos a armar 10 cubetas de +-10 alumnos
const int B = 10;

typedef struct nodoA {
    Alumno info;
    nodoA* sig;
} nodoAlumnos;

typedef nodoAlumnos* CubetaAlumnos;

typedef CubetaAlumnos Alumnos[B];

// ================= PRIMITIVAS ==================
void make(Alumnos& A);
boolean member(Alumnos A, int cedula);
// Precondición: el elemento a insertar no es miembro del diccionario.
void insert(Alumnos& A, Alumno a);
// Precondición: el elemento es miembro del diccionario.
Alumno find(Alumnos A, int cedula);
// Precondición: el elemento a sustituir es miembro del diccionario.
void modify(Alumnos& A, Alumno a);
// Precondición: el elemento es miembro del diccionario.
void delete_(Alumnos& A, int cedula);

// ================= EXTENSIONES =================

#endif