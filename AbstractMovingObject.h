#ifndef ABSTRACTMOVINGOBJECT_H
#define ABSTRACTMOVINGOBJECT_H

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      AbstractMovingObject                         *
//*** FONCTION : Classe mère des objets tirJoueur, tirBateau, *
//***            et ship                  *
//************************************************************

#include <SFML/Graphics.hpp>


class AbstractMovingObject
{
    public:
        AbstractMovingObject();//constr

        sf::Sprite getSprite();//Renvoie le sprite de l'objet

        sf::IntRect getBoundingBox();//Renvoie un rectangle entourant le sprite de l'objet

    protected:

        sf::Image *image;//Image d'origine du sprite
        sf::Sprite my_sprite;//Sprite de l'objet
};

#endif // ABSTRACTMOVINGOBJECT_H
