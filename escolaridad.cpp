#include "escolaridad.h"

void crearEscolaridad(Escolaridad& e) {
    e.prim = NULL;
    e.ult = NULL;
}

void insFront(Escolaridad& e, Curso c) {
    nodoEscolaridad* nuevo = new nodoEscolaridad;
    nuevo->info = c;
    nuevo->sig = e.prim;
    e.prim = nuevo;
    if (e.ult == NULL) e.ult = nuevo;
}

boolean esVacia(Escolaridad e) {
    if (e.prim == NULL && e.ult == NULL) {
        return TRUE;
    }
    return FALSE;
}

Curso primero(Escolaridad e) { return e.prim->info; }

Escolaridad resto(Escolaridad& e) {
    nodoEscolaridad* aux = e.prim->sig;
    delete (e.prim);
    e.prim = aux;
    if (e.prim == NULL) e.ult = NULL;
}

int largo(Escolaridad e) {
    int largo = 0;
    nodoEscolaridad* aux = e.prim;

    while (aux != NULL) {
        largo++;
        aux = aux->sig;
    }

    return largo;
}

Curso kEsimo(Escolaridad e, int k) {
    int i = 1;
    nodoEscolaridad* aux = e.prim;

    while (i < k) {
        i++;
        aux = aux->sig;
    }

    return aux->info;
}

void insBack(Escolaridad& e, Curso c) {
    nodoEscolaridad* nuevo = new nodoEscolaridad;
    nuevo->info = c;
    nuevo->sig = NULL;
    if (e.ult == NULL) {
        e.ult = nuevo;
        e.prim = nuevo;
    } else {
        e.ult->sig = nuevo;
        e.ult = nuevo;
    }
}

Curso ultimo(Escolaridad e) { return e.ult->info; }

boolean estaAprobada(Escolaridad e, int numAsignatura) {
    boolean aprobada = FALSE;
    nodoEscolaridad* aux = e.prim;

    while (aux != NULL && !aprobada) {
        if (aux->info.numAsignatura == numAsignatura &&
            estaAprobado(aux->info)) {
            aprobada = TRUE;
        }
        aux = aux->sig;
    }

    return aprobada;
}

int cantidadAprobados(Escolaridad e) {
    int aprobados = 0;
    nodoEscolaridad* aux = e.prim;

    while (aux != NULL) {
        if (estaAprobado(aux->info)) {
            aprobados++;
        }
        aux = aux->sig;
    }

    return aprobados;
}
