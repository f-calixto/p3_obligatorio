#include "menu.h"

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

void registrarAsignatura(Asignaturas &asignaturas) 
{
    if (asignaturas.tope >= MAX_ASIG)
    {
        printRojo("Error: Se ha alcanzado el tope maximo de asignaturas en el sistema.\n\n");
        return; //se usa para que el resto de la función NO se ejecute
    }
        
    Asignatura nueva;
    crearAsignatura(nueva);
    
    int nro = obtenerNumero(nueva);
    
    if (member(asignaturas, nro))
    {
        printRojo("Error: Ya existe una asignatura registrada con ese numero.\n\n");
    } 
    else 
    {
        insert(asignaturas, nueva);
        printVerde("Asignatura registrada correctamente en el sistema.\n\n");
    }
}

void agregarPreviatura(Previaturas &previaturas, Asignaturas asignaturas) 
{
    int u, v;
    print("Ingrese el numero de la asignatura PREVIA (u): ");
    scanf("%d", &u);
    print("Ingrese el numero de la asignatura DESTINO (v): ");
    scanf("%d", &v);

    // Validación A: Que ambas existan en el sistema
    if (!member(asignaturas, u) || !member(asignaturas, v))
    {
        printRojo("Error: Al menos una de las asignaturas especificadas no esta registrada.\n\n");
        return; //se usa para que el resto de la función NO se ejecute
    }

    // Validación B: Que no sean la misma asgnatura
    if (u == v)
    {
        printRojo("Error: Una asignatura no puede ser previatura de si misma.\n\n");
        return;
    }

    // Validación C: Evitar previaturas duplicadas
    if (perteneceArista(previaturas, u, v)) 
    {
        printRojo("Error: Esta relacion de previatura ya se encuentra registrada.\n\n");
        return; //se usa para que el resto de la función NO se ejecute
    }

    // Validación D: CONTROL DE CICLOS. Si ya hay camino de v a u, agregar u -> v generará un ciclo 
    if (hayCamino(previaturas, v, u))
    {
        printRojo("Error Invalido: No se puede agregar la previatura porque generaria un ciclo en el plan de estudios.\n\n");
    }
    else 
    {
        insertarArista(previaturas, u, v);
        printVerde("Previatura directa agregada de forma exitosa.\n\n");
    }


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

void listarPrevias(Previaturas previaturas, Asignaturas asignaturas)
{
    int numAsig;
    print("Ingrese el numero de la asignatura para conocer sus previas: ");
    scanf("%d", &numAsig);

    // Validación: que la asignatura destino exista
    if (!member(asignaturas, numAsig)) 
    {
        printRojo("Error: La asignatura especificada no existe en el sistema.\n\n");
        return;
    }

    boolean tienePrevias = FALSE;
    Asignatura asigActual = find(asignaturas, numAsig);
    string nombreDestino;
    obtenerNombre(asigActual, nombreDestino);

    printf("\n--- TODAS LAS PREVIAS DE: ");
    print(nombreDestino);
    printf(" (Nro: %d) ---\n", numAsig);


    for (int i = 0; i < N; i++) 
    {
        if (i != numAsig && member(asignaturas, i))
        {
            if (hayCamino(previaturas, i, numAsig))
            {
                Asignatura previa = find(asignaturas, i);
                string nomPrevia;
                obtenerNombre(previa, nomPrevia);
                
                printf("- Numero: %d | Nombre: ", i);
                print(nomPrevia);
                printf("\n");
                tienePrevias = TRUE;
            }
        }
    }

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


void mostrarEscolaridadAlumno(Alumnos alumnos, Asignaturas asignaturas)
{
    int ci;
    print("Ingrese la cedula del alumno para desplegar su escolaridad: ");
    scanf("%d", &ci);

    // Validación: Que el estudiante exista en la tabla hash
    if (!member(alumnos, ci))
    {
        printRojo("Error: El alumno con la cedula ingresada no esta registrado.\n\n");
        return;
    }

    Alumno al = find(alumnos, ci);
    string nom, ape;
    obtenerNombre(al, nom);
    obtenerApellido(al, ape);

    printf("\n========================================================\n");
    printf("ESCOLARIDAD HISTORICA CRONOLOGICA DE: );
    print(nom);
    print(ape);
    printf("ci: %d", ci);
    printf("========================================================\n");

    Escolaridad esc = obtenerEscolaridad(al);

    if (esVacia(esc)) 
    {
        printf("El alumno no registra cursos realizados hasta la fecha.\n");
    } 
    else 
    {
        int cantCursos = largo(esc);
        // Como insBack asegura que las fechas ingresadas sean cronológicas,
        // recorremos la lista mediante kEsimo desde 1 hasta el largo de la secuencia
        for (int k = 1; k <= cantCursos; k++) 
        {
            Curso cursoNodoK = kEsimo(esc, k);
            int nroMateria = obtenerNumAsignatura(cursoNodoK);
            
            string nombreMateria;
            obtenerNombreAsigantura(cNode, nombreMateria);
            
            printf("Curso %d:\n", k);
            printf("  - Asignatura: [%d] ", nroMateria);
            print(nombreMateria);
            printf("\n  - Fecha Fin: ");
            mostrarFecha(obtenerFechaFin(cursoNodoK));
            printf("\n  - Calificacion: %d", obtenerNota(cursoNodoK));
            
            // Verificamos si aprobó 
            if (estaAprobado(cursoNodoK))
            {
                printVerde(" -> [APROBADA]\n");
            } 
            else 
            {
                printRojo(" -> [REPROBADA]\n");
            }
            printf("--------------------------------------------------------\n");
        }
    }
    printf("========================================================\n\n");
}
