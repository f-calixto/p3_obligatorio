
#ifndef MENU_H
#define MENU_H

#include "alumnos.h"
#include "asignaturas.h"
#include "previaturas.h"

void mostrarMenu();

// Opción 1: Registrar una nueva asignatura en el sistema
void registrarAsignatura(Asignaturas &asignaturas);

//Opción 2: Agregar una relación de previatura directa verificando que no existan ciclos
void agregarPreviatura(Previaturas &previaturas, Asignaturas asignaturas);

void inscribirAlumno(Alumnos& alumnos);

// Opción 4: Registrar la nota de un curso finalizado para un estudiante
void registrarCursoFinalizado(Alumnos& alumnos, Asignaturas asignaturas,  Previaturas previaturas) 

// Opción 5: Listar el catálogo completo de asignaturas
void listarAsignaturas(Asignaturas asignaturas);

// Opción 6: Listar TODAS las previas (directas e indirectas) de una asignatura
void listarPrevias(Previaturas previaturas, Asignaturas asignaturas);

void mostrarDatosAlumno(Alumnos alumnos);

// Opción 8: Mostrar la escolaridad total de forma cronológica
void mostrarEscolaridadAlumno(Alumnos alumnos, Asignaturas asignaturas);

#endif // MENU_H
