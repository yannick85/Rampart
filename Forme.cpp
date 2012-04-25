//************************************************************
//**************** CLASSE : Implémentation *******************
//************************************************************
//*** NOM :      Forme                                       *
//*** FONCTION : Représente une forme contenant des murs     *
//************************************************************

#include "Forme.h"
#include "Map.h"

using namespace std;
using namespace sf;





//************************************************************
//*********************** CONSTRUCTEUR ***********************
//************************************************************
//*** ENTREE :   Numéro de la forme, coordonnées             *
//*** NOTES :    Permet d'instancier une forme               *
//************************************************************
Forme::Forme(int n, int x, int y)
{
    if (n == 1) //FORME 1
    {
        num_forme = 1;
        nb_points = 1;

        points = new Point[nb_points];


        //Génération des points
        Point p;
            //Point 1
            p.x = 0;
            p.y = 0;
            points[0] = p;
    }

    if (n == 2) // FORME 2
    {
        num_forme = 2;
        nb_points = 4;

        points = new Point[nb_points];

        //Génération des points
        Point p;
            //Point 1
            p.x = 0;
            p.y = 0;
            points[0] = p;

            //Point 2
            p.x = -1;
            p.y = 0;
            points[1] = p;

            //Point 3
            p.x = 1;
            p.y = 0;
            points[2] = p;

            //Point 4
            p.x = 0;
            p.y = -1;
            points[3] = p;


    }

    if (n == 3) //FORME 3
    {
        num_forme = 3;
        nb_points = 5;

        points = new Point[nb_points];


        //Génération des points
        Point p;
            //Point 1
            p.x = 0;
            p.y = 0;
            points[0] = p;

            //Point 2
            p.x = -1;
            p.y = 0;
            points[1] = p;

            //Point 3
            p.x = -1;
            p.y = -1;
            points[2] = p;

            //Point 4
            p.x = 1;
            p.y = 0;
            points[3] = p;

            //Point 5
            p.x = 1;
            p.y = -1;
            points[4] = p;

    }

    if (n == 4) //FORME 4
    {
        num_forme = 4;
        nb_points = 5;

        points = new Point[nb_points];


        //Génération des points
        Point p;
            //Point 1
            p.x = 0;
            p.y = 0;
            points[0] = p;

            //Point 2
            p.x = -1;
            p.y = 0;
            points[1] = p;

            //Point 3
            p.x = -1;
            p.y = -1;
            points[2] = p;

            //Point 4
            p.x = 1;
            p.y = 0;
            points[3] = p;

            //Point 5
            p.x = 1;
            p.y = 1;
            points[4] = p;
    }



    if (n == 5) //FORME 5
    {
        num_forme = 5;
        nb_points = 5;

        points = new Point[nb_points];


        //Génération des points
        Point p;
            //Point 1
            p.x = 0;
            p.y = 0;
            points[0] = p;

            //Point 2
            p.x = -1;
            p.y = 0;
            points[1] = p;

            //Point 3
            p.x = 1;
            p.y = 0;
            points[2] = p;

            //Point 4
            p.x = 0;
            p.y = -1;
            points[3] = p;

            //Point 5
            p.x = 0;
            p.y = 1;
            points[4] = p;
    }

    if (n == 6) //FORME 6
    {
        num_forme = 6;
        nb_points = 3;

        points = new Point[nb_points];


        //Génération des points
        Point p;
            //Point 1
            p.x = 0;
            p.y = 0;
            points[0] = p;

            //Point 2
            p.x = -1;
            p.y = 0;
            points[1] = p;

            //Point 3
            p.x = 1;
            p.y = 0;
            points[2] = p;
    }

    if (n == 7) //FORME 7
    {
        num_forme = 7;
        nb_points = 3;

        points = new Point[nb_points];


        //Génération des points
        Point p;
            //Point 1
            p.x = 0;
            p.y = 0;
            points[0] = p;

            //Point 2
            p.x = -1;
            p.y = 0;
            points[1] = p;

            //Point 3
            p.x = 0;
            p.y = -1;
            points[2] = p;
    }

    if (n == 8) //FORME 8
    {
        num_forme = 8;
        nb_points = 4;

        points = new Point[nb_points];


        //Génération des points
        Point p;
            //Point 1
            p.x = 0;
            p.y = 0;
            points[0] = p;

            //Point 2
            p.x = -1;
            p.y = 0;
            points[1] = p;

            //Point 3
            p.x = 1;
            p.y = 0;
            points[2] = p;

            //Point 4
            p.x = 1;
            p.y = -1;
            points[3] = p;
    }

    if (n == 9) //FORME 9
    {
        num_forme = 9;
        nb_points = 4;

        points = new Point[nb_points];


        //Génération des points
        Point p;
            //Point 1
            p.x = 0;
            p.y = 0;
            points[0] = p;

            //Point 2
            p.x = -1;
            p.y = 0;
            points[1] = p;

            //Point 3
            p.x = -1;
            p.y = -1;
            points[2] = p;

            //Point 4
            p.x = 1;
            p.y = 0;
            points[3] = p;
    }

    if (n == 10) //FORME 10
    {
        num_forme = 10;
        nb_points = 2;

        points = new Point[nb_points];


        //Génération des points
        Point p;
            //Point 1
            p.x = 0;
            p.y = 0;
            points[0] = p;

            //Point 2
            p.x = 1;
            p.y = 0;
            points[1] = p;
    }







    //Génération des murs
    int i;

    murs = new Mur[nb_points];

    for (i = 0; i < nb_points; i++)
    {
        murs[i].setPosition(x + points[i].x, y + points[i].y);
        murs[i].selectSpriteAboutPosition();
    }
}


