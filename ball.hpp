#ifndef BALL_HPP
#define BALL_HPP
#include "main.hpp"

class Ball
{
private :
    float m_tail;
    float m_y;
    float m_x;
    float m_vitesse = 2;
    double m_orientation[2] = {1,1};
    bool m_rePos;
    sf::CircleShape ball;

public :
    //fonction
    Ball(float m_y, float m_x);
    void avancer();
    void update();
    void rebonWindow();

    //get
    float getTail();
    float getY();
    float getX();
    float getVitesse();
    double getOrientation(int NT);
    bool getRePos();
    sf::CircleShape getBall();

    //set
    void setTail(float T);
    void setY(float Y);
    void setX(float X);
    void setVitesse(float V);
    void setOrientation(int NT, double ori);
    void setRePos(bool a);
};

#endif