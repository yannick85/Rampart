//************************************************************
//**************** CLASSE : Implémentation *******************
//************************************************************
//*** NOM :      ImageManager                                *
//*** FONCTION : Sert à manager les ressources de type image *
//*** NOTES :    Cette classe est un singleton               *
//************************************************************

#include "ImageManager.h"

using namespace std;
using namespace sf;


ImageManager* ImageManager::m_Inst = NULL; //Classe singleton, le pointeur vers l'unique instance de l'objet est initialisé à NULL au départ.







//************************************************************
//*********************** CONSTRUCTEUR ***********************
//************************************************************
//*** NOTES :    Rien dans ce constructeur                   *
//************************************************************
ImageManager::ImageManager()
{

}







//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      Inst                                        *
//*** ENTREE :   /                                           *
//*** SORTIE :   L'unique instance d'ImageManager            *
//*** NOTES :    Créé l'instance si le pointeur m_Inst       *
//***            est à NULL                                  *
//************************************************************
ImageManager& ImageManager::Inst()
{
    if (m_Inst == NULL) m_Inst = new ImageManager();
    return *m_Inst;
}







//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      createImage                                *
//*** ENTREE :   Nom du chemin vers l'image (&chemin)        *
//*** SORTIE :   Pointeur sur sf::Image                      *
//*** NOTES :    Charge une image, et insert un pointeur     *
//***            vers cette image dans le std::map.          *
//************************************************************
Image* ImageManager::createImage(const string &chemin)
{
    if (searchImage(chemin) == NULL) //Si l'image n'existe pas
    {
        Image * image;
        image = new Image();

        //On charge l'image
        if(!image->LoadFromFile(chemin)) // Si le chargement a échoué
        {
            delete image;
            cerr <<"Erreur durant le chargement de l'image"<<endl; // On affiche l'erreur
            return NULL;
        }
        else
        {
            //Sinon on insert le pointeur vers l'image dans le std::map, et on le retourne.
            image->SetSmooth(false);
            images.insert(std::make_pair(chemin, image));
            return image;
        }
    }
}






//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      searchImage                                *
//*** ENTREE :   Nom du chemin vers l'image (&chemin)        *
//*** SORTIE :   Pointeur sur sf::Image                      *
//*** NOTES :    Vérifie si une image est déjà chargée       *
//************************************************************
Image* ImageManager::searchImage(const std::string &chemin)
{
    std::map<std::string, sf::Image*>::iterator it; //On déclare un iterator

    it = images.find(chemin); //On cherche l'image dans le std::map.

    if (it != images.end()) //Si on a trouvé
    {
        return it->second; //On retourne le pointeur vers l'image
    }
    else
    {
        return NULL; //Sinon on retourne NULL.
    }
}







//************************************************************
//************************* FONCTION *************************
//************************************************************
//*** NOM :      getImage                                   *
//*** ENTREE :   Nom du chemin vers l'image (&chemin)        *
//*** SORTIE :   Pointeur sur sf::Image                      *
//*** NOTES :    Récupère une image chargée. Si l'image      *
//***            n'est pas chargée, on tente de la charger   *
//************************************************************
Image* ImageManager::getImage(const std::string &chemin)
{
    Image * tmpimage;
    tmpimage = searchImage(chemin); //On cherche l'image
    if (tmpimage == NULL) //Si on ne la trouve pas
    {
        tmpimage = createImage(chemin); //On tente de la charger.
    }
    return tmpimage;
}
