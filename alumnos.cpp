#include "alumnos.h"

// =============== Inicio metodos auxiliares =============

void crearCubeta(CubetaAlumnos c) { c = NULL; }

boolean perteneceCubeta(CubetaAlumnos c, int cedula) {
    boolean pertenece = FALSE;
    nodoAlumnos* aux = new nodoAlumnos;

    while (aux != NULL && !pertenece) {
        if (obtenerCedula(aux->info) == cedula) {
            pertenece = TRUE;
        }
        aux = aux->sig;
    }

    return pertenece;
}

Alumno findAlumnoCubeta(CubetaAlumnos c, int cedula) {
    nodoAlumnos* aux = c;

    while (obtenerCedula(aux->info) != cedula) {
        aux = aux->sig;
    }

    return aux->info;
}

void insFrontCubeta(CubetaAlumnos& c, Alumno a) {
    nodoAlumnos* nuevo = new nodoAlumnos;
    nuevo->info = a;
    nuevo->sig = c;
    c = nuevo;
}

void modifyAlumnoCubeta(CubetaAlumnos& c, Alumno a) {
    int cedula = obtenerCedula(a);
    nodoAlumnos* aux = c;

    while (obtenerCedula(aux->info) != cedula) {
        aux = aux->sig;
    }

    aux->info = a;
}

void deleteAlumnoCubeta(CubetaAlumnos& c, int cedula) {
    nodoAlumnos* aux = c;
    nodoAlumnos* anterior = NULL;

    while (obtenerCedula(aux->info) != cedula) {
        anterior = aux;
        aux = aux->sig;
    }

    if (anterior == NULL) {
        c = aux->sig;
    } else {
        anterior->sig = aux->sig;
    }

    delete aux;
}

int darCubeta(int cedula) { return cedula % B; }

// =============== Fin metodos auxiliares =============

void make(Alumnos& A) {
    int i;
    for (i = 0; i < B; i++) crearCubeta(A[i]);
}

boolean member(Alumnos A, int cedula) {
    int cubeta = darCubeta(cedula);
    perteneceCubeta(A[cubeta], cedula);
}

void insert(Alumnos& A, Alumno a) {
    int cedula = obtenerCedula(a);
    int cubeta = darCubeta(cedula);
    insFrontCubeta(A[cubeta], a);
}

Alumno find(Alumnos A, int cedula) {
    int cubeta = darCubeta(cedula);
    return findAlumnoCubeta(A[cubeta], cedula);
}

void modify(Alumnos& A, Alumno a) {
    int cubeta = darCubeta(obtenerCedula(a));
    modifyAlumnoCubeta(A[cubeta], a);
}

void delete_(Alumnos& A, int cedula) {
    int cubeta = darCubeta(cedula);
    deleteAlumnoCubeta(A[cubeta], cedula);
}
