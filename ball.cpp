#include "main.hpp"

//fonction
Ball::Ball(float m_x, float m_y)
{
    m_tail = 10.f;
    m_y;
    m_x;
    m_vitesse = 2;
    m_orientation[2];
    m_rePos;
    ball.setRadius(m_tail);
    ball.setPosition(sf::Vector2f(m_x, m_y));
    ball.setFillColor(sf::Color::White);
}

void Ball::update()
{
    this->ball.setPosition(sf::Vector2f(this->getX(), this->getY()));
}

void Ball::avancer()
{
    this->setOrientation(1,1);
    this->setOrientation(2,1);

    this->setY(this->getY() + this->getVitesse() * getOrientation(1));
    this->setX(this->getX() + this->getVitesse() * getOrientation(2));
}

void Ball::rebonWindow()
{
    if (this->getY() > 600)
    {
        this->setOrientation(1, this->getOrientation(1) * -1);
    }
}

//get
float Ball::getTail()
{
    return m_tail;
}

float Ball::getY()
{
    return m_y;
}

float Ball::getX()
{
    return m_x;
}

float Ball::getVitesse()
{
    return m_vitesse;
}

double Ball::getOrientation(int NT)
{
    return m_orientation[NT];
}

sf::CircleShape Ball::getBall()
{
    return ball;
}

//set
void Ball::setTail(float T)
{
    m_tail = T;
}

void Ball::setY(float Y)
{
    m_y = Y;
}

void Ball::setX(float X)
{
    m_x = X;
}

void Ball::setVitesse(float V)
{
    m_vitesse = V;
}

void Ball::setOrientation(int NT, double ori)
{
    m_orientation[NT] = ori;
}

void Ball::setRePos(bool a)
{
    m_rePos = a;
}