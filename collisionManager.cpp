//************************************************************
//******************* CLASSE : Implémentation ****************
//************************************************************
//*** NOM :      collisionManager                            *
//*** FONCTION : Contient les fonctions nécéssaires au       *
//***               calcul de collision                      *
//************************************************************

#include "CollisionManager.hpp"
#include <iostream>
#include "Map.h"

#define CASE 15
#define ELOIGNEMENT_COTE 0

using namespace std;
using namespace sf;

//Teste la collision entre deux rectangles
bool collision(IntRect & a,IntRect & b)
{
    if (a.Bottom <= b.Top)
    {
         return false;
    }
    if (a.Top >= b.Bottom)
    {
        return false;
    }
    if (a.Right <= b.Left)
    {
        return false;
    }
    if (a.Left >= b.Right)
    {
        return false;
    }
    if((a.Right == b.Right) and (a.Left == b.Left) and (a.Top == b.Top) and (a.Bottom == b.Bottom))
    {
        return false;
    }
    return true;
}


CollisionManager::CollisionManager(Vector2f window_size)
: my_window_size(window_size)
{}
// Test esntre deux AbastractMovingObject
bool CollisionManager::testCollision(AbstractMovingObject obj1,AbstractMovingObject obj2)
{
    // Récupération des boîtes englobantes
    IntRect obj1_rect = obj1.getBoundingBox();

    IntRect obj2_rect = obj2.getBoundingBox();

    // Test des Collisions
    if(collision(obj1_rect, obj2_rect))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CollisionManager::testCollisionXShip(AbstractMovingObject obj/*,std::vector<Ship> &tab_obj*/)
{
    // Récupération des boîtes englobantes
    IntRect obj_rect = obj.getBoundingBox();
    IntRect rect_temp;

    // Test des Collisions sur le bord de la map
    if(obj_rect.Right > my_window_size.x-10)
    {
        return true;
    }

    // Test des Collisions sur la terre
    int terrain = Map::Inst().getTerrain((obj_rect.Left+ELOIGNEMENT_COTE)/CASE,(obj_rect.Top)/CASE);
    if(terrain != 1)
    {
        return true;
    }

    return false;
}

bool CollisionManager::testCollisionYShip(AbstractMovingObject obj/*,std::vector<Ship> &tab_obj*/)
{
    // Récupération des boîtes englobantes
    IntRect obj_rect = obj.getBoundingBox();
    IntRect rect_temp;

    // Test des Collisions sur le bord de la map
    if(obj_rect.Bottom > my_window_size.y-10)
    {
        return true;
    }

    // Test des Collisions sur la terre
    int terrain = Map::Inst().getTerrain((obj_rect.Left)/CASE,(obj_rect.Top+ELOIGNEMENT_COTE)/CASE);
    if(terrain != 1)
    {
        return true;
    }
    return false;
}

