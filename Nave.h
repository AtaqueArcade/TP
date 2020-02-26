#ifndef __NAVE_H
#define __NAVE_H

#include "Disparo.h"
#include "Aste.h"
/**
\mainpage La biblioteca nave está destinada a las funciones de un elemento Nave.
*/
/**
   \file Nave.h
   \brief  Permite la creación del elemento Nave así como su manipulación y control. Incluye las funciones necesarias para analizar su estado respecto a las mecánicas del juego.
   El esquema básico para su uso consiste en lo siguiente:<br/><br/>
 <br/> &nbsp;&nbsp;&nbsp; Carga el elemento nave con su imagen.
 <br/> &nbsp;&nbsp;&nbsp; Muestra el elemento en pantalla.
  <br/> &nbsp;&nbsp;&nbsp; Modifica como se muestra en la patalla en función de los evantos detectados.
 <br/> &nbsp;&nbsp;&nbsp; Devuelve datos sobre el elemento necesarios en otras TDAs.
 */
/**
    \brief TDA Nave
 */
typedef struct NaveRep * Nave;
/**
  \brief Crea el elemento Nave
*/
Nave NaveCrea();
/**
  \brief Libera la memoria reservada para la nave y sus recursos asociados
  \param n El elemento Nave
 */
void NaveLibera(Nave n);
/**
  \brief Muestra la nave en la pantalla
  \param n El elemento Nave
 */
void NaveDibuja(Nave n);
/**
  \brief Desplaza el elemento con su imagen y sus características segun las teclas pulsadas
  \param n El elemento Nave
 */
void NaveMueve(Nave n);
/**
  \brief Llama a la función de Disparo.h "DisparoCrea" con los datos necesarios del elemento Nave
  \param n El elemento Nave
 */
Disparo NaveDispara(Nave n);
/**
  \brief Indica si la nave ha chocado con un asteroide.
  \param n El elemento Nave
  \param a El elemento Aste
 */
int NaveChocaAste(Nave n, Aste a);
#endif

