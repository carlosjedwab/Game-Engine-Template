#include "Utilities.h"

//Constructors / Destructors
Utilities::Utilities()
{
    
}
Utilities::~Utilities()
{
    
}

//Functions
sf::Vector2f Utilities::adjustToCamera(Global* global, sf::Vector2f entityPos)
{
    return entityPos - global->getCameraOfst();
}

void Utilities::cameraStickToX(Global *global, float entityPosX, float offset)
{
    global->setCameraOfst(sf::Vector2f(entityPosX+offset, global->getCameraOfst().y));
}

void Utilities::cameraStickToY(Global *global, float entityPosY, float offset)
{
    global->setCameraOfst(sf::Vector2f(global->getCameraOfst().x, entityPosY+offset));
}

sf::Vector2f Utilities::boundaryCollision(Global *global, sf::Vector2f entityPos, sf::Vector2f entityVel)
{
    if (entityPos.x > global->getBoundaries().width/2.f + global->getScreenSize().width/2.f)
        entityVel.x = -fabs(entityVel.x);
    if (entityPos.x < -(global->getBoundaries().width/2.f) + global->getScreenSize().width/2.f)
        entityVel.x = fabs(entityVel.x);
    if (entityPos.y > global->getBoundaries().height/2.f + global->getScreenSize().height/2.f)
        entityVel.y = -fabs(entityVel.y);
    if (entityPos.y < -(global->getBoundaries().height/2.f) + global->getScreenSize().height/2.f)
        entityVel.y = fabs(entityVel.y);

    return entityVel;
}