#include "alumno.h"

void crearAlumno(Alumno& a) {
    printf("\nIngrese cedula: ");
    scanf("%d", &a.ci);

    printf("Ingrese nombre: ");
    strcrear(a.nombre);
    scan(a.nombre);

    printf("Ingrese apellido: ");
    strcrear(a.apellido);
    scan(a.apellido);

    printf("Ingrese telefono: ");
    strcrear(a.telefono);
    scan(a.telefono);

    a.escolaridad = NULL;
}

int obtenerCedula(Alumno a) { return a.ci; }

void obtenerNombre(Alumno a, string& s) {
    strcrear(s);
    strcop(s, a.nombre);
}

void obtenerApellido(Alumno a, string& s) {
    strcrear(s);
    strcop(s, a.apellido);
}

void obtenerTelefono(Alumno a, string& s) {
    strcrear(s);
    strcop(s, a.telefono);
}

Escolaridad obtenerEscolaridad(Alumno a) { return a.escolaridad; }
