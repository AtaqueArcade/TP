#include "Nave.h"
#include "Pantalla.h"
#include "Rafaga.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Disparo.h"
#include "Aste.h"
int main(int argc, char **argv)
{

    Pantalla_Crea("Ataque Arcade", 640,480);
    Imagen fondo= Pantalla_ImagenLee("Fondo.bmp",0);
    Imagen gameover=Pantalla_ImagenLee("Gameover.bmp",0);
    Imagen imagenast = Pantalla_ImagenLee("Asteroide.bmp",1);
    Pantalla_ColorRelleno(0,0,0,255);
    Pantalla_ColorTrazo(255,255,255,255);
    Nave n = NaveCrea();
    Rafaga r=RafagaCrea();
    srand(time(NULL));
    srand(getpid());

    int nAste = 15;
    Aste aste[nAste];
    for(int i=0; i<nAste; i++) aste[i] = AsteCrea(imagenast);

    int puntos = 0;
    char cadena[10];
    int fin=0;
    int itera=0;
    while (Pantalla_Activa())
    {
        itera++;
        if (!fin)
        {
            NaveMueve(n);
            Disparo d = NaveDispara(n);
            if ((d!=NULL)&&(!(itera%4)))  RafagaInsertaDisparo(r,d);
            RafagaMueve(r);
            for(int i=0; i<nAste; i++)
            {
                AsteMueve(aste[i]);
                if (AsteMueve(aste[i]))
                {
                    AsteLibera(aste[i]);
                    aste[i] = AsteCrea(imagenast);
                }
                if (RafagaChocaAste(r,aste[i]))
                {
                    AsteLibera(aste[i]);
                    aste[i] = AsteCrea(imagenast);
                    puntos=puntos+10;
                }
                if (NaveChocaAste(n,aste[i])) fin = 1;
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE))fin = 1;
            }

        }
        Pantalla_DibujaImagen(fondo,0,0,640,480);
        NaveDibuja(n);
        RafagaDibuja(r);
        for(int i=0; i<nAste; i++) AsteDibuja(aste[i],imagenast);
        sprintf(cadena,"%d",puntos);
        Pantalla_DibujaTexto(cadena,10,8);
        if (fin)
        {
            Pantalla_DibujaImagen(gameover,0,0,640,480);
            Pantalla_DibujaTexto(cadena,320,379);
        }
        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }

    NaveLibera(n);
    RafagaLibera(r);
    for(int i=0; i<nAste; i++) AsteLibera(aste[i]);
    Pantalla_ImagenLibera(imagenast);
    Pantalla_ImagenLibera(fondo);
    Pantalla_Libera();
    return 0;
}

