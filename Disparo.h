#ifndef __DISPARO_H
#define __DISPARO_H
#include "Pantalla.h"
#include "Aste.h"
/**
\mainpage La biblioteca disparo está destinada a las funciones de un elemento Disparo.
*/
/**
   \file Disparo.h
   \brief  Permite la creación del elemento Disparo así como su análisis y uso. Notese que esta TDA esta dedicada unicamente al elemento Disparo. Para ver su estructura enlazada ver: "Rafaga.h"
   El esquema básico para su uso consiste en lo siguiente:<br/><br/>
 <br/> &nbsp;&nbsp;&nbsp; Carga el elemento disparo con sus propiedades.
  <br/> &nbsp;&nbsp;&nbsp; Modifica como se muestra en la patalla.
 <br/> &nbsp;&nbsp;&nbsp; Detecta si colisiona con un elemento Aste.
 */
/**
    \brief TDA Disparo
 */
typedef struct DisparoRep * Disparo;
/**
  \brief Crea el elemento Disparo.
  \param x Posición del disparo en el eje (se obtiene de la función NaveDispara de "Nave.h")
  \param y Posición del disparo en el eje y
*/
Disparo DisparoCrea(int x,int y);
/**
  \brief Libera la memoria reservada para el disparo
  \param m El elemento Disparo
 */
void DisparoLibera(Disparo m);
/**
  \brief Muestra el disparo en la pantalla con i como su imagen. (Esto se obtiene de "Rafaga.h", para que todos los disparos usen la misma imagen y asi no se desperdicie memoria)
  \param m El elemento Disparo
  \param i La imagen empleada
 */
void DisparoDibuja(Disparo m,Imagen i);
/**
  \brief Desplaza el disparo verticalmente
  \param m El elemento Disparo
 */
int DisparoMueve(Disparo m);
/**
  \brief Indica si el disparo ha chocado con un asteroide
  \param d El elemento Disparo
  \param a El elemento Aste
 */
int DisparoChocaAste(Disparo d, Aste a);

#endif
