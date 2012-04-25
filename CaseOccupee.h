#ifndef CASEOCCUPEE_H
#define CASEOCCUPEE_H

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      CaseOccupee                                 *
//*** FONCTION : Remplir une case pour qu'on ne puisse       *
//***   plus rien placer dessus                              *
//*** NOTES :    Hérite de AbstractCaseObject                *
//************************************************************

#include "AbstractCaseObject.h"

class CaseOccupee: public AbstractCaseObject
{
    public:
        CaseOccupee(int case_x,int case_y);//constr
        virtual std::string getType();//renvoie un string : "Occupee"
        virtual void setFixe();//place l element dans le tableau de Map
    private:
        int case_x;//Cases dans le tableau de Map
        int case_y;
};

#endif // CASEOCCUPEE_H
