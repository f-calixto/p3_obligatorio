#include "alumnos.h"
#include "asignaturas.h"

void mostrarMenu() {}

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
                printf("Saliendo del programa\n");
                break;
            default:
                printRojo("Numero de operacion invalida\n");
                break;
        }
    }

    return 0;
}