//************************************************************
//******************* CLASSE : Implémentation ****************
//************************************************************
//*** NOM :      GestionBateau                               *
//*** FONCTION : Contient tous les bateaux et les tirBateau  *
//***               et gère leurs comportements              *
//*** NOTES :    Cette classe est un singleton               *
//************************************************************

#include "GestionBateau.h"
#include "GestionMur.h"
#include "Map.h"
#include "Mur.h"
#include "CollisionManager.hpp"

#define VITESSE_BATEAU 0.2
#define CASE 15

GestionBateau::GestionBateau()
{
    //ctor
    vitesse_tir = 1.5;
}

//Classe singleton
GestionBateau* GestionBateau::inst = NULL;


void GestionBateau::makeInst()
{
    if (inst == NULL) inst = new GestionBateau();
}

GestionBateau& GestionBateau::getInst()
{
    return *inst;
}


std::vector<Ship>* GestionBateau::getTabShip()
{
    return &tab_ship;
}

// Les bateaux tirent 1 par 1 quand leurs tir est arrivé a destination
void GestionBateau::tirer()
{
    std::vector<Ship>::iterator i = tab_ship.begin();

    Mur* mur_temp;
    while(i != tab_ship.end())
    {
        if((*i).getPretATirer())
        {
            //TIR
            //Recuperation d'un mur au hasard
            mur_temp = GestionMur::getInst().getRandomMur();

            if (mur_temp == NULL)
            {
                //PLUS DE MUR
            }
            else
            {//On cree le tir
                tab_tir.push_back(TirBateau((*i).getPos(),5,5,vitesse_tir,(*mur_temp).getPos(),&(*i), mur_temp));
            }
        }
        i++;
    }
}

int GestionBateau::update()//Appelée a chaque frame en phase combat
{
    tirer();//on fait tirer tous les bateaux dispo
    bool test_aim;

    std::vector<Ship>::iterator j = tab_ship.begin();
    while(j != tab_ship.end())
    {//On fait bouger chaque bateau
        (*j).move();
        j++;
    }

    std::vector<TirBateau>::iterator i = tab_tir.begin();
    while(i != tab_tir.end())
    {//On fait bouger chaque tir
        test_aim = (*i).move();
        if(test_aim)//Si le tir est arrivé a destination !!
        {
            //detruire le mur associé
            (*i).detruireMur();
            tab_tir.erase(i);//puis le tir
        }
        else
        {
            i++;
        }
    }
    return 1;
}

int GestionBateau::creerBateau(int tour,int dif)
{
    int nombre_bateau;
    switch(tour)//Le nombre de bateau dépend de la difficulté et du tour
    {
        case 1://tour 1
            switch(dif)
            {
                case 1://facile
                    nombre_bateau = 4;
                    break;
                case 2://moyen
                    nombre_bateau = 5;
                    break;
                case 3://difficile
                    nombre_bateau = 7;
                    break;
            }
            break;
        case 2:
        switch(dif)
            {
                case 1:
                    nombre_bateau = 6;
                    break;
                case 2:
                    nombre_bateau = 8;
                    break;
                case 3:
                    nombre_bateau = 10;
                    break;
            }
            break;
        case 3:
            switch(dif)
            {
                case 1:
                    nombre_bateau = 9;
                    break;
                case 2:
                    nombre_bateau = 11;
                    break;
                case 3:
                    nombre_bateau = 13;
                    break;
            }
            break;
        case 4:
            switch(dif)
            {
                case 1:
                    nombre_bateau = 11;
                    break;
                case 2:
                    nombre_bateau = 13;
                    break;
                case 3:
                    nombre_bateau = 16;
                    break;
            }
            break;
        default://tour >4
            switch(dif)
            {
                case 1:
                    nombre_bateau = 12;
                    break;
                case 2:
                    nombre_bateau = 16;
                    break;
                case 3:
                    nombre_bateau = 20;
                    break;
            }
            break;
    }

    for(int i=0;i<nombre_bateau;i++)
    {//Creation des bateaux
        CollisionManager colManager = CollisionManager(sf::Vector2f(800,600));
        //On prend une case d'eau au hasard
        int nbWaterCase = Map::Inst().getNbWaterCases();
        int nb_rand = rand()%nbWaterCase;
        sf::Vector2f vectorxy = Map::Inst().getRandomWaterCase(nb_rand);

        bool bool_ok = true;
        bool bool_col = false;
        //on cree un bateau temporaire a placer correctement
        Ship ship_temp = Ship(vectorxy,30,25,VITESSE_BATEAU);

        while(bool_ok)//Tant que la position de départ du bateau n'est pas valide
        {
            bool_ok=false;
            //On vérifie que le bateau n'entre pas en collision avec les frontieres
            if(colManager.testCollisionXShip(ship_temp) or colManager.testCollisionYShip(ship_temp))
            {
                bool_ok = true;
            }
            //On verifie que la position initiale n'entre en collision avec aucun autre bateau
            int i=0;
            while(i<tab_ship.size())
            {
                bool_col = colManager.testCollision(ship_temp,tab_ship[i]);
                if(bool_col)
                {
                    bool_ok=true;
                }
                i++;
            }

            if(bool_ok)//si le placement est invalide on en trouve un nouveau alétoirement
            {
                int nb_rand = rand()%nbWaterCase;
                sf::Vector2f vectorxy = Map::Inst().getRandomWaterCase(nb_rand);
                ship_temp.setPos(vectorxy);
            }
        }
        //Quand le bateau est bien placé , on l'ajoute au tableau
        tab_ship.push_back(ship_temp);

    }
    return 1;
}

//Affiche tous les sprites de bateau et de tirBateau
void GestionBateau::afficher(sf::RenderWindow &App)
{
    std::vector<TirBateau>::iterator i = tab_tir.begin();
    while(i != tab_tir.end())//Pour tous les tirBateau
    {
        App.Draw((*i).getSprite());
        i++;
    }

    std::vector<Ship>::iterator j = tab_ship.begin();
    while(j != tab_ship.end())//Pour tous les bateaux
    {
        App.Draw((*j).getSprite());
        j++;
    }
}

//Vide les tableaux , appellée en fin de phase
void GestionBateau::nettoyer()
{
    tab_tir.clear();
    tab_ship.clear();
}

//Assigne la vitesse des tirs
void GestionBateau::setVitesseTir(float v_t)
{
    vitesse_tir = v_t;
}
