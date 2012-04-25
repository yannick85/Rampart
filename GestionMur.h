#ifndef GESTIONMUR_H
#define GESTIONMUR_H

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      GestionMur                                  *
//*** FONCTION : Contient tous les pointeurs vers les murs   *
//*** NOTES :    Cette classe est un singleton               *
//************************************************************

#include "mur.h"


class GestionMur // Singleton
{
    public:
        static void makeInst();//Creer une instance de l'objet
        static GestionMur &getInst();//Renvoie l'unique instancle de GestionMur
        int ajoutMur(Mur* new_mur);//appelée dans le setFixe() du Mur , ajoute le pointeur a la collection
        Mur* getRandomMur();//Renvoie un mur aléatoire pour servire de cible au bateau
        void nettoyerMur();//Supprime les murs détruits
    private:
        GestionMur();//Constructeur en private
        static GestionMur *inst;//Pointeur vers l'unique instance de GestionMur
        std::vector<Mur*> tab_mur;//Collection de pointeurs vers les murs
};

#endif // GESTIONMUR_H
