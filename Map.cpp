//************************************************************
//**************** CLASSE : Impl�mentation *******************
//************************************************************
//*** NOM :      Map                                         *
//*** FONCTION : Repr�sente la carte du jeu                  *
//*** NOTES :    Cette classe est un singleton               *
//************************************************************

#include "Map.h"
#include "ImageManager.h"
#include "GestionPanneau.h"

#define CASE 15

using namespace std;
using namespace sf;



//Classe singleton
Map* Map::m_Inst = NULL;





//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      makeInst                                    *
//*** ENTREE :   "num�ro" de la carte                        *
//*** SORTIE :   /                                           *
//*** NOTES :    Cr�� l'unique instance de Map si le         *
//***            pointeur m_Inst est � NULL                  *
//************************************************************
void Map::makeInst(int n)
{
    if (m_Inst == NULL) m_Inst = new Map(n);
}





//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      Inst                                        *
//*** ENTREE :   /                                           *
//*** SORTIE :   L'unique instance de Map                    *
//************************************************************
Map& Map::Inst()
{
    return *m_Inst;
}







//************************************************************
//*********************** CONSTRUCTEUR ***********************
//************************************************************
//*** ENTREE :   le "Num�ro" de la carte                     *
//*** NOTES :    Permet d'initialiser la carte               *
//************************************************************
Map::Map(int n)
{
    //CAS LEVEL 1
    if (n == 1)
    {

        int i;
        int j;

        nb_water_cases = 0;

        //Initialisation de la carte correspondant � l'image de la carte
        for (i = 0; i < 40; i++)
        {
            for (j = 0; j < 53; j++)
            {
                switch (i)
                {
                    case 39:
                        if (j > 12)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 38:
                        if (j > 12)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 37:
                        if (j > 13)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 36:
                        if (j > 14)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 35:
                        if (j > 15)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 34:
                        if (j > 16)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 33:
                        if (j > 19)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 32:
                        if (j > 20)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 31:
                        if (j > 20)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 30:
                        if (j > 19)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 29:
                        if (j > 18)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 28:
                        if (j > 18)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 27:
                        if (j > 18)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 26:
                        if (j > 18)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 25:
                        if (j > 18)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 24:
                        if (j > 18)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 23:
                        if (j > 18)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 22:
                        if (j > 18)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 21:
                        if (j > 19)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 20:
                        if (j > 20)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 19:
                        if (j > 21)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 18:
                        if (j > 23)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 17:
                        if (j > 24)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 16:
                        if ((j > 26 && j < 37) || (j > 42 && j < 51))
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 15:
                        if ((j > 26 && j < 36) || (j > 43 && j < 48))
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    case 14:
                        if (j > 27 && j < 35)
                        {
                            map[i][j] = 1;
                            nb_water_cases++;
                        }
                        else map[i][j] = 0;
                        break;
                    default:
                        map[i][j] = 0;
                }
            }
        }



        //Initialisation du tableau objects � NULL
        for (i = 0; i < 40; i++)
        {
            for (j = 0; j < 53; j++)
            {
                objects[i][j] = NULL;
            }
        }


        //On r�cup�re l'image de la carte via ImageManager
        image = ImageManager::Inst().getImage("images/map.png");
        sprite.SetImage(*image);
        sprite.SetSubRect(IntRect(0,0,800,600));
        sprite.SetPosition(Vector2f(0,0));



    }
}








//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      getTerrain                                  *
//*** ENTREE :   Coordonn�es de la case � v�rifier           *
//*** SORTIE :   Int correspondant au contenu de la case     *
//************************************************************
int Map::getTerrain(int x, int y)
{
    return map[y][x];
}







//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      isObject                                    *
//*** ENTREE :   Coordonn�es de la case � v�rifier           *
//*** SORTIE :   Boolean indiquant si un objet est pr�sent   *
//************************************************************
bool Map::isObject(int x, int y)
{
    if (objects[y][x] == NULL) return false;
    else return true;
}











//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      setObject                                   *
//*** ENTREE :   Coordonn�es de la case � v�rifier et        *
//***            pointeur vers l'objet � ajouter             *
//*** SORTIE :   /                                           *
//*** NOTES :    Permet d'ajouter un objet dans le tableau   *
//************************************************************
void Map::setObject(int x, int y, AbstractCaseObject *object)
{
    objects[y][x] = object;
}









