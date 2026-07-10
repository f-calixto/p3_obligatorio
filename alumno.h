#ifndef ALUMNO_H
#define ALUMNO_H

//#include "boolean.h" boolean ya viene incluido en string.h
//#include "string.h" string.h ya viene incluido en curso.h 
//#include "curso.h" curso.h ya viene incluido en escolaridad.h 
#include "escolaridad.h"

typedef struct {
    int ci;
    string nombre;
    string apellido;
    string telefono;
    Escolaridad escolaridad;
} Alumno;

void crearAlumno(Alumno& a);
int obtenerCedula(Alumno a);
void obtenerNombre(Alumno a, string& s);
void obtenerApellido(Alumno a, string& s);
void obtenerTelefono(Alumno a, string& s);
Escolaridad obtenerEscolaridad(Alumno a);

#endif
