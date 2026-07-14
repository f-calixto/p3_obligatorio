#include <stdio.h>

#include "menu.h"

int main() {
    boolean continuar = TRUE;
    Asignaturas asignaturas;
    Alumnos alumnos;
    Previaturas previaturas;

    make(asignaturas);
    make(alumnos);
    crear(previaturas);

    while (continuar) {
        int operacion;

        mostrarMenu();
        printf("\nIngrese numero de operacion (1-8) o 9 para salir: ");
        scanf("%d", &operacion);

        switch (operacion) {
            case 1:
                registrarAsignatura(asignaturas);
                break;
            case 2:
                agregarPreviatura(previaturas, asignaturas);
                break;
            case 3:
                inscribirAlumno(alumnos);
                break;
            case 4:
                registrarCursoFinalizado(alumnos, asignaturas, previaturas);
                break;
            case 5:
                listarAsignaturas(asignaturas);
                break;
            case 6:
                listarPrevias(previaturas, asignaturas);
                break;
            case 7:
                mostrarDatosAlumno(alumnos);
                break;
            case 8:
                mostrarEscolaridadAlumno(alumnos, asignaturas);
                break;
            case 9:
                continuar = FALSE;
                printVerde("\nSaliendo del programa\n");
                break;
            default:
                printRojo("\nNumero de operacion invalida\n");
                break;
        }
    }

    return 0;
}
