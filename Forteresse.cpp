//************************************************************
//******************* CLASSE : Implementation ****************
//************************************************************
//*** NOM :      Forteresse                                  *
//*** FONCTION : Forteresse fixe dans le monde               *
//*** NOTES :    Hérite de AbstractCaseObject                *
//***            Utilise 3 CaseOccupee pour simuler une      *
//***            forteresse de 4 cases                       *
//************************************************************

#include "forteresse.h"
#include "ImageManager.h"
#include "Map.h"
#include "CaseOccupee.h"
#include <sstream>

#define CASE 15

using namespace std;
using namespace sf;

Forteresse::Forteresse(int x,int y)//Constructeur avec en parametre la position de la forteresse dans le tableau objects de Map
{
    image = ImageManager::Inst().getImage("images/forteresse.png");//Chargement de l'image
    sprite.SetImage(*image);
    sprite.SetSubRect(IntRect(0,0,30,30));
    sprite.SetPosition(Vector2f(x*CASE,y*CASE));
    setFixe();
}

void Forteresse::setFixe()
{
    int x = sprite.GetPosition().x;
    int y = sprite.GetPosition().y;
    Map::Inst().setObject((x/CASE),(y/CASE),this);//Ajout de l'objet a la classe objects
}

string Forteresse::getType()
{
    return "Forteresse";
}
void Forteresse::checkProt()//Verifie si la forteresse est protégée
{
    if(Map::Inst().getTerrain(sprite.GetPosition().x/CASE,sprite.GetPosition().y/CASE)==2)//Si l'élément dans la tableau Map vaut 2 alors c est protégé
    {
        sprite.SetSubRect(IntRect(30,0,60,30));//On affiche les drapeaux!
    }else
    {
        sprite.SetSubRect(IntRect(0,0,30,30));//Sprite sans drapeau
    }
}
