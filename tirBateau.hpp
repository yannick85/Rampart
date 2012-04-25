#ifndef TIRBATEAU_H
#define TIRBATEAU_H

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      Canon                                       *
//*** FONCTION : Un canon placé par le joueur                *
//*** NOTES :    Hérite de AbstractCaseObject                *
//************************************************************

#include <SFML/Graphics.hpp>
#include "ship.hpp"
#include "Mur.h"
#include "AbstractMovingObject.h"

class TirBateau  : public AbstractMovingObject
{
public :

    TirBateau(sf::Vector2f position, int size_ver,int size_hor, float speed , sf::Vector2f aim,Ship *bateau,Mur *mur);//Constr

    bool move();//Fait bouger le sprite
    void detruireMur();//Detruit de mur associé

private :

    sf::Vector2f my_aim;//Objectif du tir
    int my_size_ver; // Taille
    int my_size_hor; // Taille
    float my_dx; // Déplacement en X
    float my_dy; // Déplacement en Y
    float my_speed; // Vitesse
    float distance_x;
    float distance_y;
    Ship *bateau_lie;//Bateau origine
    Mur *mur_lie;//Mur objectif
};


#endif
