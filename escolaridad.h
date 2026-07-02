#ifndef ESCOLARIDAD_H
#define ESCOLARIDAD_H

// Escolaridad (Secuencia Simple)

#include "boolean.h"
#include "curso.h"

typedef struct nodoEsc {
    Curso info;
    nodoEsc* sig;
} nodoEscolaridad;

typedef nodoEscolaridad* Escolaridad;

// ================= PRIMITIVAS ==================
void crear(Escolaridad& e);
void insFront(Escolaridad& s, Curso c);
boolean esVacia(Escolaridad s);
Curso primero(Escolaridad s);
Escolaridad resto(Escolaridad& s);
int largo(Escolaridad e);
Curso kEsimo(Escolaridad e, int k);

// ================= EXTENSIONES =================
void insBack(Escolaridad& s, Curso c);
Curso ultimo(Escolaridad s);
boolean estaAprobada(Escolaridad s, int numAsignatura);
int cantidadAprobados(Escolaridad s);

#endif