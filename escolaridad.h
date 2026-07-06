#ifndef ESCOLARIDAD_H_INCLUDED
#define ESCOLARIDAD_H_INCLUDED



/*
 * TAD  LPPF "Escolaridad"
 * -----------------------------------------------------------------------------------------
 * ¿Qué representa?
 * Representa la "historia académica" o el boletín de calificaciones de un alumno individual.
 * Cada alumno del sistema tiene su propia Escolaridad independiente.
 *
 * ¿Cómo se implementa?
 * A diferencia de Asignaturas (que es un arreglo estático), Escolaridad es una estructura
 * DINÁMICA (una Lista Enlazada de nodos LPPF). Esto es así porque la cantidad de materias que
 * puede cursar y aprobar un alumno a lo largo de los años es variable y no tiene un tope fijo.
 * -----------------------------------------------------------------------------------------
 */



#include "curso.h"
#include "boolean.h"

//1. Nodo de nuestra lista de cursos
typedef struct nodoC {
    Curso info;
    nodoC * sig;
} Nodo;

//2. LPPF Escolaridad
typedef struct {
    Nodo * prim;
    Nodo * ult;
} Escolaridad;

        ///Primitivas del TAD Secuencia (LPPF)///

///Inicializa la LPPF escolaridad (ambos punteros en NULL)
void inicializarEscolaridad(Escolaridad &esc);

///Inserta un curso al final de la secuencia (cronológicamente el último realizado) (InsBack LPPF)
void insertarCursoFinal(Escolaridad &esc, Curso c);

///Determina si la escolaridad no tiene ningún curso registrado
boolean esEscolaridadVacia(Escolaridad esc);


///Muesrta la LPPF imprimiendo cada curso
void mostrarEscolaridad(Escolaridad esc);



#endif // ESCOLARIDAD_H_INCLUDED
