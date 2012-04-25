#ifndef FORME_H_INCLUDED
#define FORME_H_INCLUDED

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      Forme                                       *
//*** FONCTION : Représente une forme contenant des murs     *
//************************************************************

#include <iostream>
#include <SFML/graphics.hpp>
#include "Mur.h"
#include "Point.h"

class Forme
{
    private:

        Point *points; //Tableau de points de la forme

        int num_forme; //L'identificateur de la forme
        int nb_points; //Le nombre de points de la forme

        Mur *murs; //Tableau de pointeurs vers les objets de type Mur


    public:

        Forme(int n, int x, int y); //Constructeur
        ~Forme(); //Destructeur

        void setPosition(int x, int y);
        bool validPosition(); //Vérifier la position du mur
        bool convertToWall(); //Convertir une forme en murs fixes

         //Rotation quand action sur la roulette de la souris
        void rotateRight();
        void rotateLeft();

        void displayForme(sf::RenderWindow &ecran); //Affiche la forme

};



#endif // FORME_H_INCLUDED
