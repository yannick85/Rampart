#ifndef GESTIONCANON_H
#define GESTIONCANON_H

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      GestionCanon                                *
//*** FONCTION : Contient tous les canon et les tirJoueur    *
//***               et gère leurs comportements              *
//*** NOTES :    Cette classe est un singleton               *
//************************************************************

#include <vector>
#include "TirJoueur.hpp"
#include "Canon.h"

class GestionCanon
{
    public:
        static void makeInst();//Creer une instance de GestionCanon
        static GestionCanon &getInst();//Renvoie l'unique instance de la classe
        void tirer(int aim_x,int aim_y);//Appelée lorsque l'on clique sur la souris en phase Combat, Fait tirer le premier canon disponible
        int update();//Appellée toutes les frames pour mettre a jour tous els objets
        int ajoutCanon(Canon* new_canon);//Apellée dans le setFixe() du canon , ajoute la canon au tableau de pointeur
        void afficherTir(sf::RenderWindow &App);//Afficher les objets tirs et viseurs sur l'écran
        void nettoyer();//Supprime tous les tirs
        void verifPosCanon();//Check tous les canon pour voir si il sont en zone protégés et utiliser leurs setActif()
        void tournerViseur(int souris_x,int souris_y);//Appeler lorsqu'on bouge la souris en phase Combat
        void setVitesseTir(float v_t);//Indique la vitesse des tirs
    private:
        GestionCanon();//constructeur en private : Singleton
        static GestionCanon *inst; //Pointeur vers l'unique instance de la GestionCanon
        std::vector<TirJoueur> tab_tir;//Contient tous les TirJoueur
        std::vector<Canon*> tab_canon;//Contient tous les pointeurs vers la classe Canon
        float vitesse_tir;//Vitesse des tirs
};
#endif // GESTIONCANON_H
