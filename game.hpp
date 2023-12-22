#ifndef GAME_HPP
#define GAME_HPP
#include "main.hpp"

class pong
{
private:
    int hauteur = 600;
    int largeur = 800;
    int j1;
    int j2;
    char temp[256];

    sf::RenderWindow window;
    sf::Event event;
    sf::Text score;
    sf::Font font;

    Raquette m_raquetteLeft;
    Raquette m_raquetteRight;

    Ball* m_ball;

public:
    pong();
    ~pong();
    void game();
    void gameLoop();
    void gameAffichage();
    void reaparition();
    void chekInput();
    void rebond(Raquette droit, Raquette gauche);
    void changementDeCouleur();
    void affichageScore(sf::Text &txt, sf::String str);

};

#endif