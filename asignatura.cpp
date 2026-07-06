#include "asignatura.h"

///Crea una asignatura a partir de sus componentes básicos
void crearAsignatura(Asignatura &a,int num, str nom, int hrs, boolean optativa)
{
    a.numero = num;
    strcop(a.nombre, nom);
    a.horas = hrs;
    a.esOptativa = optativa;
}



///Operación auxiliar para asignatura
void imprimirAsignatura(Asignatura a)
{
    printf("Numero: %d\n", a.numero);
    printf("Nombre: ");
    strprint(a.nombre);
    printf("\n");
    printf("Horas: %d\n", a.horas);

    if (a.esOptativa == TRUE) {
        printf("Tipo: Optativa\n");
    } else {
        printf("Tipo: Obligatoria\n");
    }
}



                ///SELECTORAS ASIGNATURA
int obtenerNumero(Asignatura a)
{
    return a.numero;
}

void obtenerNombre(Asignatura a, str &nom)
{
    strcop(nom, a.nombre);
}

int obtenerHoras(Asignatura a)
{
    return a.horas;
}

boolean esAsignaturaOptativa(Asignatura a)
{
    return a.esOptativa;
}
            ///SELECTORAS ASIGNATURA
