#include <stdio.h>
#include <stdlib.h>

typedef int Telemetro;
typedef struct Registro
{
    Telemetro e;
    struct Registro* sig;
}Nodo;

void main(){}
void Vacial (Nodo **L)
{
    *L = NULL;
}

int EsVacial(Nodo * L)
{
    return(L == NULL);
}

void AnadePL(Nodo** L, Telemetro e)
{
    Nodo *Nuevo;
    Nuevo = (Nodo*)malloc(sizeof(Nodo));
    Nuevo -> e = e;
    Nuevo -> sig = *L;
    *L = Nuevo;
}
 void BorraPL (Nodo** L)
 {
     Nodo *Ptr;
     Ptr = *L;
     if(Ptr == NULL)
     {
         printf("error en BorraP");
         return;
     }
     *L = Ptr->sig;
     free(Ptr);
 }
 Nodo *Resto( Nodo *L)
 {
     if (L == NULL)
     {
         printf("error en restol \n");
         return NULL;
     }
     return L->sig;
 }

 void ModificaL(Nodo **L, Telemetro e)
 {
     if (L == NULL)
     {
         printf("error en ModificaL \n");
         return;
     }
     (*L)->e = e;
 }
 Telemetro Primerol (Nodo* L)
 {
     if (L == NULL)
     {
         printf("error en Primerol \n");
         return NULL;
     }
     return L->e;
 }
