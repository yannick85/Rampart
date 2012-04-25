//************************************************************
//******************* CLASSE : Implémentation ****************
//************************************************************
//*** NOM :      GestionPanneau                              *
//*** FONCTION : Gere tous les éléments du tableau de droite *
//*** NOTES :    Cette classe est un singleton               *
//************************************************************
#include "GestionPanneau.h"
#include <SFML/graphics.hpp>
#include "ImageManager.h"
#include <sstream>
#include <string>

//Transforme un float en string
std::string float2string(float f)
{
  std::ostringstream os;
  os << f;
  return os.str();
}

//constr
GestionPanneau::GestionPanneau()
{
    //Chargement des images
    imagePhaseConstr = ImageManager::Inst().getImage("images/phaseConstr.png");
    imagePhaseCanon = ImageManager::Inst().getImage("images/phaseCanon.png");
    imagePhaseCombat = ImageManager::Inst().getImage("images/phaseCombat.png");
    imageCadre = ImageManager::Inst().getImage("images/cadre.png");

    //Configuration des zones de textes
    text_time.SetPosition(850,50);
    text_time.SetColor(sf::Color(255,0,0,255));
    text_time.SetSize(25);

    text_explication.SetPosition(830,120);
    text_explication.SetColor(sf::Color(0,0,0,255));
    text_explication.SetSize(15);

    text_difficulte.SetPosition(850,530);
    text_difficulte.SetSize(20);
    text_difficulte.SetText("~~~");

    text_score.SetPosition(830,220);
    text_score.SetColor(sf::Color(0,150,0,255));

    //Configuration des sprites
    my_sprite_phase.SetSubRect(sf::IntRect(0, 0,150,150));
    my_sprite_phase.SetPosition(825,350);

    my_sprite_cadre.SetImage(*imageCadre);
    my_sprite_cadre.SetSubRect(sf::IntRect(0,0,200,600));
    my_sprite_cadre.SetPosition(800,0);

    score = 0;
}

//Classe singleton
GestionPanneau* GestionPanneau::inst = NULL;

void GestionPanneau::makeInst()
{
    if (inst == NULL) inst = new GestionPanneau();
}


GestionPanneau& GestionPanneau::getInst()
{
    return *inst;
}

//Toutes les frames , on met a jour le chrono a afficher
void GestionPanneau::setTime(float time)
{
    text_time.SetText(float2string((int)time));
}

//Affiche tous les éléments du panneau
void GestionPanneau::afficher(sf::RenderWindow &App)
{
    text_score.SetText("Score :\n" + float2string((float)score));
    App.Draw(my_sprite_cadre);
    App.Draw(my_sprite_phase);
    App.Draw(text_time);
    App.Draw(text_explication);
    App.Draw(text_score);
    App.Draw(text_difficulte);
}

//Indique un changement de phase , met a jour les donnees a afficher en conséquence
void GestionPanneau::setPhase(int phaseI)
{
    phase=phaseI;
    switch(phaseI)
    {
        case -1 :
            text_explication.SetText("Cliquez\npour commencer.");
            break;
        case 0 :
            my_sprite_phase.SetImage(*imagePhaseConstr);
            text_explication.SetText("Construction : \nVous devez entourer \nles forteresses");
            break;
        case 1 :
            my_sprite_phase.SetImage(*imagePhaseCanon);
            text_explication.SetText("Placez vos canons");
            break;
        case 2 :
            my_sprite_phase.SetImage(*imagePhaseCombat);
            text_explication.SetText("Combat :\nDétruisez les \nnavires!");
            break;
        case 3 :
            my_sprite_phase.SetImage(*imagePhaseConstr);
            text_explication.SetText("Reconstruction :\nVous devez entourer \nles forteresses");
            break;
        default :
            text_explication.SetText("Erreur");
            break;
    }
}

//Ajoute un nombre au score
void GestionPanneau::addScore(long ajout_score)
{
    score = score + ajout_score;
}

//Pendant la phase de placement des canons , indique combien de canons disponibles a afficher
void GestionPanneau::setNbCanon(int nombre_de_canon_posable)
{
    text_explication.SetText("Placez vos canons : \n" + float2string((float)nombre_de_canon_posable) + " à poser" );
}

//Donne la difficulté
void GestionPanneau::setDifficulte(int dif)
{
    switch(dif)
    {//Selon la difficulté on change le texte a afficher
        case 1:
            text_difficulte.SetColor(sf::Color(0,255,0,255));
            text_difficulte.SetText("Facile");
            break;
        case 2:
            text_difficulte.SetColor(sf::Color(255,160,0,255));
            text_difficulte.SetText("Normal");
            break;
        case 3:
            text_difficulte.SetColor(sf::Color(255,0,0,255));
            text_difficulte.SetText("Difficile");
            break;
    }
}


