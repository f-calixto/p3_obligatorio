#include "boolean.h"

void cargarBoolean(boolean& b) 
{
    int valor;
    printf("Ingrese 0 para FALSE o 1 para TRUE: ");
    scanf("%d", &valor);

    if (valor == 1) {
        b = TRUE;
    } else {
        b = FALSE;
    }
}

void mostrarBoolean(boolean b)
{
    if (b == TRUE) {
        printf("TRUE");
    } else {
        printf("FALSE");
    }
}
