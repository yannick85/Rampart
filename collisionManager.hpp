#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      collisionManager                            *
//*** FONCTION : Contient les fonctions nécéssaires au       *
//***               calcul de collision                      *
//************************************************************

#include <SFML/Graphics.hpp>

#include "TirJoueur.hpp"
#include "Ship.hpp"
#include "TirBateau.hpp"
#include "AbstractMovingObject.h"

class CollisionManager
{
public :

    CollisionManager(sf::Vector2f window_size);//Constructeur

    bool testCollision(AbstractMovingObject obj1,AbstractMovingObject obj2);//Test la collision entre deux éléments

    bool testCollisionXShip(AbstractMovingObject obj);//Test la collision d'un bateau avec les frontières maritimes
    bool testCollisionYShip(AbstractMovingObject obj);

private :

    sf::Vector2f my_window_size; // Taille de la fenêtre
};

bool collision(sf::IntRect & a,sf::IntRect & b); // Collisions entre deux rectangles

#endif