//Destructeur
Forme::~Forme()
{
    delete [] points;

    //On ne détruit pas les murs, car un pointeur vers chaque mur va etre stocké dans le tableau objects de Map.
}






//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      setPosition                                 *
//*** ENTREE :   Coordonées souhaitées                       *
//*** SORTIE :   /                                           *
//*** NOTES :    Permet de mettre la forme à la position     *
//***            voulue                                      *
//************************************************************
void Forme::setPosition(int x, int y)
{
    int i;

    for (i = 0; i < nb_points; i++)
    {
        murs[i].setPosition(x + points[i].x, y + points[i].y);
        murs[i].selectSpriteAboutPosition();
    }
}






//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      validPosition                               *
//*** ENTREE :   /                                           *
//*** SORTIE :   Booleen indiquant si la forme est dans une  *
//***            position valide pour la rendre fixe         *
//*** NOTES :    Appelle pour chaque mur la méthode          *
//***            validPosition de la classe Mur              *
//************************************************************
bool Forme::validPosition()
{
    int i;
    bool valid = true;

    for (i = 0; i < nb_points; i++)
    {
        if(murs[i].validPosition() == false)
        {
            valid = false;
        }
    }

    return valid;
}






//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      convertToWall                               *
//*** ENTREE :   /                                           *
//*** SORTIE :   Booleen indiquant si la forme est bien      *
//***            convertie en murs fixes ou non              *
//*** NOTES :    Permet de rendre fixe une forme, de la      *
//***            "placer" sur la carte                       *
//************************************************************
bool Forme::convertToWall()
{
    //Si la position de la forme est valide
    if (validPosition() == true)
    {
        int i = 0;

        //On rend fixe chaque mur
        for (i = 0; i < nb_points; i++)
        {
            murs[i].setFixe();
        }
        return true;
    }

    else return false;

}






//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      rotateRight                                 *
//*** ENTREE :   /                                           *
//*** SORTIE :   /                                           *
//*** NOTES :    Permet de tourner une forme vers la droite  *
//************************************************************
void Forme::rotateRight()
{
    int i;

    for (i = 0; i < nb_points; i++)
    {
        int tmp;
        tmp = points[i].y;
        points[i].y = points[i].x;
        points[i].x = -tmp;
    }
}







//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      rotateLeft                                  *
//*** ENTREE :   /                                           *
//*** SORTIE :   /                                           *
//*** NOTES :    Permet de tourner une forme vers la gauche  *
//************************************************************
void Forme::rotateLeft()
{
    int i;

    for (i = 0; i < nb_points; i++)
    {
        int tmp;
        tmp = points[i].x;
        points[i].x = points[i].y;
        points[i].y = -tmp;
    }
}






//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      displayForme                                *
//*** ENTREE :   Ecran                                       *
//*** SORTIE :   /                                           *
//*** NOTES :    Permet d'afficher une forme                 *
//************************************************************
void Forme::displayForme(sf::RenderWindow &ecran)
{
    int i;

    //On affiche chaque mur
    for (i = 0; i < nb_points; i++)
    {
        if (murs[i].outOfMap() == false)
        {
            ecran.Draw(murs[i].getSprite());
        }
    }
}
