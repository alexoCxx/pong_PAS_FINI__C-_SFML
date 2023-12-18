#include "main.hpp"

//fonction
Raquette::Raquette(float m_x)
{
    m_vitesse;
    m_hauteur = 100.f;
    m_largeur = 20.f;
    m_y;
    m_x;
    m_raquetteNum;
    up[2] = {false};
    down[2] = {false};
    m_raquette.setSize(sf::Vector2f(m_largeur, m_hauteur));
    m_raquette.setPosition(sf::Vector2f(m_y,m_x));
}

void Raquette::input(sf::Keyboard::Key key, bool chekPressed)
{
    if (chekPressed == true)
    {
        if (key == sf::Keyboard::A)
            up[1] = true;
        if (key == sf::Keyboard::Q)
            down[1] = true;

        if (key == sf::Keyboard::P)
            up[2] = true;
        if (key == sf::Keyboard::M)
            down[2] = true;
    }
    else if (chekPressed == false)
    {
        up[1] = false;
        down[1] = false;

        up[2] = false;
        down[2] = false;
    }
}

void Raquette::update(int a)
{
    if (up[a])
    {
        setY(getY() - 1.f);
    }
    else if (down[a])
    {
        setY(getY() + 1.0f);
    }

    m_raquette.setPosition(sf::Vector2f(getX(), getY()));
}

void Raquette::chekRebort()
{
    std::cout << this->getY() << std::endl;

    if (this->getY() <= 0)
    {
        this->setY(0);
    }
    else if (this->getY() + this->getHauteur() >= 600)
    {
        this->setY(600 - this->getHauteur());
    }
}

//get
bool Raquette::getUp(int NT)
{
    return up[NT];
}

bool Raquette::getDown(int NT)
{
    return down[NT];
}

int Raquette::getVitesse()
{
    return m_vitesse;
}

float Raquette::getHauteur()
{
    return m_hauteur;
}

float Raquette::getLargeur()
{
    return m_largeur;
}

float Raquette::getY()
{
    return m_y;
}

float Raquette::getX()
{
    return m_x;
}

int Raquette::getRaquetteNum()
{
    return m_raquetteNum;
}

sf::RectangleShape Raquette::getRaquette()
{
    return m_raquette;
}

//set
void Raquette::setUp(bool a, int NT)
{
    up[NT] = a;
}

void Raquette::setDown(bool a, int NT)
{
    down[NT] = a;
}

void Raquette::setVitesse(int V)
{
    m_vitesse = V;
}

void Raquette::setHauteur(float H)
{
    m_hauteur = H;
}

void Raquette::setLargeur(float L)
{
    m_largeur = L;
}

void Raquette::setY(float Y)
{
    m_y = Y;
}

void Raquette::setX(float X)
{
    m_x = X;
}

void Raquette::setRaquetteNum(int RN)
{
    m_raquetteNum = RN;
}