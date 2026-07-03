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
void insert(Alumnos& A, Alumno a);
Alumno find(Alumnos A, int cedula);
void modify(Alumnos& A, Alumno a, int cedula);
void delete_(Alumnos& A, int cedula);

// ================= EXTENSIONES =================

#endif