#ifndef TIRJOUEUR_H
#define TIRJOUEUR_H

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      TirJoueur                                   *
//*** FONCTION : un tir originaire d'un canon                *
//*** NOTES :    Hérite de AbstractMovingObject              *
//************************************************************

#include <SFML/Graphics.hpp>
#include "AbstractMovingObject.h"
#include "Canon.h"

class TirJoueur : public AbstractMovingObject
{
public :

    TirJoueur(sf::Vector2f position, int size_ver,int size_hor, int speed , sf::Vector2f aim , Canon *canon);//Constructeur

    bool move();//fait bouger le sprite et vérifie sa position par rapport a l'objectif

private :

    //sf::Vector2f my_position;
    sf::Vector2f my_aim;//Objectif : coordonnee du clic
    int my_size_ver; // Taille
    int my_size_hor; // Taille
    float my_dx; // Déplacement en X
    float my_dy; // Déplacement en Y
    int my_speed; // Vitesse
    float distance_x;//distance en l'origine et l'objectif
    float distance_y;
    Canon *canon_lie;//Pointeur vers le Canon d'origine
};


#endif
