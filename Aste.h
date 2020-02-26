#ifndef __ASTE_H
#define __ASTE_H

#include "Pantalla.h"
/**
\mainpage La biblioteca aste está destinada a las funciones de un elemento Aste.
*/
/**
   \file Aste.h
   \brief  Permite  la creación del elemento Aste, el principal obstaculo del juego.
   El esquema básico para su uso consiste en lo siguiente:<br/><br/>
 <br/> &nbsp;&nbsp;&nbsp; Carga el elemento aste en un array en el principal, junto con una imagen común para todos los elementos.
 <br/> &nbsp;&nbsp;&nbsp; Muestra el elemento en pantalla.
  <br/> &nbsp;&nbsp;&nbsp; Se desplaza el elemento. Se analiza si ha impactado tanto con un elemento nave como un elemento disparo.
 <br/> &nbsp;&nbsp;&nbsp; Se analiza si ha impactado tanto con un elemento nave como un elemento disparo.
 */
/**
    \brief TDA Aste
 */
typedef struct AsteRep * Aste;
/**
  \brief Crea el elemento Aste.
    \param i Imagen cargada en el principal, comun para todo el array de elementos aste
*/
Aste AsteCrea(Imagen i);
/**
  \brief Libera la memoria reservada para el aste
  \param a El elemento Aste
 */
void AsteLibera(Aste a);
/**
  \brief Muestra el aste en la pantalla
  \param a El elemento Aste
 */
void AsteDibuja(Aste a, Imagen imagen);
/**
  \brief Desplaza el elemento verticalmente
  \param a El elemento Aste
 */
int AsteMueve(Aste a);
/**
  \brief Analiza si un elemento con posición x e y ha impactado con el elemento aste
  \param a El elemento Aste
  \param x Posición horizontal del elemento que ha impactado
  \param y Posición vertical del elemento que ha impactado
 */
int AsteChoca(Aste a,int x, int y);
#endif

