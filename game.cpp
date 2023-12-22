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
    this->j1 = 0;
    this->j2 = 0;

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
            m_raquetteRight.input(event.key.code, true);
        }
        if (event.type == sf::Event::KeyReleased)
        {
            m_raquetteLeft.input(event.key.code, false);
            m_raquetteRight.input(event.key.code, false);
        }
    }
    this->affichageScore(score, std::to_string(j1) + " | " + std::to_string(j2));

    this->m_ball->avancer();
    this->m_ball->rebonWindow();
    this->reaparition();
    this->rebond(m_raquetteRight, m_raquetteLeft);

    this->chekInput();
    this->m_raquetteLeft.update();        
    this->m_raquetteRight.update();
    this->m_ball->update();
    this->m_raquetteLeft.chekRebort();
    this->m_raquetteRight.chekRebort();

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void pong::gameAffichage()
{
    this->changementDeCouleur();

    this->window.draw(this->score);
    this->window.draw(m_raquetteRight.getRaquette());
    this->window.draw(m_raquetteLeft.getRaquette());
    this->window.draw(m_ball->getBall());

    this->window.display();
}

void pong::reaparition()
{
    if (m_ball->getX() > 800 - m_ball->getTail())
    {
        delete m_ball;
        m_ball = new Ball(400.f,300.f);

        m_ball->setX((largeur + m_ball->getTail())/2);
        m_ball->setY((hauteur + m_ball->getTail())/2);
        m_ball->setOrientation(1,1);
        m_ball->setOrientation(2,1);

        this->j1++;
    }
    else if (m_ball->getX()<0)
    {
        delete m_ball;
        m_ball = new Ball(400.f,300.f);

        m_ball->setX((largeur + m_ball->getTail())/2);
        m_ball->setY((hauteur + m_ball->getTail())/2);
        m_ball->setOrientation(1,1);
        m_ball->setOrientation(2,1);

        this->j2++;
    }
}

void pong::chekInput()
{
    if(this->m_raquetteLeft.getDown(1))
    {
        this->m_raquetteLeft.setY(this->m_raquetteLeft.getY() + 5.0f);
    }
    if(this->m_raquetteLeft.getUp(1))
    {
        this->m_raquetteLeft.setY(this->m_raquetteLeft.getY() - 5.0f);
    }

    if(this->m_raquetteRight.getDown(0))
    {
        this->m_raquetteRight.setY(this->m_raquetteRight.getY() + 5.0f);
    }
    if(this->m_raquetteRight.getUp(0))
    {
        this->m_raquetteRight.setY(this->m_raquetteRight.getY() - 5.0f);
    }
}

void pong::rebond(Raquette droit, Raquette gauche)
{
    if (m_ball->getY() > gauche.getY() && m_ball->getY() < gauche.getY() + gauche.getHauteur() && m_ball->getX() == gauche.getX() + gauche.getLargeur()
    || m_ball->getY() > droit.getY() && m_ball->getY() < droit.getY() + droit.getHauteur() && m_ball->getX() + m_ball->getTail() == droit.getX())
    {
        m_ball->setOrientation(2, m_ball->getOrientation(2) * -1);
    }
}

void pong::changementDeCouleur()
{
    int r = 0;
    int g = 0;
    int b = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        r = 80;
        g = 200;
        b = 255;
    }

    window.clear(sf::Color(r,g,b));
}

void pong::affichageScore(sf::Text &txt,sf::String str)
{
    font.loadFromFile("ressource/arial_narrow_7.ttf");

    txt.setFont(font);
    txt.setString(str);
    txt.setCharacterSize(26);
    txt.setFillColor(sf::Color::White);
    txt.setPosition((largeur / 2) - 40, 10);
}