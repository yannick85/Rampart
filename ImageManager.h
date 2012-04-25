#ifndef IMAGEMANAGER_H_INCLUDED
#define IMAGEMANAGER_H_INCLUDED

//************************************************************
//******************* CLASSE : Header ************************
//************************************************************
//*** NOM :      ImageManager                                *
//*** FONCTION : Sert � manager les ressources de type image *
//*** NOTES :    Cette classe est un singleton               *
//************************************************************

#include <map>
#include <iostream>
#include <SFML/graphics.hpp>


class ImageManager
{
    private :

        ImageManager(); //Constructeur en mode PRIVATE : Cette classe est un singleton.

        static ImageManager *m_Inst; //Pointeur vers l'unique instance d'ImageManager

        std::map<std::string, sf::Image*> images; //Std::map pour stocker les images.


    public :

        static ImageManager &Inst(); //Fonction renvoyant l'unique instance d'ImageManager, permettant de l'appeler dans toute fonction.

        sf::Image* createImage(const std::string &chemin); //Charge une image en m�moire.
        sf::Image* searchImage(const std::string &chemin); //Cherche si une image est charg�e en m�moire.
        sf::Image* getImage(const std::string &chemin); //R�cup�re une image charg�e � partir de son chemin. Si l'image n'est pas charg�e, le programme tente de la charger.

};

#endif // IMAGEMANAGER_H_INCLUDED
