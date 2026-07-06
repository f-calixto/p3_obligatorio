#include "escolaridad.h"
#include <stdio.h>

///Inicializa la LPPF escolaridad (ambos punteros en NULL)
void inicializarEscolaridad(Escolaridad &esc)
{
    esc.prim = NULL;
    esc.ult = NULL;
}


///Inserta un curso al final de la secuencia (cronológicamente el último realizado) (InsBack LPPF)
void registrarCursoFinal(Escolaridad &esc, Curso c)
{
    Nodo * nuevo = new Nodo;
    nuevo->info = c; // Copia el struct Curso completo de una
    nuevo->sig = NULL;

    if (esc.ult == NULL) // Si la lista estaba vacía
    {
        esc.prim = nuevo;
        esc.ult = nuevo;
    }
    else // Si ya tenía elementos, colgamos del último usando el puntero 'ult'
    {
        esc.ult->sig = nuevo;
        esc.ult = nuevo;
    }
}



///Determina si la escolaridad no tiene ningún curso registrado
boolean esEscolaridadVacia(Escolaridad esc)
{
    if (esc.prim == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}



///Muesrta la LPPF imprimiendo cada curso
void mostrarEscolaridad(Escolaridad esc)
{
    Nodo * aux = esc.prim;

    if (aux == NULL)
    {
        printf("La escolaridad no registra cursos finalizados.\n");
    }
    else
    {
        while (aux != NULL)
        {
            imprimirCurso(aux->info); // Reutilizamos la primitiva que ya programaste en curso.cpp
            aux = aux->sig;
        }
    }
}
