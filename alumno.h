#ifndef ALUMNO_H
#define ALUMNO_H

#include "boolean.h"
#include "curso.h"
#include "escolaridad.h"
#include "string.h"

typedef struct {
    int ci;
    string nombre;
    string apellido;
    string telefono;
    Escolaridad escolaridad;
} Alumno;

void crearAlumno(Alumno& a, int ci, string nombre, string apellido,
                 string telefono);

int obtenerCedula(Alumno a);
void obtenerNombre(Alumno a, string& s);
void obtenerApellido(Alumno a, string& s);
void obtenerTelefono(Alumno a, string& s);
Escolaridad obtenerEscolaridad(Alumno a);

#endif