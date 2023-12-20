#include "main.hpp"

pong::pong() : m_raquetteLeft(20.f), m_raquetteRight(760.f), m_ball(nullptr)
{
    Raquette &raquetteLeft = m_raquetteLeft;
    Raquette &raquetteRight = m_raquetteRight;

    srand(time(nullptr));

    m_ball = new Ball(300.f,400.f);
}

pong::~pong()
{
    delete m_ball;
}

void pong::game()
{
    this->m_raquetteLeft.setHauteur(100);
    this->m_raquetteRight.setLargeur(20);
    this->m_raquetteLeft.setX(20.f);
    this->m_raquetteRight.setX(largeur - (m_raquetteLeft.getX() + 20));
    this->m_raquetteLeft.setY((hauteur - m_raquetteLeft.getHauteur()) /2);
    this->m_raquetteRight.setY((hauteur - m_raquetteRight.getHauteur()) /2);
    this->m_raquetteLeft.setRaquetteNum(1);
    this->m_raquetteRight.setRaquetteNum(2);

    this->m_ball->setOrientation(1,1);
    this->m_ball->setOrientation(2,1);
    this->m_ball->setTail(10);
    this->m_ball->setX((this->largeur - this->m_ball->getTail()) /2);
    this->m_ball->setY((this->hauteur - this->m_ball->getTail()) /2);

    this->window.create(sf::VideoMode(largeur, hauteur), "pong");

    while (this->window.isOpen())
    {
        this->gameLoop();

        this->gameAffichage();
    }
}

void pong::gameLoop()
{
    while (this->window.pollEvent(this->event))
    {
        if (this->event.type == sf::Event::Closed)
        {
            this->window.close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            m_raquetteLeft.input(event.key.code, true);
        }
        if (event.type == sf::Event::KeyReleased)
        {
            m_raquetteLeft.input(event.key.code, false);
        }
    }

    this->m_ball->avancer();
    this->m_ball->rebonWindow();

    this->m_raquetteLeft.update(1);        
    this->m_raquetteRight.update(2);
    this->m_ball->update();

    std::this_thread::sleep_for(std::chrono::milliseconds(20));
}

void pong::gameAffichage()
{
    this->window.clear(sf::Color(0,0,0));

    this->window.draw(m_raquetteRight.getRaquette());
    this->window.draw(m_raquetteLeft.getRaquette());
    this->window.draw(m_ball->getBall());

    this->window.display();
}

void pong::reaparition()
{
    if (this->m_ball->rebonWindow())
    {
        delete m_ball;
        m_ball = new Ball(300.f,400.f);

        m_ball->setY((largeur + m_ball->getTail())/2);
        m_ball->setX((hauteur + m_ball->getTail())/2);

        m_ball->update();
    }
    else
    {
        m_ball->update();
    }
}