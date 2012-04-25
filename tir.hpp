#include <SFML/Graphics.hpp>

class Tir
{
public :

    Tir(sf::Vector2f position, int size_ver,int size_hor, int speed , sf::Vector2f aim);

    bool move();

    sf::Sprite getSprite();
    sf::IntRect getBoundingBox(); // Retourne la boîte englobante de l'image de la balle

private :

    sf::Sprite my_sprite;
    sf::Image my_image;

    sf::Vector2f my_position;
    sf::Vector2f my_aim;
    int my_size_ver; // Taille
    int my_size_hor; // Taille
    float my_dx; // Déplacement en X
    float my_dy; // Déplacement en Y
    int my_speed; // Vitesse
    float distance_x;
    float distance_y;
};


