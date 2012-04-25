#ifndef GESTIONPANNEAU_H
#define GESTIONPANNEAU_H

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      GestionPanneau                              *
//*** FONCTION : Gere tous les éléments du tableau de droite *
//*** NOTES :    Cette classe est un singleton               *
//************************************************************

#include <SFML/graphics.hpp>

class GestionPanneau
{
    public:
        static void makeInst();//Creer une instance de la classe
        static GestionPanneau &getInst();//Renvoie l'unique instance de la classe
        void setTime(float time);//Indique au panneau quel temps afficher
        void afficher(sf::RenderWindow &App);//Affiche tout le panneau de droite
        void setPhase(int phaseI);//Indique au panneau a quel phase le jeu est actuellement
        void addScore(long ajout_score);//Ajoute un nombre au score actuelle
        void setNbCanon(int nombre_de_canon_posable);//indique le nombre de canon disponible a afficher
        void setDifficulte(int dif);//indique la difficultée a afficher
    private:
        long score;//Represente le score du jeu
        static GestionPanneau *inst;//Pointeur vers l'unique instance de la classe
        int phase;//Indique le phase actuelle
        GestionPanneau();//Constructeur en private : singleton

        //sf::String Represente du texte affichable
        sf::String text_explication;
        sf::String text_score;
        sf::String text_time;
        sf::String text_difficulte;

        //Toutes les images utiles a l'affichage des différents éléments
        sf::Image *imagePhaseConstr;
        sf::Image *imagePhaseCanon;
        sf::Image *imageCadre;
        sf::Image *imagePhaseCombat;

        sf::Sprite my_sprite_phase;//Sprite du logo de la phase en cours
        sf::Sprite my_sprite_cadre;//Sprite de fond
};

#endif // GESTIONPANNEAU_H
