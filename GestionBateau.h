#ifndef GESTIONBATEAU_H
#define GESTIONBATEAU_H

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      GestionBateau                               *
//*** FONCTION : Contient tous les bateaux et les tirBateau  *
//***               et gère leurs comportements              *
//*** NOTES :    Cette classe est un singleton               *
//************************************************************

#include <vector>
#include "Ship.hpp"
#include "TirBateau.hpp"

class GestionBateau
{
    public:

        static void makeInst();//Creer une instance de la classe
        static GestionBateau &getInst();//Renvoie l'unique instance de la classe
        void tirer();//Fais tirer tous les bateaux disponibles
        int update();//Appeler a chaque frame
        std::vector<Ship>* getTabShip();//renvoie la collection de tous les bateaux
        void afficher(sf::RenderWindow &App);//Affiche tous les bateaux et les tir dans la fenetre
        int creerBateau(int tour,int dif);//Apellée en debut de phase combat pour creer tout les bateaux
        void nettoyer();//Supprime tous les bateaux et tous les tirs
        void setVitesseTir(float v_t);//Indique la vitesse a donner aux tirs
    private:
        GestionBateau();//Constructeur en PRIVATE : Cette classe est un singleton !
        static GestionBateau *inst; //Pointeur vers l'unique instance de la GestionCanon
        std::vector<TirBateau> tab_tir;//Collection de tous les tirs de bateux
        std::vector<Ship> tab_ship;//Collection de tous les bateaux
        float vitesse_tir;//Vitesses des tirs

};

#endif // GESTIONBATEAU_H
