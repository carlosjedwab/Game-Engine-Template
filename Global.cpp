#include "Global.h"

//Private functions
void Global::initVariables()
{
    this->videoMode  = sf::VideoMode(800*1.0, 480*1.0);
    this->boundaries = sf::VideoMode(800*1.0, 480*1.0);
    this->cameraOfst = sf::Vector2f(0.f, 0.f);
}

//Constructors / Destructors
Global::Global()
{
    this->initVariables();
}

Global::~Global()
{
    
}

//Accessors
sf::VideoMode Global::getScreenSize()
{
    return this->videoMode;
}

void Global::setScreenSize(sf::VideoMode videoMode)
{
    this->videoMode = videoMode;
}

sf::VideoMode Global::getBoundaries()
{
    return this->boundaries;
}

void Global::setBoundaries(sf::VideoMode boundaries)
{
    this->boundaries = boundaries;
}

sf::Vector2f Global::getMousePos()
{
    return this->mousePosView;
}

void Global::setMousePos(sf::Vector2f mousePosView)
{
    this->mousePosView = mousePosView;
}

sf::Vector2f Global::getCameraOfst()
{
    return this->cameraOfst;
}

void Global::setCameraOfst(sf::Vector2f cameraOfst)
{
    this->cameraOfst = cameraOfst;
}

sf::Event Global::getEvent()
{
    return this->event;
}

void Global::setEvent(sf::Event event)
{
    this->event = event;
}