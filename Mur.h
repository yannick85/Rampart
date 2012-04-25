#ifndef MUR_H_INCLUDED
#define MUR_H_INCLUDED

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      Mur                                         *
//*** FONCTION : Un mur placé par le joueur                  *
//*** NOTES :    Hérite de AbstractCaseObject                *
//************************************************************

#include <iostream>
#include <SFML/graphics.hpp>
#include "AbstractCaseObject.h"


class Mur: public AbstractCaseObject
{
    private :
        bool detruit;//Represente l'état du mur

    public :

        Mur(); //Constructeur


        void selectSpriteAboutPosition(); //Choix du sprite (normal ou rouge) selon la position du mur


        virtual void setFixe(); //On redéfinit la méthode setFixe
        virtual std::string getType(); //On redéfinit également getType

        void detruire();//Passe detruite a true , passe le sprite a rouge
        bool estDetruit();//renvoie l'état de détruit

        sf::Vector2f getPos();

};


#endif // MUR_H_INCLUDED
