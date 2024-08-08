#include <stdio.h>
#include <stdlib.h>

int NumeroDeNodosDeLaLista(Nodo *L)
{
    int k = 0;
    Nodo *p;
    p = L;
    while (p != NULL)
    {
        k++;
        p = p->sig;
    }
    return(k);
}

void EliminaPosicion (Nodo** L, int i)
{
    int k = 0;
    Nodo *Ptr, *Ant;
    Ptr = *L;
    Ant = NULL;
    while ((k < i) && (Ptr != NULL))
    {
        k++;
        Ant = Ptr;
        Ptr = Ptr->sig;
    }
    if(k == i)
    {
        if(Ant == NULL)
            *L = Ptr->sig;
        else
            Ant->sig = Ptr->sig;
        free(Ptr);
    }
}

void InsertarLista(Nodo* Ant, Telemetro e)
{
    Nodo *Nuevo;
    Nuevo = (Nodo*)malloc(sizeof(Nodo));
    Nuevo -> e = e;
    Nuevo -> sig = Ant -> sig;
    Ant = sig = Nuevo;
}
Nodo* BuscarEnLista (Nodo* L, Telemetro e)
{
    Nodo *Ptr;
    for (Ptr = L; Ptr != NULL; Ptr = Ptr ->sig )
        if (Ptr-> e == e)
            return Ptr;
    return NULL;
