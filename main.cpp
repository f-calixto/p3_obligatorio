#include "alumnos.h"
#include "asignaturas.h"

void mostrarMenu() {
    print("Ingrese un numero de operacion:\n");
    print("1: Registrar nueva asigantura\n");
    print("2: Agregar previatura entre 2 asignaturas\n");
    print("3: Inscribir alumno\n");
    print("4: Registrar curso finalizado\n");
    print("5: Listar todas las asignaturas\n");
    print("6: Listar previas de asignaturas\n");
    print("7: Mostrar datos de alumno\n");
    print("8: Mostrar escolaridad de alumno\n");
    print("9: Salir del programa\n");
}

int main() {
    boolean continuar = TRUE;

    while (continuar) {
        int operacion;

        mostrarMenu();
        printf("\nIngrese numero de operacion (1-8 o 9 para salir): ");
        scanf("%d", &operacion);

        switch (operacion) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
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