#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include "string.h"
//include "escolaridad.h"  // <--- ¡Esto es lo que maneja sus cursos cronológicamente!

typedef struct {
    long int cedula;
    str nombre;
    str apellido;
    int telefono;
    //Escolaridad historiaAcademica; // El TAD Secuencia LPPF
} Alumno;

/// Primitiva de carga (Crear Alumno)
void crearAlumno(Alumno &alum, long int ci, str nom, str ape, str tel);

                ///SELECTORAS
long int obtenerCedula(Alumno alum);
void obtenerNombreAlumno(Alumno al, str &nom);
void obtenerApellidoAlumno(Alumno al, str &ape);
int obtenerTelefonoAlumno(Alumno al, str &tel);
//void obtenerEscolaridad(Alumno al, Escolaridad &esc);
                ///SELECTORAS




#endif // ALUMNO_H_INCLUDED
