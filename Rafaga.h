#ifndef __RAFAGA_H
#define __RAFAGA_H

#include "Disparo.h"
#include "Nave.h"
/**
\mainpage La biblioteca rafaga está destinada a la lista enlazada de elementos disparo.
*/
/**
   \file Rafaga.h
   \brief
   El esquema básico para su uso consiste en lo siguiente:<br/><br/>
 <br/> &nbsp;&nbsp;&nbsp; Crea la lista de elementos en si.
 <br/> &nbsp;&nbsp;&nbsp; Carga una imagen común para todos los elementos.
  <br/> &nbsp;&nbsp;&nbsp; Introduce y hace uso de elementos disparo, al mismo tiempo que los libera cuando se dan ciertas condiciones.
 <br/> &nbsp;&nbsp;&nbsp; Llama a las funciones necesarias de la TDA "Disparo.h".
 */
/**
    \brief TDA Rafaga
 */
typedef struct RafagaRep * Rafaga;
/**
  \brief Crea la estructura Rafaga, carga la imagen usada para los elementos
*/
Rafaga RafagaCrea();
/**
  \brief Libera todos los elementos incluidos en la lista. Hace uso de la función DisparoLibera de "Disparo.h"
  \param r la estructura Rafaga
 */
void RafagaLibera(Rafaga r);
/**
  \brief Inserta elementos disparo en la estructura Rafaga
  \param r la estructura Rafaga
  \param d el elemento Disparo
 */
void RafagaInsertaDisparo(Rafaga r,Disparo d);
/**
  \brief Bucle que va dibujando los elementos de la estructura en pantalla. Usa la función DisparoDibuja de "Disparo.h"
  \param r la estructura Rafaga
 */
void RafagaDibuja(Rafaga r);
/**
  \brief Bucle que va desplazando los elementos de la estructura. Usa la función DisparoMueve de "Disparo.h"
  \param r la estructura Rafaga
 */
void RafagaMueve(Rafaga r);
/**
  \brief Bucle que va liberando los elementos de la estructura si impactan. Usa la función DisparoChoca de "Disparo.h"
  \param r la estructura Rafaga
  \param a el elemento Aste
 */
int RafagaChocaAste(Rafaga r, Aste a);
#endif
