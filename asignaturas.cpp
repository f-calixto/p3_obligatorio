#include "asignaturas.h"
#include <stdio.h>

///Inicializa el diccionario vacío
void Create(Asignaturas &asigs)
{
    asigs.tope = 0;
}



///Determina si una asignatura pertenece al diccionario buscando por su número
boolean Member(Asignaturas asigs, int numAsig)
{
    boolean esta = FALSE;
    int i = 0;

    // Recorremos secuencialmente mientras queden elementos y no lo hayamos encontrado
    while ((i < asigs.tope) && (!esta))
    {
        if (obtenerNumero(asigs.coleccion[i]) == numAsig)
        {
            esta = TRUE;
        }
        else
        {
            i++;
        }
    }
    return esta;
}



///Inserta una nueva asignatura en el diccionario
void Insert (Asignaturas &asigs, Asignatura a)
{
    int i = asigs.tope - 1;
    int nuevoNum = obtenerNumero(a);

    // Corrimiento clásico hacia la derecha para hacer el hueco
    while ((i >= 0) && (obtenerNumero(asigs.coleccion[i]) > nuevoNum))
    {
        asigs.coleccion[i + 1] = asigs.coleccion[i];
        i--;
    }

    asigs.coleccion[i + 1] = a;
    asigs.tope++;
}




///Recupera una asignatura del diccionario dado su número
void Find(Asignaturas asigs, int numAsig, Asignatura &a)
{
    int i = 0;
    boolean encontrado = FALSE;

    while ((i < asigs.tope) && (!encontrado))
    {
        if (obtenerNumero(asigs.coleccion[i]) == numAsig)
        {
            a = asigs.coleccion[i];
            encontrado = TRUE;
        }
        else
        {
            i++;
        }
    }
}




/// Retorna TRUE si el diccionario está lleno
boolean Full(Asignaturas asigs)
{
    return (asigs.tope == MAX_ASIGNATURAS) ? TRUE : FALSE;
}




///Retorna la cantidad actual de asignaturas registradas
int Size(Asignaturas asigs)
{
    return asigs.tope;
}



///Muestra las asginaturas registradas
void Listar(Asignaturas asigs)
{
    if (asigs.tope == 0)
    {
        printf("No hay asignaturas registradas en el sistema.\n");
    }
    else
    {
        for (int i = 0; i < asigs.tope; i++)
        {
            imprimirAsignatura(asigs.coleccion[i]);
            printf("-----------------------------------------\n");
        }
    }
}
