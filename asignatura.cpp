#include "asignatura.h"

void crearAsignatura(Asignatura& a) {
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

void asignarNumero(Asignatura& a, int nro) { a.numero = nro; }

void mostrarAsignatura(Asignatura a) {
    printf("    Nombre: ");
    print(a.nombre);
    printf("\n    Nro: %d\n    Horas: %d", a.numero, a.horas);
    print("\n    Es optativa: ");
    if (a.esOptativa) {
        print("Si");
    } else {
        print("No");
    }
}