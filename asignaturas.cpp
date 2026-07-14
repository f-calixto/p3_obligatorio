#include "asignaturas.h"

#include <stdio.h>

// Inicializa el diccionario poniendo el tope en 0
void make(Asignaturas& A) { A.tope = 0; }

// Devuelve TRUE si la asignatura existe recorriendo secuencialmente hasta el
// tope
boolean member(Asignaturas A, int numAsig) {
    boolean esta = FALSE;
    int i = 0;

    while ((i < A.tope) && (!esta)) {
        if (obtenerNumero(A.act[i]) == numAsig) {
            esta = TRUE;
        } else {
            i++;
        }
    }
    return esta;
}

// Inserta al final del arreglo aprovechando el tope
void insert(Asignaturas& A, Asignatura a) {
    if (A.tope < MAX_ASIG) {
        A.act[A.tope] = a;
        A.tope++;
    }
}

// Busca secuencialmente y retorna la asignatura
Asignatura find(Asignaturas A, int numAsig) {
    int i = 0;
    boolean encontrado = FALSE;
    Asignatura encontrada;

    while ((i < A.tope) && (!encontrado)) {
        if (obtenerNumero(A.act[i]) == numAsig) {
            encontrada = A.act[i];
            encontrado = TRUE;
        } else {
            i++;
        }
    }
    return encontrada;
}

// Modifica los datos de la asignatura existente buscando su posición
void modify(Asignaturas& A, Asignatura a, int numAsig) {
    int i = 0;
    boolean modificado = FALSE;

    while ((i < A.tope) && (!modificado)) {
        if (obtenerNumero(A.act[i]) == numAsig) {
            A.act[i] = a;
            modificado = TRUE;
        } else {
            i++;
        }
    }
}

// Elimina una asignatura haciendo un "cambio por el último" para no dejar
// huecos
void delete_(Asignaturas& A, int numAsig) {
    int i = 0;
    boolean eliminado = FALSE;

    while ((i < A.tope) && (!eliminado)) {
        if (obtenerNumero(A.act[i]) == numAsig) {
            // Pisamos el elemento a borrar con el que está en la última
            // posición válida
            A.act[i] = A.act[A.tope - 1];
            A.tope--;  // Achicamos el tope
            eliminado = TRUE;
        } else {
            i++;
        }
    }
}

// ================= EXTENSIONES =================

void listar(Asignaturas A) {
    printf("\n--- LISTADO DE ASIGNATURAS ---\n");
    if (A.tope == 0) {
        printRojo("No hay asignaturas registradas en el sistema.\n");
    } else {
        for (int i = 0; i < A.tope; i++) {
            mostrarAsignatura(A.act[i]);
            printf("\n---\n");
        }
    }
    printf("-------------------------------\n");
}

int largo(Asignaturas A) { return A.tope; }