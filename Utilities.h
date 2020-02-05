#pragma once

#include <iostream>
#include <vector>

#include "Global.h"

/*
    UTILITIES CLASS

    Constructor's parameters: none;

    About this class:
    - It contains some useful functions.
*/

class Utilities
{
public:
    //Constructors / Destructors
    Utilities();
    virtual ~Utilities();

    //Functions
    sf::Vector2f adjustToCamera(Global *global, sf::Vector2f entityPos);
    void cameraStickToX(Global *global, float entityPosX, float offset);
    void cameraStickToY(Global *global, float entityPosY, float offset);
    sf::Vector2f boundaryCollision(Global *global, sf::Vector2f entityPos, sf::Vector2f entityVel);
};