//************************************************************
//******************* CLASSE : Implémentation ****************
//************************************************************
//*** NOM :      Canon                                       *
//*** FONCTION : Un canon placé par le joueur                *
//*** NOTES :    Hérite de AbstractCaseObject                *
//************************************************************

#include <iostream>
#include <math.h>
#include "tirBateau.hpp"
#include "ImageManager.h"

using namespace std;
using namespace sf;

TirBateau::TirBateau(Vector2f position, int size_ver ,int size_hor, float speed , sf::Vector2f aim,Ship *bateau,Mur *mur)//constr
{
        my_size_ver = size_ver;
        my_size_hor=size_hor;
        my_dx=speed;
        my_dy=speed;
        my_speed=speed;
         my_aim=aim;

        image = ImageManager::Inst().getImage("images/projB.png");//Chargement de l'image

        my_sprite.SetImage(*image);

        my_sprite.SetSubRect(IntRect(0, 0, my_size_hor, my_size_ver));

        //Calcul de la trajectoire
        distance_x = aim.x - position.x;
        distance_y = aim.y - position.y;

        float hyp = sqrt(distance_x*distance_x+distance_y*distance_y);
        float cos= distance_x/hyp;
        float sin= distance_y/hyp;

        my_dx = cos;
        my_dy = sin;

        my_sprite.SetPosition(position);
        bateau_lie = bateau;
        mur_lie = mur;//Represente le mur objectif
        (*bateau_lie).CommencerTir();//On indique au bateau qu'il doit devenir indisponible pour tirer

}

//fait bouger le tir et vérifie sa position
bool TirBateau::move()
{
    bool bool_x = false;
    bool bool_y = false;

    my_sprite.Move(my_dx*my_speed, my_dy*my_speed);//le sprite bouge

    //Test pour savoir si le tir a atteint l'objectif
    if(distance_x>0 and distance_y>0)
    {
        if(my_sprite.GetPosition().x>my_aim.x and my_sprite.GetPosition().y>my_aim.y)
        {
            bool_x = true;
            bool_y = true;
        }
    }
    if(distance_x>0 and distance_y<00)
    {
        if(my_sprite.GetPosition().x>my_aim.x and my_sprite.GetPosition().y<my_aim.y)
        {
            bool_x = true;
            bool_y = true;
        }
    }
    if(distance_x<0 and distance_y<0)
    {
        if(my_sprite.GetPosition().x<my_aim.x and my_sprite.GetPosition().y<my_aim.y)
        {
            bool_x = true;
            bool_y = true;
        }
    }
    if(distance_x<0 and distance_y>0)
    {
        if(my_sprite.GetPosition().x<my_aim.x and my_sprite.GetPosition().y>my_aim.y)
        {
            bool_x = true;
            bool_y = true;
        }
    }

    if(bool_x and bool_y)//Si il a atteint l'objectif
    {
        my_sprite.SetPosition(my_aim);//Il se replace bien
        (*bateau_lie).tirFini();//On indique au bateau qu'il devient a nouveau disponible pour tirer
        return true;//renvozer true signale que le tir est arrivé
    }
    else
    {
        return false;
    }

}

//Detruit le mur associé
void TirBateau::detruireMur()
{
    (*mur_lie).detruire();
}

