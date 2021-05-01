#ifndef GRID_H
#define GRID_H

/*!
  * \file grid.h
  * \brief Grille du jeu
  * \author Mélina MAHE
  */

#include<algorithm>
#include <ctime>
#include <vector>
#include<fstream>
#include"player.h"
using namespace std;

/*!
 * \class Grid
 * \brief la classe représentant la grille de jeu
 */
class Grid
{
    int itsSize;/*!< La taille de la grille*/
    vector<vector<State>> itsGrid;/*!< la grille*/
public:
    /*!
     * \brief constructeur de la classe Grid
     * \param size : la Taille de la grille
     */
    Grid(int size);
    /*!
     * \brief modifie la taille de la grille
     * \param size : la taille de la grille
     */
    void setSize(int size);
    /*!
     * \brief donne la taille de la grille
     * \return la taille de la grille
     */
    int getItsSize();
    /*!
     * \brief donne la grille de jeu
     * \return la grille de jeu
     */
    bool getItsGrid();
    /*!
     * \brief affiche la grille de jeu
     */
    void displayGrid();
    /*!
     * \brief initialise la grille de jeu
     */
    void initGrid();
    /*!
     * \brief efface le terminal
     */
    void clearScreen();
    /*!
     * \brief vérifie que les coordonnées soient juste
     * \param coord :  les coordonnées à vérifier
     * \return vrai si les coordonnéees sont valides, sinon return false
     */
    bool checkCoord(string coord);
    /*!
     * \brief place le pion sur la grille
     * \param coord :  les coordonées où le pion doit être changé
     * \param type :  le type de pion à placer
     */
    void placePion(string coord, State type);
    /*!
     * \brief choisi des coordonnées pour l'IA
     * \return les coordonnées pour l'IA
     */
    string IAcase();
    /*!
     * \brief sauvegarde les coups dans un fichier
     * \param coord : les coordonnées à mettre dans le fichier
     * \param type :  le type de pion qui a été jouer
     */
    void save(string coord, State type);
    /*!
     * \brief vérifie si un des joueurs gagne
     * \param Coord : les coordonnées du joueur
     * \param player :  le joueur qui a peut-être gagné
     * \return true si un joueur gagne ou si il y a match null, sinon return false
     */
    bool checkWin(string Coord, Player player);
};

#endif // GRID_H
