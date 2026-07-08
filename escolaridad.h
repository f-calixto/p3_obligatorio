#ifndef ESCOLARIDAD_H
#define ESCOLARIDAD_H

#include "boolean.h"
#include "curso.h"

// ================= Escolaridad (Secuencia Simple) ===============

typedef struct nodoEsc {
    Curso info;
    nodoEsc* sig;
} nodoEscolaridad;

typedef nodoEscolaridad* Escolaridad;

// ================= PRIMITIVAS ==================
void crear(Escolaridad& e);
void insFront(Escolaridad& s, Curso c);
boolean esVacia(Escolaridad s);
// Precondición: la secuencia no es vacía.
Curso primero(Escolaridad s);
// Precondición: la secuencia no es vacía
Escolaridad resto(Escolaridad& s);
int largo(Escolaridad e);
// Precondición: El largo de la secuencia es mayor o igual a K.
Curso kEsimo(Escolaridad e, int k);

// ================= EXTENSIONES =================
void insBack(Escolaridad& s, Curso c);
Curso ultimo(Escolaridad s);
boolean estaAprobada(Escolaridad s, int numAsignatura);
int cantidadAprobados(Escolaridad s);

#endif