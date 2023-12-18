#ifndef GAME_HPP
#define GAME_HPP
#include "main.hpp"

class pong
{
private:
    int hauteur = 600;
    int largeur = 800;

    sf::RenderWindow window;
    sf::Event event;
    sf::Text score;

    Raquette m_raquetteLeft;
    Raquette m_raquetteRight;

    Ball* m_ball;

public:
    pong();
    ~pong();
    void game();
    void gameLoop();
    void gameAffichage();

};

#endif