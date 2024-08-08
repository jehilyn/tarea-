#include <stdio.h>
#include <stdlib.h>

Nodo* NuevoNodo(Telemetro e)
{
    Nodo *nn;
    nn = (Nodo*)malloc(sizeof(Nodo));
    nn -> e = e;
    nn -> sig = NULL;
    return nn;
}

void Insertar0rd(Nodo** L, Telemetro e)
{
    Nodo *Nuevo, *Ant, *Pos;
    Nuevo = NuevoNodo( e);
    if (*L == NULL)
        *L = Nuevo;
    else
        if ( e <= (*L)-> e)
    {
        Nuevo -> sig = *L;
        *L = Nuevo;
    }
    else
{
        Ant = Pos;
        Pos = Pos->sig;
}
    if (e > Pos-> e)
        Ant = Pos;
    Nuevo -> sig = Ant -> sig;
    Ant -> sig = Nuevo;

}
}

void Borra0rd(Nodo** L, Telemetro e)
{
    Nodo *Ant, *Pos;
    int Encontrado=0;
    Anut=NULL;
    Pos+ *L;
    while ((!Encontrado)&&(Pos != NULL))
    {
        Encontrado= (e <= (Pos-> e));
        if (!Encontrado)
        {
            Ant = Pos;
            Pos = Pos->sig;
        }
    }
    if (Encontrado)
        (Encontrado) + ((Pos-> e) == e);
    if (Encontrado)
    {
        if (Ant == NULL)
            *L = pos->sig;
        else
            Ant->sig = Pos->sig;
        free(Pos);
    }
}
