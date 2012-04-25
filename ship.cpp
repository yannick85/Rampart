//************************************************************
//******************* CLASSE : Implémentation ****************
//************************************************************
//*** NOM :      Ship                                        *
//*** FONCTION : Un bateau                                   *
//*** NOTES :    Hérite de AbstractMovingObject              *
//************************************************************

#include <iostream>
#include "ship.hpp"
#include "ImageManager.h"
#include "GestionBateau.h"
#include "CollisionManager.hpp"

using namespace std;
using namespace sf;

Ship::Ship(Vector2f position, int size_ver ,int size_hor, float speed)//constr
{
        my_size_ver=size_ver;
        my_size_hor=size_hor;
        my_speed=speed;
        point_de_vie = 3;
        my_dx = -1;
        my_dy = -1;

        image = ImageManager::Inst().getImage("images/ship.png");//chargement de l'image

        my_sprite.SetImage(*image);


        my_sprite.SetPosition(position);
        pret_a_tirer = true;//Le bateau est pret a tirer a sa création
}

//Fait bouger le bateau et verifie sa position
void Ship::move()
{
    my_sprite.Move(my_dx*my_speed, my_dy*my_speed);//le sprite bouge

    //Test des collisions avec les frontières
    CollisionManager colManager = CollisionManager(sf::Vector2f(800,600));
    bool bool_x = colManager.testCollisionXShip(*this);
    if(bool_x)
    {
        my_dx = -(my_dx);
    }
    bool bool_y = colManager.testCollisionYShip(*this);
    if(bool_y)
    {
        my_dy = -(my_dy);
    }
    //Tests des collisions avec les autres bateaux
    std::vector<Ship> *tab_ship = GestionBateau::getInst().getTabShip();
    std::vector<Ship>::iterator i = (*tab_ship).begin();
    while(i != (*tab_ship).end())
    {
        bool test_col = colManager.testCollision(*this,*i);
        if(test_col)
        {
            my_dy = -(my_dy);
            my_dx = -(my_dx);
        }
        i++;
    }
    if(my_dx < 0)
    {
        my_sprite.SetSubRect(IntRect(25, 0, my_size_hor+25, my_size_ver));
    }
    else
    {
        my_sprite.SetSubRect(IntRect(0, 0, my_size_hor, my_size_ver));
    }

}

//retourne la position du sprite
Vector2f Ship::getPos()
{
    return my_sprite.GetPosition();
}

//indique une nouvelle position pour le bateau
void Ship::setPos(Vector2f new_pos)
{
    my_sprite.SetPosition(new_pos);
}

bool Ship::getPretATirer()//connaitre l'état du tir du bateau
{
    return pret_a_tirer;
}

void Ship::tirFini()//appeler quand le tir est arrivé a destination
{
    pret_a_tirer = true;
}

void Ship::CommencerTir()//appeler quand on fait tirer le bateau;
{
    pret_a_tirer = false;
}

bool Ship::toucher() // renvoie vrai si le bateau coule
{
    point_de_vie=point_de_vie-1;//Les pdv baisse de 1 par coup
    switch(point_de_vie)
    {
        case 2:
            return false;
            break;
        case 1://Quand le bateau a un seul point de vie , on change l'image (voiles rouges)
            image = ImageManager::Inst().getImage("images/shipTouche.png");
            my_sprite.SetImage(*image);
            my_sprite.SetSubRect(IntRect(0, 0, my_size_hor, my_size_ver));
            return false;
            break;
        case 0:
            return true;
            break;
    }
    return true;
}
