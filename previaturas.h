#ifndef PREVIATURAS_H
#define PREVIATURAS_H

#include "boolean.h"

// ================== Previaturas (Grafo) =================

const int N = 30;

typedef boolean Grafo[N][N];

// ================= PRIMITIVAS ==================
void crear(Grafo& g);
boolean perteneceVertice(Grafo g, int u);
boolean perteneceArista(Grafo g, int u, int v);
// Precondición: el vértice no pertenece al grafo.
void insertarVertice(Grafo& g, int u);
// Precondición: la arista no pertenece al grafo
void insertarArista(Grafo& g, int u, int v);
// Precondición: el vértice pertenece al grafo.
void gradoVertice(Grafo g, int u);

// ================= EXTENSIONES =================
// Precondición: v y u pertenencen al grafo
boolean hayCamino(Grafo g, int v, int u);
// Precondición: u pertenence al grafo
void listarPreviaturas(Grafo g, int u);
// Precondición: u pertenence al grafo
void obtenerPrevias(Grafo g, int u, int res[],
                    int& cant);  // --> capaz podriamos devolver un "Escolaridad
                                 // previas" (definir)

#endif