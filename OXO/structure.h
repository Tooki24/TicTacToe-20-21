#ifndef STRUCTURE_H
#define STRUCTURE_H

/*!
  *\file structure.h
  * \brief les structures
  * \author Mélina MAHE
  */
#include <iostream>
using namespace std;
#endif // STRUCTURE_H



/*!
  *\enum State
 * \brief enum des différents états d'une case et des pions
 */
enum State{
    VOID='-',/*!< la case est vide*/
    CROSSES='X',/*!< le pion croix / la case est remplie d'un pion croix*/
    CIRCLES='O'/*!< le pion cercle / la case est remplie d'un pion cercle*/
};

/*!
  *\enum Type
 * \brief enum des différents type de joueur
 */
enum Type{
    HUMAN='H', /*!< le joueur humain*/
    IA='I' /*!< le joueur robot*/

};

