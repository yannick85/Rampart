//************************************************************
//******************* CLASSE : Implémentation ****************
//************************************************************
//*** NOM :      TirJoueur                                   *
//*** FONCTION : un tir originaire d'un canon                *
//*** NOTES :    Hérite de AbstractMovingObject              *
//************************************************************

#include <iostream>
#include <math.h>
#include "TirJoueur.hpp"
#include "ImageManager.h"

using namespace std;
using namespace sf;
//constr
TirJoueur::TirJoueur(Vector2f position, int size_ver ,int size_hor, int speed , sf::Vector2f aim,Canon *canon)
{
        my_size_ver=size_ver;
        my_size_hor=size_hor;
        my_dx=speed;
        my_dy=speed;
        my_speed=speed;
        my_aim=aim;
        image = ImageManager::Inst().getImage("images/proj.png");//Chargement de l'image

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

        //On indique au canon origine qu'il doit passer en mode occupé
        canon_lie = canon;
        (*canon_lie).CommencerTir();

        my_sprite.SetPosition(position);

}

//utilisé pour faire bouger le tir
bool TirJoueur::move()
{
    bool bool_x = false;
    bool bool_y = false;

    my_sprite.Move(my_dx*my_speed, my_dy*my_speed);//fait bouger le sprite

    //Verification de sa position par rapport a l'objectif
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

    //Si il est arrivé a son objectif
    if(bool_x and bool_y)
    {
        my_sprite.SetPosition(my_aim);
        (*canon_lie).tirFini();//On libère le canon
        return true;// on renvoie true pour indiqué qu'il est arrivé
    }
    else
    {
        return false;
    }

}
