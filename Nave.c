#include "Pantalla.h"
#include <stdlib.h>
#include "Nave.h"
#include <time.h>

struct NaveRep
{
    Imagen imagen;
    int x;
};

Nave NaveCrea()
{
    Nave n = malloc(sizeof(struct NaveRep));
    n->x = 240;
    n->imagen=Pantalla_ImagenLee("Nave.bmp",1);
    return n;
}
void NaveLibera(Nave n)
{
    Pantalla_ImagenLibera(n->imagen);
    free(n);
}
void NaveDibuja(Nave n)
{
    Pantalla_DibujaImagen(n->imagen,n->x,420,45,45);
}
void NaveMueve(Nave n)
{
    if ((Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT))&&(n->x>10)) n->x-=10;
    if ((Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT))&&(n->x<590)) n->x+=10;
}

Disparo NaveDispara(Nave n)
{
    if (Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE))
    {
        return DisparoCrea(n->x+18,378);
    }
    else return NULL;

}

int NaveChocaAste(Nave n, Aste a)
{
    return AsteChoca(a,n->x,420);
}
