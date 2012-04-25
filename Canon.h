#ifndef CANON_H_INCLUDED
#define CANON_H_INCLUDED

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      Canon                                       *
//*** FONCTION : Un canon plac� par le joueur                *
//*** NOTES :    H�rite de AbstractCaseObject                *
//************************************************************

#include <iostream>
#include <SFML/graphics.hpp>
#include "AbstractCaseObject.h"

#include <vector>


class Canon: public AbstractCaseObject
{
    private :

        bool pret_a_tirer;//represente l'�tat du canon , faux quand il a un tir actif , vrai quand il est dispo
        bool actif;//faux si le canon est en zone prot�g� , vrai sinon
        sf::Sprite sprite_viseur;//sprite du viseur
        sf::Image *image_viseur;//image du viseur
        // le sprite et l'image de la base du canon sont elles h�rit�s

    public :

        Canon(); //Constructeur

        bool validPosition(); //Onn red�finit la m�thode validPosition
        void selectSpriteAboutPosition(); //Choix du sprite (normal ou rouge) selon la position du canon

        sf::Vector2f getPos();

        void verifActif();//le canon verifie sa position pour savoir si il est actif ou non
        bool isActif();//savoir si le canon est actif
        bool isPretATirer();//connaitre l'�tat du tir du canon
        void tirFini();//appeler quand le tir est arriv� a destination
        void CommencerTir();//appeler quand on fait tirer le canon;

        void tournerViseur(int souris_x,int souris_y);//appeler lorsque le canon est actif et que l'on bouge la souris
        void displayCanon(sf::RenderWindow &ecran);//affiche canon au moment de son placement

        virtual void setFixe(); //On red�finit la m�thode setFixe
        virtual std::string getType(); //On red�finit �galement getType

        sf::Sprite getSpriteViseur();//renvoie le sprite du viseur

};

#endif // CANON_H_INCLUDED
