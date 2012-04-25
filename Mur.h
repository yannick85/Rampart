#ifndef MUR_H_INCLUDED
#define MUR_H_INCLUDED

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      Mur                                         *
//*** FONCTION : Un mur plac� par le joueur                  *
//*** NOTES :    H�rite de AbstractCaseObject                *
//************************************************************

#include <iostream>
#include <SFML/graphics.hpp>
#include "AbstractCaseObject.h"


class Mur: public AbstractCaseObject
{
    private :
        bool detruit;//Represente l'�tat du mur

    public :

        Mur(); //Constructeur


        void selectSpriteAboutPosition(); //Choix du sprite (normal ou rouge) selon la position du mur


        virtual void setFixe(); //On red�finit la m�thode setFixe
        virtual std::string getType(); //On red�finit �galement getType

        void detruire();//Passe detruite a true , passe le sprite a rouge
        bool estDetruit();//renvoie l'�tat de d�truit

        sf::Vector2f getPos();

};


#endif // MUR_H_INCLUDED
