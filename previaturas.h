/* ==================================================================================
MÓDULO: PREVIATURAS (GRAFO)
==================================================================================
DESCRIPCIÓN CONCEPTUAL:
Representa la relacion entre asignaturas de la carrera mediante un Grafo Dirigido y Acíclico
implementado sobre una Matriz de Adyacencia de booleanos de tamaño fijo (30x30).

RELACIÓN CON LA REALIDAD Y LA LETRA DEL OBLIGATORIO:
- VÉRTICES: Representan los números enteros únicos de las Asignaturas.
- ARISTAS: Representan las relaciones de previatura entre dos materias.
  Si la asignatura 'u' es previa de 'v', la celda g[u][v] será TRUE.

  La operación 'hayCamino' evalúa mediante el algoritmo
   DFS si existe una correlatividad directa o transitiva entre dos asignaturas,
   permitiendo validar si un estudiante cumple con los requisitos del plan de
   estudios antes de registrar una nueva nota en su Escolaridad.
==================================================================================
*/


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

// Precondición: la arista no pertenece al grafo
void insertarArista(Grafo& g, int u, int v);

// Precondición: el vértice pertenece al grafo.
void gradoVertice(Grafo g, int u);



// ================= EXTENSIONES =================

// Precondición: v y u pertenecen al grafo.
// determina si v es olbigatoria para cursar u
boolean hayCamino(Grafo g, int v, int u);

// Precondición: u pertenence al grafo
//imrpimre por pantalla la lista d los numeros de las asignaturas previas a u
void listarPreviaturas(Grafo g, int u);

// Precondición: u pertenence al grafo
void obtenerPrevias(Grafo g, int u, int res[],
                    int& cant);  // --> capaz podriamos devolver un "Escolaridad
                                 // previas" (definir)

#endif
