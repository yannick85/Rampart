//************************************************************
//**************** CLASSE : Implémentation *******************
//************************************************************
//*** NOM :      AbstractCaseObject                          *
//*** FONCTION : Classe mère des objets Mur, Canon,          *
//***            Forteresse et CaseOccupee                   *
//*** NOTES :    Permet de mettre tous ces objets dans le    *
//***            tableau "objects" de Map                    *
//************************************************************

#include "AbstractCaseObject.h"
#include "Map.h"

#define CASE 15

using namespace std;
using namespace sf;



//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      getFixe                                     *
//*** ENTREE :   /                                           *
//*** SORTIE :   Booleen "fixe"                              *
//*** NOTES :    Getter pour le booleen fixe                 *
//************************************************************
bool AbstractCaseObject::getFixe()
{
    return fixe;
}





//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      getSprite                                   *
//*** ENTREE :   /                                           *
//*** SORTIE :   Sprite de l'objet                           *
//*** NOTES :    Getter pour le sprite de l'objet            *
//************************************************************
Sprite AbstractCaseObject::getSprite()
{
    return sprite;
}





//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      setFixe                                     *
//*** ENTREE :   /                                           *
//*** SORTIE :   /                                           *
//*** NOTES :    Permet de rendre l'objet fixe               *
//************************************************************
void AbstractCaseObject::setFixe()
{
    fixe = true;
}







//Travail sur les positions

//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      setPosition                                 *
//*** ENTREE :   Position de l'objet voulue (par rapport aux *
//***            cases de la map                             *
//*** SORTIE :   /                                           *
//*** NOTES :    Permet de mettre l'objet à la position      *
//***            voulue                                      *
//************************************************************
void AbstractCaseObject::setPosition(int x, int y)
{
    sprite.SetPosition(Vector2f(x*CASE, y*CASE));
}






//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      outOfMap                                    *
//*** ENTREE :   /                                           *
//*** SORTIE :   Booleen indiquant si l'objet est en dehors  *
//***            de la map                                   *
//************************************************************
bool AbstractCaseObject::outOfMap()
{
    bool out = false;

    //On récupère les coordonnés du sprite
    int x = (sprite.GetPosition().x) / CASE;
    int y = (sprite.GetPosition().y) / CASE;

    //S'il est en dehors de la map on retourne true
    if (x > 52 || x < 0 || y > 39 || y < 0) out = true;

    return out;
}






//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      validPosition                               *
//*** ENTREE :   /                                           *
//*** SORTIE :   Booleen indiquant si l'objet est bien placé *
//***            (possible de le rendre fixe à cette position*
//************************************************************
bool AbstractCaseObject::validPosition()
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
        if (Map::Inst().getTerrain(x, y) == 1) valid = false;
        if (Map::Inst().isObject(x, y)) valid = false;
    }

    return valid;
}
