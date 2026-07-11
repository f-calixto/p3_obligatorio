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

void registrarCursoFinalizado(Alumnos& alumnos, Asignaturas asignaturas,
                              Previaturas previaturas) {
    int ci;
    print("Ingrese la cedula del alumno: ");
    scanf("%d", &ci);

    if (!member(alumnos, ci)) {
        printRojo("El alumno no esta registrado en la academia\n\n");
        return;
    }

    Curso cursoARegistrar;
    crearCurso(cursoARegistrar);
    int nroAsignatura = obtenerNumAsignatura(cursoARegistrar);

    if (!member(asignaturas, nroAsignatura)) {
        printRojo("La asignatura no esta registrada\n\n");
        return;
    }

    string nombreAsig, nombreCurso;
    obtenerNombre(find(asignaturas, nroAsignatura), nombreAsig);
    obtenerNombreAsigantura(cursoARegistrar, nombreCurso);
    if (!streq(nombreCurso, nombreAsig)) {
        printRojo(
            "La asignatura con dicho numero fue ingresada con otro nombre: ");
        printRojo(nombreAsig);
        print("\n\n");
        return;
    }

    Alumno alumno = find(alumnos, ci);
    Escolaridad escolaridad = obtenerEscolaridad(alumno);

    if (estaAprobada(escolaridad, nroAsignatura)) {
        printRojo("La asignatura ya esta aprobada por el alumno\n\n");
        return;
    }

    if (!esVacia(escolaridad)) {
        Curso ult = ultimo(escolaridad);
        Fecha fechaFinUltimo = obtenerFechaFin(ult);
        if (!esIgualOMayor(obtenerFechaFin(cursoARegistrar), fechaFinUltimo)) {
            printRojo(
                "La fecha de finalizacion debe ser igual o mayor al ultimo "
                "curso "
                "registrado\n\n");
            return;
        }
    }

    if (perteneceVertice(previaturas, nroAsignatura)) {
        int previas[MAX_ASIG];
        int cantidadPrevias;
        obtenerPreviasInmediatas(previaturas, nroAsignatura, previas,
                                 cantidadPrevias);

        for (int i = 0; i < cantidadPrevias; i++) {
            if (!estaAprobada(escolaridad, previas[i])) {
                printRojo("Deben estar aprobadas todas las previas\n\n");
                return;
            }
        }
    }

    insBack(escolaridad, cursoARegistrar);
    asignarEscolaridad(alumno, escolaridad);
    modify(alumnos, alumno);
    printVerde("Curso ingresado con exito\n\n");
}

void listarAsignaturas(Asignaturas asignaturas) { listar(asignaturas); }

void listarPrevias() {}

void mostrarDatosAlumno(Alumnos alumnos) {
    int ci;
    print("Ingrese la cedula del alumno: ");
    scanf("%d", &ci);

    if (!member(alumnos, ci)) {
        printRojo("El alumno no esta registrado en la academia\n\n");
        return;
    }

    Alumno alumno;
    string nombre, apellido, telefono;
    Escolaridad escolaridad;
    int cantidadCursos, cantidadAprobadas;

    alumno = find(alumnos, ci);
    obtenerNombre(alumno, nombre);
    obtenerApellido(alumno, apellido);
    obtenerTelefono(alumno, telefono);
    escolaridad = obtenerEscolaridad(alumno);

    printf("\n   Nombre: %s %s\n", nombre, apellido);
    printf("\n   Telefono: %s\n", telefono);
    printf("\n   Cursos registrados: %d\n", largo(escolaridad));
    printf("\n   Cursos aprobados: %d\n\n", cantidadAprobados(escolaridad));
}

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
                registrarCursoFinalizado(alumnos, asignaturas, previaturas);
                break;
            case 5:
                listarAsignaturas(asignaturas);
                break;
            case 6:
                listarPrevias();
                break;
            case 7:
                mostrarDatosAlumno(alumnos);
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