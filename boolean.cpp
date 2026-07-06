#include "boolean.h"


void cargarboolean (boolean &b)
{
    int valor;
    printf ("Ingrese 0 si es FLASE y 1 si es TRUE: ");
    scanf ("%d", &valor);
    if (valor == 0)
        b = FALSE;
    else
        b = TRUE;
}

void mostrarboolean (boolean b)
{
    if (b)
        printf ("verdadero");
    else
        printf ("falso");
}
