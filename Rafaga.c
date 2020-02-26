#include "Pantalla.h"
#include <stdlib.h>
#include <stdio.h>
#include "Disparo.h"
#include "Nave.h"
#include "Rafaga.h"

struct NodoRep
{
    Disparo disparo;
    struct NodoRep* sig;
};
typedef struct NodoRep * Nodo;
struct RafagaRep
{
    Nodo primero;
    Imagen imagen;
};

Rafaga RafagaCrea()
{
    Rafaga r = malloc(sizeof(struct RafagaRep));
    r->imagen=Pantalla_ImagenLee("Disparo.bmp",1);
    r->primero = malloc(sizeof(struct NodoRep));
    r->primero->sig = NULL;
    return r;
}
void RafagaLibera(Rafaga r)
{
    while(r->primero->sig !=NULL)
    {
        Nodo nodo=r->primero->sig;
        r->primero->sig=r->primero->sig->sig;
        DisparoLibera(nodo->disparo);
        free(nodo);
    }
    free(r->primero);
    free(r);
    Pantalla_ImagenLibera(r->imagen);
}
void RafagaInsertaDisparo(Rafaga r,Disparo d)
{
    Nodo aux = malloc( sizeof( struct NodoRep ) );
    aux->disparo= d;
    aux-> sig = r->primero->sig;
    r->primero->sig=aux;
}
void RafagaDibuja(Rafaga r)
{
    for(Nodo n=r->primero->sig; n!=NULL; n=n->sig) DisparoDibuja(n->disparo,r->imagen);
}
void RafagaMueve(Rafaga r)
{
    Nodo n=r->primero;
    while(n->sig!=NULL)
    {
        if (DisparoMueve(n->sig->disparo))
        {
            Nodo aux = n->sig;
            n->sig = n->sig->sig;
            DisparoLibera(aux->disparo);
            free(aux);
        }
        else n = n->sig;
    }
}
int RafagaChocaAste(Rafaga r, Aste a)
{
    Nodo n=r->primero;
    while ((n->sig!=NULL)&&(!DisparoChocaAste(n->sig->disparo,a))) n=n->sig;
    int aux= (n->sig!=NULL);
    if (aux)
    {
        Nodo auxi = n->sig;
        n->sig = n->sig->sig;
        DisparoLibera(auxi->disparo);
        free(auxi);
        free(a);
    }
    return aux;
}
