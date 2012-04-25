#include <iostream>
#include <math.h>
#include "tir.hpp"

using namespace std;
using namespace sf;

Tir::Tir(Vector2f position, int size_ver ,int size_hor, int speed , sf::Vector2f aim)
: my_size_ver(size_ver),my_size_hor(size_hor), my_dx(speed), my_dy(speed), my_speed(speed) , my_position(position),my_aim(aim)
{
        Image image;

        if (!image.LoadFromFile("proj.png")) // Si le chargement du fichier a échoué
        {
            cout<<"Erreur durant le chargement de l'image"<<endl;
        }
        else // Si le chargement de l'image a réussi
        {
            my_sprite.SetImage(image);
        }
        my_sprite.SetSubRect(IntRect(0, 0, my_size_hor, my_size_ver));

        distance_x = aim.x - position.x;
        distance_y = aim.y - position.y;

        float hyp = sqrt(distance_x*distance_x+distance_y*distance_y);
        float cos= distance_x/hyp;
        float sin= distance_y/hyp;
        //cout << cos <<endl;
        //cout << sin <<endl;

        my_dx = cos;
        my_dy = sin;

        my_sprite.SetPosition(position);

}

bool Tir::move()
{
    bool bool_x = false;
    bool bool_y = false;

    my_sprite.Move(my_dx*my_speed, my_dy*my_speed);

    /*cout << "dx=" << distance_x << endl;
    cout << "dy=" << distance_y << endl;
    cout << "mx=" << my_sprite.GetPosition().x << endl;
    cout << "my=" << my_sprite.GetPosition().y << endl;
    cout << "ax=" << my_aim.x << endl;
    cout << "ay=" << my_aim.y << endl;*/

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

    if(bool_x and bool_y)
    {
        my_sprite.SetPosition(my_aim);
        return true;
    }
    else
    {
        return false;
    }

}

Sprite Tir::getSprite()
{
    return my_sprite;
}

IntRect Tir::getBoundingBox()
{
    IntRect bounding_box;
    bounding_box.Left = (int)my_sprite.GetPosition().x;
    bounding_box.Right = bounding_box.Left + my_size_ver;
    bounding_box.Top = (int)my_sprite.GetPosition().y;
    bounding_box.Bottom = bounding_box.Top + my_size_hor;

    return bounding_box;
}

