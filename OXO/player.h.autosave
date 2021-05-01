#ifndef PLAYER_H
#define PLAYER_H
 /*!
   *\file player.H
   * \brief un joueur
   *\author Mélina MAHE
   */
#include "structure.h"
/*!
  *\class Player
 * \brief la classe représentant un joueur
 */
class Player
{
private:
    /*!
     * \brief le nom du joueur
     */
    string itsName;
    /*!
     * \brief le pion du joueur
     */
    State itsState;
    /*!
     * \brief le type de joueur : robot ou humain
     */
    Type itsType;
public:
    /*!
     * \brief constructeur d'un joueur
     * \param name : le nom du joueur
     * \param type : le pion du joueur
     * \param state : l'état du joueur
     */
    Player(string name, Type type,State state);
    /*!
     * \brief change le nom du joueur
     * \param name : le nom du joueur
     */
    void setItsName(string name);
    /*!
     * \brief change le tpe de pion du joueur
     * \param aType : le type de pion du joueur
     */
    void setItsType(Type aType);
    /*!
     * \brief change l'état du joueur : robot ou humain
     * \param aState : l'état du joueur
     */
    void setItsState(State aState);
    /*!
     * \brief donne le nom du joueur
     * \return le nom du joueur
     */
    string getItsName();
    /*!
     * \brief donne le pion du joueur
     * \return le pion du joueur
     */
    State getItsState();
    /*!
     * \brief donne le type du joueur : robot ou humain
     * \return le type du joueur
     */
    Type getItsType();
};

#endif // PLAYER_H
