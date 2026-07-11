#include "alumnos.h"
#include "asignaturas.h"
#include "previaturas.h"

void mostrarMenu() {
    print("Ingrese un numero de operacion:\n");
    print("1: Registrar nueva asignatura\n");
    print("2: Agregar previatura entre 2 asignaturas\n");
    print("3: Inscribir alumno\n");
    print("4: Registrar curso finalizado\n");
    print("5: Listar todas las asignaturas\n");
    print("6: Listar previas de asignaturas\n");
    print("7: Mostrar datos de alumno\n");
    print("8: Mostrar escolaridad de alumno\n");
    print("9: Salir del programa\n");
}

void registrarAsignatura(Asignaturas& asignaturas) {
    // if (estaCompleto(asignaturas)) {
    //     printRojo("Tope de asignaturas alcanzado\n");
    //     return;
    // }

    // Asignatura nueva;
    // crearAsignatura(nueva);
}

void agregarPreviatura(Previaturas& previaturas) {}

void inscribirAlumno(Alumnos& alumnos) {
    Alumno nuevo;
    crearAlumno(nuevo);

    if (member(alumnos, obtenerCedula(nuevo))) {
        printRojo("El alumno ya esta registrado\n\n");
    } else {
        insert(alumnos, nuevo);
        printVerde("Alumno ingresado correctamente\n\n");
    }
}

void registrarCursoFinalizado() {}

void listarAsignaturas(Asignaturas asignaturas) { listar(asignaturas); }

void listarPrevias() {}

void mostrarDatosAlumno() {}

void mostrarEscolaridadAlumno() {}

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
                agregarPreviatura(previaturas);
                break;
            case 3:
                inscribirAlumno(alumnos);
                break;
            case 4:
                registrarCursoFinalizado();
                break;
            case 5:
                listarAsignaturas(asignaturas);
                break;
            case 6:
                listarPrevias();
                break;
            case 7:
                mostrarDatosAlumno();
                break;
            case 8:
                mostrarEscolaridadAlumno();
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