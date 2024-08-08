#include <stdio.h>
#include <stdlib.h>

void MezclarListasOrdenadas(Nodo *L1, Nodo *L2, Nodo **L3)
{
    Nodo *Puntero1,*Puntero2,*Primero,*Ultimo, *NodoNuevo;
    NodoNuevo = NuevoNodo(-32767);
    Primero = NodoNuevo;
    Ultimo = NodoNuevo;
    Puntero1 = L1;
    Puntero2 = L2;
    while (Puntero1 && Puntero2)
        if (Puntero1->e < Puntero2->e)
        {
            NodoNuevo = NuevoNodo(Puntero1->e);
            Ultimo->Sig = NodoNuevo;
            Ultimo = NodoNuevo;
            Puntero1 = Puntero1->Sig;
        }
        else
        {
            NodoNuevo = NuevoNodo(Puntero2->e);
            Ultimo->Sig = NodoNuevo;
            Ultimo = NodoNuevo;
            Puntero2 = Puntero2->Sig;
        }
        while(Puntero1)
        {
            NodoNuevo = NuevoNodo(Puntero1->e);
            Ultimo->Sig = NodoNuevo;
            Ultimo = NodoNuevo;
            Puntero1 = Puntero1->Sig;

            while(Puntero2)
            {
                NodoNuevo = NuevoNodo(Puntero2->e);
                Ultimo->Sig = NodoNuevo;
                Ultimo = NodoNuevo;
                Puntero2 = Puntero2->Sig;
            }
            L3 = Primero->sig;
            free(Primero);
        }