//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      displayMap                                  *
//*** ENTREE :   Ecran                                       *
//*** SORTIE :   /                                           *
//*** NOTES :    Permet d'afficher la carte                  *
//************************************************************
void Map::displayMap(sf::RenderWindow &ecran)
{
    //On affiche la carte
    ecran.Draw(sprite);

    Shape carre;
    int i;
    int j;

    for (i = 0; i < 40; i++)
    {
        for (j = 0; j < 53; j++)
        {
            if (map[i][j] == 2)
            {
                //Si la case est terrain entour�, on ajoute un shape noir transparent
                carre.AddPoint(j*CASE, i*CASE, Color(0,0,0,160), Color(0,0,0,160));
                carre.AddPoint(j*CASE + CASE, i*CASE, Color(0,0,0,160), Color(0,0,0,160));
                carre.AddPoint(j*CASE + CASE, i*CASE + CASE, Color(0,0,0,160), Color(0,0,0,160));
                carre.AddPoint(j*CASE, i*CASE + CASE, Color(0,0,0,160), Color(0,0,0,160));
                carre.EnableFill(true);
                ecran.Draw(carre);
                carre = Shape();
            }
        }
    }
}






//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      displayObjects                              *
//*** ENTREE :   Ecran                                       *
//*** SORTIE :   /                                           *
//*** NOTES :    Permet d'afficher les objets sur la carte   *
//************************************************************
void Map::displayObjects(sf::RenderWindow &ecran)
{
    int i;
    int j;

    for (i = 0; i < 40; i++)
    {
        for (j = 0; j < 53; j++)
        {
            if (objects[i][j] != NULL)
            {
                if(objects[i][j]->getType() != "Occupee")
               {
                    ecran.Draw(objects[i][j]->getSprite());
               }
            }
        }
    }
}








//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      verifMur                                    *
//*** ENTREE :   Booleen indiquant si cette v�rification     *
//***            compte dans le score du joueur              *
//*** SORTIE :   /                                           *
//*** NOTES :    Permet de v�rifier l'entourage d'un zone par*
//***            des murs                                    *
//************************************************************
void Map::verifMur(bool add_score)
{
    initVerifMur(); //Initialisation de la v�rification
    Point p;
    int i;
    int j;

    do {

        p = getRandomTerre();

        if (recursiveVerifMur(p.x, p.y) == true)
        {
            //Si la zone qu'on vient de v�rifier est entour�e par des murs
            for (i = 0; i < 40; i++)
            {
                for (j = 0; j < 53; j++)
                {
                    if (verif_mur[i][j] == 3)
                    {
                        map[i][j] = 2; //On met � jour le tableau map
                        verif_mur[i][j] = 5;
                        if (add_score) GestionPanneau::getInst().addScore(10); //On met � jour le score selon le booleen
                    }
                }
            }
        }


        //On marque ces cases v�rifi�es
        for (i = 0; i < 40; i++)
        {
            for (j = 0; j < 53; j++)
            {
                if (verif_mur[i][j] == 3) verif_mur[i][j] = 4;
            }
        }

    } while (continueVerif() == true); //Tant qu'il reste des cases terres non trait�es
}






//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      initVerifMur                                *
//*** ENTREE :   /                                           *
//*** SORTIE :   /                                           *
//*** NOTES :    Initialise la v�rification                  *
//************************************************************
void Map::initVerifMur()
{
    int i;
    int j;

    //On remplit le tableau verif_mur
    for (i = 0; i < 40; i++)
    {
        for (j = 0; j < 53; j++)
        {
            if (objects[i][j] != NULL && objects[i][j]->getType() == "Mur") verif_mur[i][j] = 2; //2 pour MUR
            else if (map[i][j] == 1) verif_mur[i][j] = 1; //1 pour EAU
            else if (map[i][j] == 2) verif_mur[i][j] = 3; //3 pour TERRAIN ENTOURE (d�j� v�rifi� avant...)
            else verif_mur[i][j] = 0; //0 pour TERRE
        }
    }
}






