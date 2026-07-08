#include "fecha.h"

void cargarFecha(Fecha& fecha) {
    printf("\n Ingrese dia, mes y año");
    printf("\n");

    scanf("%d", &fecha.dia);
    scanf("%d", &fecha.mes);
    scanf("%d", &fecha.anio);
}

void mostrarFecha(Fecha fecha) {
    printf("(%d/%d/%d)", fecha.dia, fecha.mes, fecha.anio);
}

int obtenerDia(Fecha fecha) { return fecha.dia; }

int obtenerMes(Fecha fecha) { return fecha.mes; }

int obtenerAnio(Fecha fecha) { return fecha.anio; }

boolean esValida(Fecha fecha) {
    if (fecha.dia > 31 || fecha.mes > 12 || fecha.dia < 1 || fecha.anio < 1) {
        return FALSE;
    }

    if (fecha.anio % 4 != 0 && fecha.dia > 28 && fecha.mes == 2) {
        return FALSE;
    }

    return TRUE;
}

boolean esIgualOMayor(Fecha f1, Fecha f2) {
    if (f1.anio == f2.anio && f1.mes == f2.mes && f1.dia == f2.dia)
        return TRUE;  // igual

    if (f1.anio > f2.anio) {
        return TRUE;
    } else if (f1.anio < f2.anio) {
        return FALSE;
    }

    if (f1.mes > f2.mes) {
        return TRUE;
    } else if (f1.mes < f2.mes) {
        return FALSE;
    }

    if (f1.dia > f2.dia) {
        return TRUE;
    } else {
        return FALSE;
    }
}