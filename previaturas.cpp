#include "previaturas.h"

void crear(Previaturas& g) {
    int i = 0;
    for (i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            g[i][j] = FALSE;
        }
    }
}

boolean perteneceVertice(Previaturas g, int u) {
    boolean pertenece = FALSE;
    if ((u >= 0) && (u < N)) pertenece = TRUE;
    return pertenece;
}

boolean perteneceArista(Previaturas g, int u, int v) {
    boolean pertenece = FALSE;

    if (perteneceVertice(g, u) && perteneceVertice(g, v)) pertenece = TRUE;

    return pertenece;
}

// Precondición: la arista no pertenece al Previaturas
void insertarArista(Previaturas& g, int u, int v) { g[u][v] = TRUE; }

// Precondición: el vértice pertenece al Previaturas.
int gradoVertice(Previaturas g, int u) {
    int cantAristas = 0;

    for (int i = 0; i < N; i++) {
        if (g[u][i] == TRUE || g[i][u] == TRUE) cantAristas++;
    }

    return cantAristas;
}

void dfs(Previaturas g, int actual, int destino, boolean visitados[N],
         boolean& encontrado) {
    encontrado = FALSE;
    visitados[actual] = TRUE;

    if (actual == destino) {
        encontrado = TRUE;
    } else {
        int i = 0;
        while (i < N && !encontrado) {
            if (g[actual][i] == TRUE && !visitados[i]) {
                dfs(g, i, destino, visitados, encontrado);
            }
            i++;
        }
    }
}

// Precondición: v y u pertenecen al Previaturas.
// determina si v es olbigatoria para cursar u
boolean hayCamino(Previaturas g, int u, int v) {
    boolean visitados[N];
    for (int i = 0; i < N; i++) {
        visitados[i] = FALSE;
    }
    boolean encontrado = FALSE;
    dfs(g, u, v, visitados, encontrado);
    return encontrado;
}

// Precondición: u pertenece al Previaturas.
// Carga en el arreglo "res" todos los números de materias que son previas de u
void obtenerPreviasInmediatas(Previaturas g, int u, int res[N], int& cant) {
    cant = 0;
    for (int i = 0; i < N; i++) {
        if (g[u][i] == TRUE) {
            res[cant] = i;
            cant++;
        }
    }
}
