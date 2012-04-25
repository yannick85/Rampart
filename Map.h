#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      Map                                         *
//*** FONCTION : Repr�sente la carte du jeu                  *
//*** NOTES :    Cette classe est un singleton               *
//************************************************************

#include <iostream>
#include <SFML/graphics.hpp>
#include "Mur.h"
#include "Canon.h"
#include "Point.h"


class Map
{
    private :

        Map(int n); //Constructeur en PRIVATE : Cette classe est un singleton !
        static Map *m_Inst; //Pointeur vers l'unique instance de la Map


        //Tableau correspondant � la map : 0 pour terre, 1 pour mer ,2 pour terre prot�g�
        int map[40][53];
        int nb_water_cases; //Nombre de cases d'eau

        //Tableau correspondant aux murs et tourelles (objet a placer par "case")
        AbstractCaseObject* objects[40][53];

        //Tableau pour la v�rification de l'entourage d'une zone par des murs
        int verif_mur[40][53];

        //Image de la carte, et pointeur vers la ressource image
        sf::Image *image;
        sf::Sprite sprite;


    public :

        static Map &Inst(); //Fonction renvoyant l'unique instance de Map, permettant de l'appeler dans toute fonction.
        static void makeInst(int n); //Initialisation de la map gr�ce � son num�ro

        int getTerrain(int x, int y); //Permet de savoir quel terrain est aux coordonn�es x y
        bool isObject(int x, int y); //Permet de savoir si un objet existe aux coordonn�es x y
        void setObject(int x, int y, AbstractCaseObject *object); //Permet de mettre un objet aux coordonn�es x y

        void displayMap(sf::RenderWindow &ecran); //Affiche la carte
        void displayObjects(sf::RenderWindow &ecran); //Affiche les objets


        //Verification mur
        void verifMur(bool add_score);
        void initVerifMur();
        bool recursiveVerifMur(int x, int y);
        bool continueVerif();
        Point getRandomTerre();
        void reinitMap();


        //R�cup�ration d'une case al�atoire d'eau
        int getNbWaterCases();
        sf::Vector2f getRandomWaterCase(int rand);

        int getNombreCanonPosable(int tab_fort[5][2]);


};


#endif // MAP_H_INCLUDED
