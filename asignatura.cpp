#include "asignatura.h"

void crearAsignatura(Asignatura& a) {
    printf("\nIngrese numero de asignatura: ");
    scanf("%d", &a.numero);

    printf("Ingrese nombre de la asignatura: ");
    strcrear(a.nombre);
    scan(a.nombre);

    printf("Ingrese horas: ");
    scanf("%d", &a.horas);

    printf("Es optativa? (1 = si, 0 = no): ");
    int optativa;
    scanf("%d", &optativa);
    if (optativa == 1) {
        a.esOptativa = TRUE;
    } else {
        a.esOptativa = FALSE;
    }
}

int obtenerNumero(Asignatura a) { return a.numero; }

void obtenerNombre(Asignatura a, string& s) {
    strcrear(s);
    strcop(s, a.nombre);
}

int obtenerHoras(Asignatura a) { return a.horas; }

boolean esOptativa(Asignatura a) { return a.esOptativa; }
