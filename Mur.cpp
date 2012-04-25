//************************************************************
//**************** CLASSE : Implémentation *******************
//************************************************************
//*** NOM :      Mur                                         *
//*** FONCTION : Un mur placé par le joueur                  *
//*** NOTES :    Hérite de AbstractCaseObject                *
//************************************************************

#include "Mur.h"
#include "ImageManager.h"
#include "Map.h"
#include "GestionMur.h"
#include "GestionPanneau.h"

#define CASE 15

using namespace std;
using namespace sf;




//************************************************************
//*********************** CONSTRUCTEUR ***********************
//************************************************************
//*** ENTREE :   /                                           *
//*** NOTES :    Permet d'instancier un mur                  *
//************************************************************
Mur::Mur()
{
    //On récupère l'image via ImageManager
    image = ImageManager::Inst().getImage("images/mur.png");
    sprite.SetImage(*image);
    sprite.SetSubRect(IntRect(0,0,15,15));
    sprite.SetPosition(Vector2f(0,0));

    fixe = false; //Par défaut non fixe (dans une forme)
    detruit=false;
}







//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      selectSpriteAboutPosition                   *
//*** ENTREE :   /                                           *
//*** SORTIE :   /                                           *
//*** NOTES :    Permet de choisir le sprite (normal ou      *
//***            rouge) en fonction du placement du mur      *
//************************************************************
void Mur::selectSpriteAboutPosition()
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
void Mur::setFixe()
{
    fixe = true;

    int x = (sprite.GetPosition().x) / CASE;
    int y = (sprite.GetPosition().y) / CASE;

    Map::Inst().setObject(x, y, this);

    //Ajout du mur a GestionMur
    GestionMur::getInst().ajoutMur(this);
    GestionPanneau::getInst().addScore(10);
}

//Retourne l'état du mur
bool Mur::estDetruit()
{
    return detruit;
}

//Passe l'état du mur a détruit et change son sprite
void Mur::detruire()
{
    detruit=true;
    sprite.SetSubRect(IntRect(15, 0, 30, 15));
    GestionPanneau::getInst().addScore(-5);//-5 dans le score par destruction de mur (Rappel +10 pour construction)
}

string Mur::getType()
{
    return "Mur";
}

//Retourne la position du sprite
sf::Vector2f Mur::getPos()
{
    return Vector2f(sprite.GetPosition().x,sprite.GetPosition().y);
}
