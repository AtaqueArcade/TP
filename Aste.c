#include "Pantalla.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Aste.h"
#include "disparo.h"


struct AsteRep
{
    int x;
    int y;
    int v;
    int hitboxa;
    int hitboxb;
};

Aste AsteCrea(Imagen i)
{
    Aste a = malloc(sizeof(struct AsteRep));
    a->x=rand()%605;
    a->y=0;
    a->v = 3+rand()%10;

    return a;
}
void AsteLibera(Aste a)
{
    free(a);
}
void AsteDibuja(Aste a, Imagen imagen)
{
    Pantalla_DibujaImagen(imagen,a->x,a->y,35,35);
}
int AsteMueve(Aste a)
{
    a->y+=a->v;
    return (a->y>445);

}
int AsteChoca(Aste a,int x,int y)
{
    return (sqrt(pow(a->x-x,2)+pow(a->y-y,2))<30);
}
