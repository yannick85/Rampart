//************************************************************
//******************* CLASSE : Implémentation ****************
//************************************************************
//*** NOM :      GestionMur                                  *
//*** FONCTION : Contient tous les pointeurs vers les murs   *
//*** NOTES :    Cette classe est un singleton               *
//************************************************************
#include "GestionMur.h"
#include "Map.h"

#define CASE 15

//Classe singleton
GestionMur* GestionMur::inst = NULL;

GestionMur::GestionMur()
{
    //ctor
}

void GestionMur::makeInst()
{
    if (inst == NULL) inst = new GestionMur();
}

//Retourne l'instance de la classe
GestionMur& GestionMur::getInst()
{
    return *inst;
}

//Utilisée lors du fixage d'un mur a la map , ajoute un pointeur vers ce mur dans la collection
int GestionMur::ajoutMur(Mur* new_mur)
{
    GestionMur::tab_mur.push_back(new_mur);
    return 1;
}

//Renvoie un mur au hasard
Mur* GestionMur::getRandomMur()
{
    int i=0;
    int nb_rand;
    bool mur_detruit;
    if (tab_mur.size() > 0)
    {
        do
        {//On cherche le mur tant qu'on a pas trouvé un mur non détruit
            i++;
            nb_rand = rand()%tab_mur.size();
            mur_detruit = (*tab_mur[nb_rand]).estDetruit();
        }
        while(mur_detruit and i<500);
    }
    else return NULL;


    if(i>499)
    {//Si il reste aucun mur valide
        return NULL;
    }
    else
    {
        return (tab_mur[nb_rand]);
    }

}

//Retire tous les mur détruit
void GestionMur::nettoyerMur()
{
    std::vector<Mur*>::iterator i = tab_mur.begin();
    while(i != tab_mur.end())
    {//Pour tous les murs
        if((*(*i)).estDetruit())//Si il est détruit
        {
            Map::Inst().setObject((*(*i)).getPos().x/CASE,(*(*i)).getPos().y/CASE,NULL);//le supprime de Map
            tab_mur.erase(i);//supprime son pointeur dans la collection
        }
        else
        {
            i++;
        }
    }
}
