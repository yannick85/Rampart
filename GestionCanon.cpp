//************************************************************
//******************* CLASSE : Implémentation ****************
//************************************************************
//*** NOM :      GestionCanon                                *
//*** FONCTION : Contient tous les canon et les tirJoueur    *
//***               et gère leurs comportements              *
//*** NOTES :    Cette classe est un singleton               *
//************************************************************

#include "GestionCanon.h"
#include "CollisionManager.hpp"
#include "GestionBateau.h"
#include "GestionPanneau.h"

//Classe singleton
GestionCanon* GestionCanon::inst = NULL;



//
void GestionCanon::makeInst()
{
    if (inst == NULL) inst = new GestionCanon();
}

GestionCanon& GestionCanon::getInst()
{
    return *inst;
}

GestionCanon::GestionCanon()
{
    //CONSTRUCTEUR
    vitesse_tir = 4;
}

//Appelée lors d'un clic de souris
void GestionCanon::tirer(int aim_x,int aim_y)
{
    bool tir_fait=false;
    std::vector<Canon*>::iterator i = tab_canon.begin();
    while((i != tab_canon.end()) and !tir_fait)//Pour chaque canon et tant que aucun tir est effectué
        {
            if((*(*i)).isPretATirer() & (*(*i)).isActif())//Si le canon est actif et prêt a tirer
            {
                tab_tir.push_back(TirJoueur((*(*i)).getPos(),5,5,vitesse_tir,sf::Vector2f(aim_x,aim_y),(*i)));//on ajoute le tir
                tir_fait=true;// on indique que le tir est effectué pour sortir de la méthode
            }
            i++;
        }
}

//Appellée a chaque frame
int GestionCanon::update()
{
    CollisionManager colManager = CollisionManager(sf::Vector2f(800,600));

        std::vector<Ship> *tab_ship = GestionBateau::getInst().getTabShip();//On recupère le tableau de tous les bateaux
        int bateau_coule=0;
        bool est_coule;

        std::vector<TirJoueur>::iterator i = tab_tir.begin();
        while(i != tab_tir.end())//Pour chaque tir
        {
            bool testPos = (*i).move();//on fait bouger le tir

            if(testPos)//si il est arrivé a destination
            {
                std::vector<Ship>::iterator j = (*tab_ship).begin();
                while(j != (*tab_ship).end())//Pour chaque bateau
                {
                    bool boolTemp = colManager.testCollision(*i,*j);//on vérifie si il y a collision
                    if(boolTemp)
                    {
                        est_coule = (*j).toucher();//On indique au bateau qu'il a été touché
                        if(est_coule)//Si il a été coulé
                        {
                            (*tab_ship).erase(j);//on détruit le bateau
                            bateau_coule++;
                            GestionPanneau::getInst().addScore(100);//100 pts pour avoir couler un bateau !
                        }
                        else
                        {
                            j++;
                        }
                    }
                    else
                    {
                        j++;
                    }
                }
                tab_tir.erase(i);//on détruit le tir
            }
            else
            {
                //app.Draw((*i).getSprite());
                i++;
            }
        }
        return bateau_coule;
}

//On ajoute le canon dans le tableau de pointeurs vers canon
int GestionCanon::ajoutCanon(Canon* new_canon)
{
    tab_canon.push_back(new_canon);
    return 1;
}

//Affiche tous les sprites de viseur et de tir
void GestionCanon::afficherTir(sf::RenderWindow &App)
{
    std::vector<TirJoueur>::iterator i = tab_tir.begin();
    while(i != tab_tir.end())//Pour tous les tirs
    {
        App.Draw((*i).getSprite());
        i++;
    }

    std::vector<Canon*>::iterator j = tab_canon.begin();
    while(j != tab_canon.end())//Pour tous les canons
    {
        if((*(*j)).isActif())//Si il est actif
        {
            App.Draw((*(*j)).getSpriteViseur());
        }
        j++;
    }

}

//libère tous les canons et détruis tous les tirs
void GestionCanon::nettoyer()
{
    std::vector<Canon*>::iterator i = tab_canon.begin();
    while(i != tab_canon.end())
    {
        (*(*i)).tirFini();
        i++;
    }

    tab_tir.clear();
}

//Vérifie la postion de chaque canon et met a jour son statut
void GestionCanon::verifPosCanon()
{
    std::vector<Canon*>::iterator i = tab_canon.begin();
    while(i != tab_canon.end())
    {
        (*(*i)).verifActif();
        i++;
    }
}

//Tourne le viseurs vers la souris
void GestionCanon::tournerViseur(int souris_x,int souris_y)
{
    std::vector<Canon*>::iterator j = tab_canon.begin();
    while(j != tab_canon.end())
    {
        if((*(*j)).isActif())//Pour chaque canon actif
        {
            (*(*j)).tournerViseur(souris_x,souris_y);
        }
        j++;
    }
}

//On indique la vitesse de tir
void GestionCanon::setVitesseTir(float v_t)
{
    vitesse_tir = v_t;
}
