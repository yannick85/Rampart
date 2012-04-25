//************************************************************
//**************** CLASSE : Implémentation *******************
//************************************************************
//*** NOM :      CaseOccupee                                 *
//*** FONCTION : Sert seulement a occuper une place dans Map *
//************************************************************

#include "CaseOccupee.h"
#include "ImageManager.h"
#include "Map.h"
#include <sstream>

using namespace std;
using namespace sf;


CaseOccupee::CaseOccupee(int c_x,int c_y)//Constructeur avec les case du tableau objects de Map en paramètre
{
    case_x = c_x;
    case_y = c_y;
    setFixe();
}

void CaseOccupee::setFixe()
{
    Map::Inst().setObject(case_x,case_y,this);//Ajout de l'élément dans le tableau objects
}

string CaseOccupee::getType()
{
    return "Occupee";
}

