#ifndef FORTERESSE_H
#define FORTERESSE_H

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      Forteresse                                  *
//*** FONCTION : Forteresse fixe dans le monde               *
//*** NOTES :    Hérite de AbstractCaseObject                *
//***            Utilise 3 CaseOccupee pour simuler une      *
//***            forteresse de 4 cases                       *
//************************************************************

#include "AbstractCaseObject.h"
#include "CaseOccupee.h"

class Forteresse: public AbstractCaseObject
{
    public:
        Forteresse(int x, int y);//Constructeur
        virtual std::string getType();//renvoie "Forteresse"
        virtual void setFixe();//rentre l'élément dans le tableau de Map
        void checkProt();//Verifie si la forteresse est en zone protégée
    private:
};

#endif // FORTERESSE_H
