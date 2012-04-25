#ifndef ABSTRACTCASEOBJECT_H_INCLUDED
#define ABSTRACTCASEOBJECT_H_INCLUDED

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      AbstractCaseObject                          *
//*** FONCTION : Classe mère des objets Mur, Canon,          *
//***            Forteresse et CaseOccupee                   *
//*** NOTES :    Permet de mettre tous ces objets dans le    *
//***            tableau "objects" de Map                    *
//************************************************************

#include <iostream>
#include <SFML/graphics.hpp>


class AbstractCaseObject
{
    protected :

        bool fixe; //1 si objet fixe (tableau); 0 si objet mobile (forme ou tourelle en placement)


        //Pointeur vers l'image et sprite
        sf::Image *image;
        sf::Sprite sprite;


    public :

        //Getters
        bool getFixe(); //Renvoie fixe
        sf::Sprite getSprite(); //Renvoie le sprite


        virtual void setFixe(); //Permet de rendre fixe l'objet


        //Gestion de la position
        void setPosition(int x, int y); //Mis à jour de la position
        bool outOfMap(); //Vérifie si l'objet est en dehors de la map
        bool validPosition(); //Vérifie si l'objet est dans une position valide pour le rendre fixe


        virtual std::string getType() = 0; //Fonction a redéfinir dans les classes filles; Sert a savoir le type de l'objet

};

#endif // ABSTRACTCASEOBJECT_H_INCLUDED
