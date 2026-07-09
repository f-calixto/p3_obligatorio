#include "asignaturas.h"


// Inicializa el diccionario poniendo todas las celdas en FALSE
void make(Asignaturas& A)
{
    for (int i = 0; i < MAX_ASIG; i++)
    {
        A[i].existe = FALSE;
    }
}

// Devuelve TRUE si la asignatura existe en esa posición del arreglo
boolean member(Asignaturas A, int numAsig)
{
    if (numAsig >= 0 && numAsig < MAX_ASIG)
    {
        return A[numAsig].existe;
    }
    return FALSE;
}

// Precondición: la asignaturaa a insertar no exitse en diccionario A.
void insert (Asignaturas& A, Asignatura a)
{
    int pos = obtenerNumero(a);

    if (pos >= 0 && pos < MAX_ASIG)
    {
        A[pos].info = a;
        A[pos].existe = TRUE;
    }
}

// Precondición: la asignatura existe en el diccionario A
Asignatura find (Asignaturas A, int numAsig)
{
    return A[numAsig].info;
}

// Precondición: la asigantura sustituir existe en iccionario A.
void modify (Asignaturas& A, Asignatura a, int numAsig)
{
    A[numAsig].info = a;
}

// Precondición: la asignatura existe en diccionario A
void delete_(Asignaturas& A, int numAsig)
{
    A[numAsig].existe = FALSE;
}

// ================= EXTENSIONES =================

// Precondición: la asignatura existe en diccionario A
void listar(Asignaturas A)
{
    boolean hayMaterias = FALSE;
    printf("\n--- LISTADO DE ASIGNATURAS ---\n");
    for (int i = 0; i < MAX_ASIG; i++)
    {
        if (A[i].existe == TRUE)
        {
            mostrarAsignatura(A[i].info);
            hayMaterias = TRUE;
        }
    }
    if (!hayMaterias)
    {
        printf("No hay asignaturas registradas en el sistema.\n");
    }
    printf("-------------------------------\n");
}
