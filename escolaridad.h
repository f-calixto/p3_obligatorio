#ifndef ESCOLARIDAD_H
#define ESCOLARIDAD_H

//#include "boolean.h" boolean.h esta incluido en string.h , string.h esta incluido en curso.h
#include "curso.h"

// ================= Escolaridad (Secuencia Simple) ===============

typedef struct nodoEsc {
    Curso info;
    nodoEsc* sig;
} nodoEscolaridad;

typedef struct {
    nodoEscolaridad* prim;
    nodoEscolaridad* ult;
} Escolaridad;

// ================= PRIMITIVAS ==================
void crearEscolaridad(Escolaridad& e);
void insFront(Escolaridad& e, Curso c);
boolean esVacia(Escolaridad e);
// Precondición: la secuencia no es vacía.
Curso primero(Escolaridad e);
// Precondición: la secuencia no es vacía
Escolaridad resto(Escolaridad& e);
int largo(Escolaridad e);
// Precondición: El largo de la secuencia es mayor o igual a K.
Curso kEsimo(Escolaridad e, int k);

// ================= EXTENSIONES =================
void insBack(Escolaridad& e, Curso c);
Curso ultimo(Escolaridad e);
boolean estaAprobada(Escolaridad e, int numAsignatura);
int cantidadAprobados(Escolaridad e);

#endif
