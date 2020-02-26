#include "Pantalla.h"
#include <stdlib.h>
#include <stdio.h>
#include "Disparo.h"
#include "Aste.h"
struct DisparoRep
{
    int x,y;
};

Disparo DisparoCrea(int x,int y)
{
    Disparo m = malloc(sizeof(struct DisparoRep));
    m->x = x;
    m->y = y;
    return m;
}
void DisparoLibera(Disparo m)
{
    free(m);
}
void DisparoDibuja(Disparo m,Imagen i)
{
    Pantalla_DibujaImagen(i,m->x+2,m->y+30,5,20 );
}
int DisparoMueve(Disparo m)
{
    m->y-=15;
    return (m->y<0);
}
int DisparoChocaAste(Disparo m,Aste a)
{
    return AsteChoca(a, m->x,m->y);
}
