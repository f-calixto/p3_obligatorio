#ifndef ASIGNATURAS_H_INCLUDED
#define ASIGNATURAS_H_INCLUDED


/*
 *TAD DICCIONARIO "Asignaturas"
 * --------------------------------------------------
 *ctúa como el gran Diccionario
 *el sistema donde se almacena de forma ordenada
 *el catálogo completo de todas las asignaturas que
 *los alumnos pueden cursar en la academia.
 * --------------------------------------------------
 */



#include "asignatura.h"
#include "boolean.h"


const int MAX_ASIGNATURAS = 50;

typedef struct {
    Asignatura coleccion[MAX_ASIGNATURAS];
    int tope;
} Asignaturas;


        ///PRIMITIVAS DEL TAD DICCIONARIO///

///Inicializa el diccionario vacío
void Create(Asignaturas &asigs);

///Determina si una asignatura pertenece al diccionario buscando por su número
boolean Member(Asignaturas asigs, int numAsig);

///Inserta una nueva asignatura en el diccionario
void Insert(Asignaturas &asigs, Asignatura a);

///Recupera una asignatura del diccionario dado su número
void Find(Asignaturas asigs, int numAsig, Asignatura &a);

        ///PRIMITIVAS DEL TAD DICCIONARIO///




        ///FUNCIONES AUXILIARES DE LA COLECCIÓN///

/// Retorna TRUE si el diccionario está lleno
boolean Full(Asignaturas asigs);

///Retorna la cantidad de elementos actuales
int Size(Asignaturas asigs);

///Muestra las asginaturas registradas
void Listar(Asignaturas asigs);

    ///FUNCIONES AUXILIARES DE LA COLECCIÓN///



#endif // ASIGNATURAS_H_INCLUDED
