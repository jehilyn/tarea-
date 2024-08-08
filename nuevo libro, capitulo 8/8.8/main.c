#include <stdio.h>
#include <stdlib.h>

struct lista
{
int x;
struct lista *Sig;
};
typedef struct lista Lista;
void ordena(Lista **L, int n)
{
int i, j;
Lista *Auxiliar, *Auxiliar1, *Anterior;
for (i = 1 ;i < n; i++)
{
j = 1;
Auxiliar = *L;
Anterior = NULL;
while (j <= (n - i))
{
Auxiliar1 = Auxiliar->Sig;
if (Auxiliar->x > Auxiliar1->x)
{
Auxiliar->Sig = Auxiliar1->Sig;
Auxiliar1->Sig = Auxiliar;
if (Anterior == NULL)
{*L = Auxiliar1;
Anterior = *L;
}
else
{
Anterior->Sig = Auxiliar1;
Anterior = Auxiliar1;
}
Auxiliar = Anterior->Sig;
}
else
{
Anterior = Auxiliar;
Auxiliar = Auxiliar1;
}
j ++;
}
}
}
