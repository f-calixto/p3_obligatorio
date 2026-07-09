#include "previaturas.h"

void crear(Grafo &g)
{
    int i=0;
    for(i=0; i<N; i++)
    {
        for(int j =0; j<N; j++)
        {
            g[i][j] = FALSE;
        }
    }
}

boolean perteneceVertice(Grafo g, int u)
{
    if ((u >=0) && ( u<N))
        return TRUE;
    return FALSE;
}

boolean perteneceArista (Grafo g, int u, int v)
{
    if (perteneceVertice(g,u) && perteneceVertice(g,v))
        return g[u][v];
    else
        return FALSE;
}

// Precondición: la arista no pertenece al grafo
void insertarArista (Grafo &g, int u, int v)
{
    g[u][v] = TRUE;
}


// Precondición: el vértice pertenece al grafo.
void gradoVertice (Grafo g, int u)
{
    int cantHabilita = 0;
    int cantPrevias = 0;
    for (int i =0; i<N; i++)
    {
        if (g[u][i] == TRUE)
            cantHabilita ++;
        else
            cantPrevias ++;
    }
    printf("Asignatura %d -> cantidad de asiganturas previas: %d | cantidad de asignaturas que habilita: %d\n", u, cantPrevias, cantHabilita);
}



void dfs (Grafo g, int actual, int destino, boolean visitados[N], boolean encontrado)
 {
    
      encontrado = FALSE;
     visitados[actual] = TRUE;
    
     if (actual == destino)
    {
        encontrado = TRUE;
    }
    else
    {
        for (int i = 0; i< N && !encontrado; i++)
        {
            if (g[actual][i] == TRUE && !visitados[i])
            {
                dfs(g, i, destino, visitados, encontrado);
            }
        }
    }
}


// Precondición: v y u pertenecen al grafo.
// determina si v es olbigatoria para cursar u
boolean hayCamino (Grafo g, int v, int u)
{
    boolean visitados[N];
    for (int i = 0; i < N; i++)
    {
        visitados[i] = FALSE;
    }
    boolean encontrado = FALSE;
    dfs(g, v, u, visitados, encontrado);
    return encontrado;
}

// Precondición: u pertenence al grafo
//imrpimre por pantalla la lista d los numeros de las asignaturas previas a u
void listarPreviaturas(Grafo g, int u)
{
    boolean tienePrevias = FALSE;
    for (int i=0; i<N; i++)
    {
        if (g[i][u] == TRUE)
        {
            printf("%d ", i);
            tienePrevias = TRUE;
        }
        else
        {
            if (!tienePrevias)
                printf("\n La asignatura %d NO tiene previaturas\n", i);
        }

    }
}


// Precondición: u pertenece al grafo.
// Carga en el arreglo "res" todos los números de materias que son previas de u ,
void obtenerPrevias (Grafo g, int u, int res[], int &cant)
 {
    cant = 0;
    for (int i = 0; i < N; i++)
    {
        if (g[i][u] == TRUE)
        {
            res[cant] = i;
            cant++;
        }
    }
 }