//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      recursiveVerifMur                           *
//*** ENTREE :   Coordonn�es de la case � v�rifier           *
//*** SORTIE :   Boolean indiquant si la case v�rifi�e est   *
//***            bonne ou non                                *
//*** NOTES :    Fonction r�cursive qui v�rifie une � une    *
//***            les cases                                   *
//************************************************************
bool Map::recursiveVerifMur(int x, int y)
{
    bool ok = true;

    //Si la case est en dehors du plateau on renvoie faux.
    if (y < 0 || y > 39 || x < 0 || x > 52) ok = false;
    else
    {
        if (verif_mur[y][x] == 1) ok = false; //Si c'est de l'eau on renvoie faux
        else
        {
            if (verif_mur[y][x] == 0) //Si c'est de la terre
            {
                verif_mur[y][x] = 3; //On "marque cette case

                //On v�rifie toute ses case voisines
                if (recursiveVerifMur(x-1, y-1) == false) ok = false;
                if (recursiveVerifMur(x, y-1) == false) ok = false;
                if (recursiveVerifMur(x+1, y-1) == false) ok = false;
                if (recursiveVerifMur(x+1, y) == false) ok = false;
                if (recursiveVerifMur(x+1, y+1) == false) ok = false;
                if (recursiveVerifMur(x, y+1) == false) ok = false;
                if (recursiveVerifMur(x-1, y+1) == false) ok = false;
                if (recursiveVerifMur(x-1, y) == false) ok = false;

            }
        }
    }

    //On renvoie faux si la case v�rifi�e est en dehors du plateau ou si c'est de l'eau
    //mais �galement si l'un de ces conditions est v�rifi�es sur ses cases voisines

    return ok;
}








//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      continueVerif                               *
//*** ENTREE :   /                                           *
//*** SORTIE :   Boolean indiquant si on doit continuer la   *
//***            v�rification ou non                         *
//************************************************************
bool Map::continueVerif()
{
    bool cont = false;
    int i;
    int j;

    //Si on trouve une case Terre non marqu�e (0), on doit continuer, sinon toutes les cases sont v�rifi�es
    for (i = 0; i < 40; i++)
    {
        for (j = 0; j < 53; j++)
        {
            if (verif_mur[i][j] == 0) cont = true;
        }
    }

    return cont;

}






//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      getRandomTerre                              *
//*** ENTREE :   /                                           *
//*** SORTIE :   Point correspondant � une case de Terre non *
//***            marqu�e                                     *
//************************************************************
Point Map::getRandomTerre()
{
    Point p;
    int i;
    int j;

    for (i = 0; i < 40; i++)
    {
        for (j = 0; j < 53; j++)
        {
            if (verif_mur[i][j] == 0)
            {
                p.x = j;
                p.y = i;
                return p;
            }
        }
    }

}







//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      reinitMap                                   *
//*** ENTREE :   /                                           *
//*** SORTIE :   /                                           *
//*** NOTES :    Permet de r�initialiser les zones de        *
//***            terrain entour� de la map                   *
//************************************************************
void Map::reinitMap()
{
    int i;
    int j;

    for (i = 0; i < 40; i++)
    {
        for (j = 0; j < 53; j++)
        {
            if (map[i][j] == 2)
            {
                map[i][j] = 0;
            }
        }
    }
}






//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      getNbWaterCases                             *
//*** ENTREE :   /                                           *
//*** SORTIE :   Nombre de cases eau de la map               *
//*** NOTES :    Getter pour nb_water_case                   *
//************************************************************
int Map::getNbWaterCases()
{
    return nb_water_cases;
}





//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      getNbWaterCases                             *
//*** ENTREE :   int au hasard                               *
//*** SORTIE :   Vector::2f correspondant � la position sur  *
//***            l'�cran de la case choisie                  *
//************************************************************
Vector2f Map::getRandomWaterCase(int rand)
{
    Vector2f vector;
    int cases_founded = 0;
    int i;
    int j;

    for (i = 0; i < 40; i++)
    {
        for (j = 0; j < 53; j++)
        {
            if (map[i][j] == 1)
            {
                if (rand == cases_founded) vector = Vector2f(j*CASE, i*CASE);
                cases_founded++;
            }
        }
    }

    return vector;
}





int Map::getNombreCanonPosable(int tab_fort[5][2])
{
    int nb_fort_protege=0;
    for(int i =0;i<5;i++)
    {
        if(getTerrain(tab_fort[i][0],tab_fort[i][1])==2)
        {
            nb_fort_protege++;
        }
    }
    return (nb_fort_protege+1);
}
