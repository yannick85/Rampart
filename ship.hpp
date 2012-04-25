#ifndef SHIP_H
#define SHIP_H

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      Ship                                        *
//*** FONCTION : Un bateau                                   *
//*** NOTES :    Hérite de AbstractMovingObject              *
//************************************************************

#include <SFML/Graphics.hpp>
#include "AbstractMovingObject.h"

class Ship  : public AbstractMovingObject
{
public :

    Ship(sf::Vector2f position, int size_ver,int size_hor, float speed);//ctor

    void move();//fait bouger le bateau

    sf::Vector2f getPos();//Renvoie la position du sprite
    void setPos(sf::Vector2f new_pos);//Donne une nouvelle position au bateau

    bool getPretATirer();//connaitre l'état du tir du bateau
    void tirFini();//appeler quand le tir est arrivé a destination
    void CommencerTir();//appeler quand on fait tirer le bateau;
    bool toucher();//appeller quand le bateau ets touché par un tir , renvoie vrai si le bateau coule

private :

    int point_de_vie;//Nombre de point de vie
    int my_size_ver; // Taille
    int my_size_hor; // Taille
    float my_dx; // Déplacement en X
    float my_dy; // Déplacement en Y
    float my_speed; // Vitesse
    bool pret_a_tirer;//Indique si le bateau est pret a tirer
};

#endif
