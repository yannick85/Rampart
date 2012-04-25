#define LARGEUR_FENETRE 1000
#define HAUTEUR_FENETRE 600
#define CASE 15

#include "Map.h"
#include "Forme.h"
#include <time.h>
#include <sstream>
#include <string>
#include "collisionManager.hpp"
#include "GestionBateau.h"
#include "GestionCanon.h"
#include "GestionMur.h"
#include "GestionPanneau.h"
#include "Forteresse.h"
#include "CaseOccupee.h"
#include "ImageManager.h"

using namespace std;
using namespace sf;

int main()
{
    //Creation de la fenêtre de rendu
    RenderWindow App(VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32), "Rampart", Style::Titlebar | Style::Close);
    App.SetFramerateLimit(60);//60 frame par seconde

    Event evenement;

    //Creation des instance de singleton
    Map::makeInst(1);
    GestionBateau::makeInst();
    GestionCanon::makeInst();
    GestionMur::makeInst();
    GestionPanneau::makeInst();

    //CREATION FORTERESSE
    //Creation des coordonnées de chaque forteresse
    int tab_fort[5][2];
    tab_fort[0][0]=7;
    tab_fort[0][1]=6;

    tab_fort[1][0]=5;
    tab_fort[1][1]=20;

    tab_fort[2][0]=22;
    tab_fort[2][1]=4;

    tab_fort[3][0]=38;
    tab_fort[3][1]=9;

    tab_fort[4][0]=10;
    tab_fort[4][1]=30;

    int num_fort =0;

    //Une Forteresse dans le jeu équivaut a une classe forteresse sur une case et 3 caseOccupee qui empeche de construire sur le sprite de la forteresse
    //pour simuler une forteresse de 4 cases
    Forteresse fort0 = Forteresse(tab_fort[num_fort][0],tab_fort[num_fort][1]);
    CaseOccupee co01 = CaseOccupee(tab_fort[num_fort][0]+1,tab_fort[num_fort][1]);
    CaseOccupee co02 = CaseOccupee(tab_fort[num_fort][0],tab_fort[num_fort][1]+1);
    CaseOccupee co03 = CaseOccupee(tab_fort[num_fort][0]+1,tab_fort[num_fort][1]+1);

    num_fort=1;

    Forteresse fort1 = Forteresse(tab_fort[num_fort][0],tab_fort[num_fort][1]);
    CaseOccupee co11 = CaseOccupee(tab_fort[num_fort][0]+1,tab_fort[num_fort][1]);
    CaseOccupee co12 = CaseOccupee(tab_fort[num_fort][0],tab_fort[num_fort][1]+1);
    CaseOccupee co13 = CaseOccupee(tab_fort[num_fort][0]+1,tab_fort[num_fort][1]+1);

    num_fort=2;

    Forteresse fort2 = Forteresse(tab_fort[num_fort][0],tab_fort[num_fort][1]);
    CaseOccupee co21 = CaseOccupee(tab_fort[num_fort][0]+1,tab_fort[num_fort][1]);
    CaseOccupee co22 = CaseOccupee(tab_fort[num_fort][0],tab_fort[num_fort][1]+1);
    CaseOccupee co23 = CaseOccupee(tab_fort[num_fort][0]+1,tab_fort[num_fort][1]+1);

    num_fort=3;

    Forteresse fort3 = Forteresse(tab_fort[num_fort][0],tab_fort[num_fort][1]);
    CaseOccupee co31 = CaseOccupee(tab_fort[num_fort][0]+1,tab_fort[num_fort][1]);
    CaseOccupee co32 = CaseOccupee(tab_fort[num_fort][0],tab_fort[num_fort][1]+1);
    CaseOccupee co33 = CaseOccupee(tab_fort[num_fort][0]+1,tab_fort[num_fort][1]+1);

    num_fort=4;

    Forteresse fort4 = Forteresse(tab_fort[num_fort][0],tab_fort[num_fort][1]);
    CaseOccupee co41 = CaseOccupee(tab_fort[num_fort][0]+1,tab_fort[num_fort][1]);
    CaseOccupee co42 = CaseOccupee(tab_fort[num_fort][0],tab_fort[num_fort][1]+1);
    CaseOccupee co43 = CaseOccupee(tab_fort[num_fort][0]+1,tab_fort[num_fort][1]+1);


    //FIN CREATION FORTERESSE

    //DEBUT CHOIX DIFFICULTE
    int difficulte;

    //Creation de chaque sprite de choix de difficulté
    Image *image_facile = ImageManager::Inst().getImage("images/facile.png");
    Sprite sprite_facile;
    sprite_facile.SetImage(*image_facile);
    sprite_facile.SetPosition(120,270);
    sprite_facile.SetSubRect(IntRect(0,0,160,60));

    Image *image_normal = ImageManager::Inst().getImage("images/normal.png");
    Sprite sprite_normal;
    sprite_normal.SetImage(*image_normal);
    sprite_normal.SetPosition(320,270);
    sprite_normal.SetSubRect(IntRect(0,0,160,60));

    Image *image_difficile = ImageManager::Inst().getImage("images/difficile.png");
    Sprite sprite_difficile;
    sprite_difficile.SetImage(*image_difficile);
    sprite_difficile.SetPosition(520,270);
    sprite_difficile.SetSubRect(IntRect(0,0,160,60));
    //FIN CHOIX DIFFICULTE

    int mouseX;
    int mouseY;

    srand(time(NULL));
    Forme *forme = NULL;

    Canon *canon = NULL;


    int phase=-1;//la phase -1 represente le choix de la difficulté
    int tour =1;

    Clock timer_phase;//Ce timer sera remis a zero a chaque debut de phase et servira a reperer la fin des phases
    bool debut_phase=true;
    float max_temps;

    int nombre_de_canon_posable;

    String message_fin;

    while(App.IsOpened())//Boucle infini tant qu'on ne ferme pas la fenetre
    {

        App.Clear();//On vide la fenetre de tout ses éléments


        while(App.GetEvent(evenement))//On recupère les évenements utilisateur
        {
            //Cas où on ferme la fenetre
            if (evenement.Type == Event::Closed) App.Close();

            //Cas où on appuie sur Echap
            if (evenement.Type == Event::KeyPressed && evenement.Key.Code == Key::Escape) App.Close();

            switch(phase)
            {
                case -1 :
                    //gestion de la souris : déplacement
                    if (evenement.Type == Event::MouseMoved)
                    {
                        mouseX = evenement.MouseMove.X;
                        mouseY = evenement.MouseMove.Y;

                        if((mouseX>120 & mouseX < 280)and(mouseY>270 & mouseY<330))//Quand l'utilisateur est sur facile , on change le sprite pour lui monter l'interaction possible
                        {
                            sprite_facile.SetSubRect(IntRect(0,60,160,120));
                        }else
                        {
                            sprite_facile.SetSubRect(IntRect(0,0,160,60));
                        }

                        if((mouseX> 320& mouseX < 480)and(mouseY>270 & mouseY<330))//De même pour normal
                        {
                            sprite_normal.SetSubRect(IntRect(0,60,160,120));
                        }else
                        {
                            sprite_normal.SetSubRect(IntRect(0,0,160,60));
                        }

                        if((mouseX>520 & mouseX < 680)and(mouseY>270 & mouseY<330))//De même pour difficile
                        {
                            sprite_difficile.SetSubRect(IntRect(0,60,160,120));
                        }else
                        {
                            sprite_difficile.SetSubRect(IntRect(0,0,160,60));
                        }
                    }

                    if (evenement.Type == Event::MouseButtonPressed)
                    {
                        if((mouseX>120 & mouseX < 280)and(mouseY>270 & mouseY<330))//Clic sur facile
                        {
                            difficulte = 1;
                            phase=0;//Passage en phase construction
                            forme = new Forme(rand()%10 + 1,mouseX/CASE,mouseY/CASE);//Preparation de la phase construction , nouvelle forme aléatoire
                        }

                        if((mouseX> 320& mouseX < 480)and(mouseY>270 & mouseY<330))
                        {
                            difficulte = 2;
                            phase=0;
                            forme = new Forme(rand()%10 + 1,mouseX/CASE,mouseY/CASE);
                        }

                        if((mouseX>520 & mouseX < 680)and(mouseY>270 & mouseY<330))
                        {
                            difficulte = 3;
                            phase=0;
                            forme = new Forme(rand()%10 + 1,mouseX/CASE,mouseY/CASE);
                        }
                        GestionPanneau::getInst().setDifficulte(difficulte);
                    }
                    break;
                case 0: //Placement des murs
                    //gestion de la souris : déplacement
                    if (evenement.Type == Event::MouseMoved)
                    {
                        mouseX = evenement.MouseMove.X;//Recuperation des coordonnes de la souris
                        mouseY = evenement.MouseMove.Y;

                        forme->setPosition(mouseX/CASE, mouseY/CASE);
                    }


                    //gestion de la souris : roulette
                    if(evenement.Type == sf::Event::MouseWheelMoved)
                    {
                        if (evenement.MouseWheel.Delta > 0)
                        {
                            forme->rotateLeft();//Rotation de la forme
                            forme->setPosition(mouseX/CASE, mouseY/CASE);
                        }
                        else if (evenement.MouseWheel.Delta < 0)
                        {
                            forme->rotateRight();
                            forme->setPosition(mouseX/CASE, mouseY/CASE);
                        }
                    }



                    //gestion de la souris : clic
                    if (evenement.Type == Event::MouseButtonPressed)
                    {

                        if (evenement.MouseButton.Button == Mouse::Left)
                        {

                            if (forme->convertToWall() == true)//Si les murs se sont construit avec succès (si il était en zone valide)
                            {
                                delete forme;
                                forme = new Forme(rand()%10 + 1, mouseX/CASE, mouseY/CASE);//Creation d'une nouvelle forme

                                Map::Inst().verifMur(true);//Vérifie si il existe des zones fermées , true pour ajouter les éventuelles cases fermées au score
                            }
                        }
                    }

                    break;
                case 1://Placement des canons
                    //gestion de la souris : déplacement
                    if (evenement.Type == Event::MouseMoved)
                    {
                        mouseX = evenement.MouseMove.X;
                        mouseY = evenement.MouseMove.Y;

                        canon->setPosition(mouseX/CASE, mouseY/CASE);
                        canon->selectSpriteAboutPosition();//Met le canon en rouge si il est en zone invalide
                    }


                    //gestion de la souris : clic
                    if (evenement.Type == Event::MouseButtonPressed)
                    {

                        if (evenement.MouseButton.Button == Mouse::Left)
                        {
                            if (canon->validPosition())//Si la position du canon est bonne
                            {
                                canon->setFixe();//on le fixe
                                canon = new Canon();//Creation d'un nouveau canon pour le prochain placement
                                canon->setPosition(mouseX/CASE, mouseY/CASE);
                                canon->selectSpriteAboutPosition();
                                nombre_de_canon_posable--;//un canon en moins a poser
                            }
                        }
                    }

                    break;
                case 2://Tir
                    //gestion de la souris : déplacement
                    if (evenement.Type == Event::MouseMoved)
                    {
                        mouseX = evenement.MouseMove.X;
                        mouseY = evenement.MouseMove.Y;
                        GestionCanon::getInst().tournerViseur(mouseX,mouseY);//tourne tous les canons actifs vers le pointeur de la souris

                    }

                    //gestion de la souris : clic
                    if (evenement.Type == Event::MouseButtonPressed)
                    {
                        Mouse::Button button = evenement.MouseButton.Button;

                        if (button == Mouse::Left)
                        {
                            GestionCanon::getInst().tirer(mouseX,mouseY);//fera tirer le premier canon disponible
                        }
                    }

                    break;
                case 3://Reparation -> 1
                    //gestion de la souris : déplacement
                    if (evenement.Type == Event::MouseMoved)
                    {
                        mouseX = evenement.MouseMove.X;
                        mouseY = evenement.MouseMove.Y;

                        forme->setPosition(mouseX/CASE, mouseY/CASE);
                    }


                    //gestion de la souris : roulette
                    if(evenement.Type == sf::Event::MouseWheelMoved)
                    {
                        if (evenement.MouseWheel.Delta > 0)
                        {
                            forme->rotateLeft();//tourne la forme
                            forme->setPosition(mouseX/CASE, mouseY/CASE);
                        }
                        else if (evenement.MouseWheel.Delta < 0)
                        {
                            forme->rotateRight();
                            forme->setPosition(mouseX/CASE, mouseY/CASE);
                        }
                    }



                    //gestion de la souris : clic
                    if (evenement.Type == Event::MouseButtonPressed)
                    {

                        if (evenement.MouseButton.Button == Mouse::Left)
                        {

                            if (forme->convertToWall() == true)//Si les murs se sont bien placés
                            {
                                delete forme;
                                forme = new Forme(rand()%10 + 1, mouseX/CASE, mouseY/CASE);//Nouvelle forme a poser

                                Map::Inst().verifMur(true);//Verifie si il existe des zones fermés , true pour ajouter au score les éventuelles cases fermées
                            }
                        }
                    }

                    break;
            }
        }

        Map::Inst().displayMap(App);//Affiche le fond de la carte
        Map::Inst().displayObjects(App);//Affiche tous les objets immobiles : murs , canons , forteresses

        switch(phase)//Selon la phase
        {
            case -1://Choix de la difficulté
                //
                GestionPanneau::getInst().setPhase(phase);//Informe la panneau de droite de la difficulté a afficher
                message_fin.SetText("Bienvenue dans Rampart");//Message de bienvenue
                message_fin.SetPosition(100,100);
                //Affichage du message de bienvenue ainsi que des sprite de choix de difficulté
                App.Draw(message_fin);
                App.Draw(sprite_facile);
                App.Draw(sprite_normal);
                App.Draw(sprite_difficile);
                break;
            case 0://Construction
                if(debut_phase)
                {
                    timer_phase.Reset();
                    GestionPanneau::getInst().setPhase(phase);
                    switch(difficulte)
                    {
                        case 1:
                            max_temps = 30;
                            break;
                        case 2:
                            max_temps = 25;
                            break;
                        case 3:
                            max_temps = 20;
                            break;
                    }
                    debut_phase=false;
                    GestionMur::getInst().nettoyerMur();
                }

                forme->displayForme(App);
                fort0.checkProt();
                fort1.checkProt();
                fort2.checkProt();
                fort3.checkProt();
                fort4.checkProt();

                if(timer_phase.GetElapsedTime()>max_temps)
                {
                    //Check du nombe de canon posable selon le nombre de forteresse protégé
                    phase=1;
                    nombre_de_canon_posable=Map::Inst().getNombreCanonPosable(tab_fort);
                    if(nombre_de_canon_posable == 1)
                    {
                        phase = 4;
                    }
                    if(nombre_de_canon_posable == 6)
                    {
                        phase = 5;
                    }
                    debut_phase=true;
                    timer_phase.Reset();
                    delete forme;
                    canon = new Canon();
                    canon->setPosition(mouseX/CASE, mouseY/CASE);
                    canon->selectSpriteAboutPosition();
                }
                break;
            case 1:
                if(debut_phase)
                {
                    GestionPanneau::getInst().setPhase(phase);
                    switch(difficulte)
                    {
                        case 1:
                            max_temps = 20;
                            break;
                        case 2:
                            max_temps = 15;
                            break;
                        case 3:
                            max_temps = 10;
                            break;
                    }
                    debut_phase=false;
                }

                GestionPanneau::getInst().setNbCanon(nombre_de_canon_posable);
                canon->displayCanon(App);

                if(timer_phase.GetElapsedTime()>max_temps or nombre_de_canon_posable == 0)
                {
                    phase=2;
                    debut_phase=true;
                    timer_phase.Reset();
                    delete canon;
                }
                break;
            case 2:
                if(debut_phase)
                {
                    GestionPanneau::getInst().setPhase(phase);
                    switch(difficulte)
                    {
                        case 1:
                            max_temps = 15;
                            break;
                        case 2:
                            max_temps = 15;
                            break;
                        case 3:
                            max_temps = 20;
                            break;
                    }
                    GestionBateau::getInst().creerBateau(tour,difficulte);
                    GestionCanon::getInst().verifPosCanon();
                    debut_phase=false;
                }
                GestionCanon::getInst().update();
                GestionBateau::getInst().update();
                GestionCanon::getInst().afficherTir(App);
                GestionBateau::getInst().afficher(App);

                if(timer_phase.GetElapsedTime()>max_temps)
                {
                    tour++;
                    phase=3;
                    debut_phase=true;
                    timer_phase.Reset();
                    GestionCanon::getInst().nettoyer();
                    GestionBateau::getInst().nettoyer();
                    forme = new Forme(rand()%10 + 1, mouseX/CASE, mouseY/CASE);
                }
                break;
            case 3:
                if(debut_phase)
                {
                    GestionPanneau::getInst().setPhase(phase);
                    switch(difficulte)
                    {
                        case 1:
                            max_temps = 22;
                            break;
                        case 2:
                            max_temps = 20;
                            break;
                        case 3:
                            max_temps = 15;
                            break;
                    }
                    debut_phase=false;
                    GestionMur::getInst().nettoyerMur();
                    Map::Inst().reinitMap();
                    Map::Inst().verifMur(false);
                }

                forme->displayForme(App);
                fort0.checkProt();
                fort1.checkProt();
                fort2.checkProt();
                fort3.checkProt();
                fort4.checkProt();

                if(timer_phase.GetElapsedTime()>max_temps)
                {
                    phase=1;
                    //Check du nombe de canon posable selon le nombre de forteresse protégé
                    nombre_de_canon_posable=Map::Inst().getNombreCanonPosable(tab_fort);
                    if(nombre_de_canon_posable == 1)
                    {
                        phase = 4;
                    }
                    if(nombre_de_canon_posable == 6)
                    {
                        phase = 5;
                    }
                    debut_phase=true;
                    timer_phase.Reset();
                    delete forme;
                    canon = new Canon();
                    canon->setPosition(mouseX/CASE, mouseY/CASE);
                    canon->selectSpriteAboutPosition();
                }
                break;
            case 4 ://DEFAITE
                message_fin.SetText("ECHEC");
                message_fin.SetPosition(380,280);
                App.Draw(message_fin);
                break;
            case 5 ://VICTOIRE
                message_fin.SetText("VICTOIRE");
                message_fin.SetPosition(380,280);
                App.Draw(message_fin);
                break;

        }

        if(phase != 4 and phase != 5 and phase != -1)
        {
            GestionPanneau::getInst().setTime(max_temps-timer_phase.GetElapsedTime());
        }

        GestionPanneau::getInst().afficher(App);

        App.Display();
    }
}


