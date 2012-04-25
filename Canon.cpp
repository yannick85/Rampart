//************************************************************
//**************** CLASSE : Implémentation *******************
//************************************************************
//*** NOM :      Canon                                       *
//*** FONCTION : Un canon placé par le joueur                *
//*** NOTES :    Hérite de AbstractCaseObject                *
//************************************************************

#include "Canon.h"
#include "ImageManager.h"
#include <sstream>
#include "Ship.hpp"
#include "CollisionManager.hpp"
#include "GestionCanon.h"
#include "Map.h"


#define CASE 15

using namespace std;
using namespace sf;




//************************************************************
//*********************** CONSTRUCTEUR ***********************
//************************************************************
//*** ENTREE :   /                                           *
//*** NOTES :    Permet d'instancier un canon                *
//************************************************************
Canon::Canon()
{
    //On récupère l'image via ImageManager
    image = ImageManager::Inst().getImage("images/canon.png");
    sprite.SetImage(*image);
    sprite.SetSubRect(IntRect(0,0,15,15));
    sprite.SetPosition(Vector2f(0,0));


    fixe = false; //Par défaut le canon est en placement
    pret_a_tirer = true;
    actif=true;
}



sf::Vector2f Canon::getPos()
{
    return sprite.GetPosition();
}








//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      validPosition                               *
//*** ENTREE :   /                                           *
//*** SORTIE :   Booleen indiquant si l'objet est bien placé *
//***            (possible de le rendre fixe à cette position*
//*** NOTES :    Redéfinition d'une méthode présente dans    *
//***            la classe AbstractCaseObject                *
//************************************************************
bool Canon::validPosition()
{
    bool valid = true;

    //On récupère les coordonnées du sprite
    int x = (sprite.GetPosition().x) / CASE;
    int y = (sprite.GetPosition().y) / CASE;

    //S'il est en dehors de la map on retourne false
    if (outOfMap()) valid = false;
    else
    {
        //Sinon on vérifie sa position
        if (Map::Inst().getTerrain(x, y) == 0 || Map::Inst().getTerrain(x, y) == 1) valid = false;
        if (Map::Inst().isObject(x, y)) valid = false;
    }

    return valid;
}









//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      selectSpriteAboutPosition                   *
//*** ENTREE :   /                                           *
//*** SORTIE :   /                                           *
//*** NOTES :    Permet de choisir le sprite (normal ou      *
//***            rouge) en fonction du placement du canon    *
//************************************************************
void Canon::selectSpriteAboutPosition()
{
    if (validPosition()) sprite.SetSubRect(IntRect(0,0,15,15));
    else sprite.SetSubRect(IntRect(15,0,30,15));
}







//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      setFixe                                     *
//*** ENTREE :   /                                           *
//*** SORTIE :   /                                           *
//*** NOTES :    Redéfinition d'une méthode présente dans    *
//***            la classe AbstractCaseObject                *
//************************************************************
void Canon::setFixe()
{
    fixe = true;

    int x = (sprite.GetPosition().x) / CASE;
    int y = (sprite.GetPosition().y) / CASE;

    Map::Inst().setObject(x, y, this);

    //Ajout du mur a GestionCanon
    GestionCanon::getInst().ajoutCanon(this);

    image_viseur = ImageManager::Inst().getImage("images/viseur.png");
    sprite_viseur.SetImage(*image_viseur);
    sprite_viseur.SetSubRect(IntRect(0,0,5,10));
    sprite_viseur.SetPosition(sprite.GetPosition().x+7,sprite.GetPosition().y+7);
    sprite_viseur.SetCenter(3,0);
}









//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      displayCanon                                *
//*** ENTREE :   Ecran                                       *
//*** SORTIE :   /                                           *
//*** NOTES :    Fonction permettant d'afficher un canon     *
//***            (nécessaire pour le canon en placement)     *
//************************************************************
void Canon::displayCanon(sf::RenderWindow &ecran)
{
    if (!outOfMap()) ecran.Draw(sprite);
}






string Canon::getType()
{
    return "Canon";
}





bool Canon::isPretATirer()//connaitre l'état du tir du canon
{
    return pret_a_tirer;
}

void Canon::tirFini()//appeler quand le tir est arrivé a destination
{
    pret_a_tirer = true;
}

void Canon::CommencerTir()//appeler quand on fait tirer le canon
{
    pret_a_tirer = false;
}


void Canon::verifActif()//le canon verifie sa position pour savoir si il est actif ou non
{
    int x = (sprite.GetPosition().x) / CASE;//Recuperation de la postion du sprite
    int y = (sprite.GetPosition().y) / CASE;

    if (Map::Inst().getTerrain(x, y) == 2)//Si le canon est en zone protégé
    {
        actif = true;
    }
    else
    {
        actif =false;
    }
}

bool Canon::isActif()//savoir si le canon est actif
{
    return actif;
}


void Canon::tournerViseur(int souris_x,int souris_y)
{
    int c_x = sprite.GetPosition().x;
    int c_y = sprite.GetPosition().y;
    int d_x = c_x - souris_x;//Recuperation de la distance entre le sprite et la souris pour calculer l'angle
    int d_y = c_y - souris_y;

    sprite_viseur.SetRotation(atan2(-d_x,-d_y)/ 3.14159 * 180);//On tourne le sprite
}

sf::Sprite Canon::getSpriteViseur()
{
    return sprite_viseur;
}
