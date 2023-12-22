#ifndef RAQUETTE_HPP
#define RAQUETTE_HPP
#include "main.hpp"

class Raquette
{
private :
    int m_vitesse;
    float m_hauteur = 100.f;
    float m_largeur = 20.f;
    float m_y;
    float m_x;
    int m_raquetteNum;
    bool up[2] = {false, false};
    bool down[2] = {false, false};
    sf::RectangleShape m_raquette;

public:
    //fonction
    Raquette(float m_x);
    void input(sf::Keyboard::Key key, bool chekPressed);
    void update();
    void chekRebort();

    //get
    bool getUp(int NT);
    bool getDown(int NT);
    int getVitesse();
    float getHauteur();
    float getLargeur();
    float getY();
    float getX();
    int getRaquetteNum();
    sf::RectangleShape getRaquette();

    //set
    void setUp(bool a, int NT);
    void setDown(bool a, int NT);
    void setVitesse(int V);
    void setHauteur(float H);
    void setLargeur(float L);
    void setY(float Y);
    void setX(float X);
    void setRaquetteNum(int RN); 
};

#endif