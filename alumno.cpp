#include "alumno.h"

///Crea un alumno
void crearAlumno(Alumno &alum, long int ci, str nom, str ape, int tel)
{
    alum.cedula = ci;
    strcop(alum.nombre, nom);
    strcop(alum.apellido, ape);
    alum.telefono = tel;
    //inicializarEscolaridad(al.historiaAcademica);
}

        ///SELCTORAS///
long int obtenerCedula(Alumno alum)
{
    return alum.cedula;
}

void obtenerNombreAlumno(Alumno alum, str &nom)
{
    strcop(nom, alum.nombre);
}

void obtenerApellidoAlumno(Alumno alum, str &ape)
{
    strcop(ape, alum.apellido);
}

int obtenerTelefonoAlumno(Alumno alum)
{
    return alum.telefono;
}
            ///SELCTORAS///
