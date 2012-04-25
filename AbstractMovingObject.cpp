//************************************************************
//******************* CLASSE : IMPLEMENTATION ****************
//************************************************************
//*** NOM :      AbstractMovingObject                         *
//*** FONCTION : Classe mère des objets tirJoueur, tirBateau, *
//***            et ship                  *
//************************************************************

#include "AbstractMovingObject.h"

AbstractMovingObject::AbstractMovingObject()
{
    //ctor
}

//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      getSprite                                   *
//*** ENTREE :   /                                           *
//*** SORTIE :   Sprite                                      *
//************************************************************
sf::Sprite AbstractMovingObject::getSprite()
{
    return my_sprite;
}

//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      setFixe                                     *
//*** ENTREE :   /                                           *
//*** SORTIE :   IntRect                                     *
//************************************************************
sf::IntRect AbstractMovingObject::getBoundingBox()//Retourne la boite englobante du sprite
{
    sf::IntRect bounding_box;
    bounding_box.Left = (int)my_sprite.GetPosition().x;
    bounding_box.Right = bounding_box.Left + my_sprite.GetSize().x;
    bounding_box.Top = (int)my_sprite.GetPosition().y;
    bounding_box.Bottom = bounding_box.Top + my_sprite.GetSize().y;

    return bounding_box;
}
