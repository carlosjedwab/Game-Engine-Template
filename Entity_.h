#pragma once

#include <iostream>
#include <vector>

#include "Global.h"
#include "Utilities.h"

/*
    ENTITY CLASS

    Constructor's parameters: 
    - Global* global

    About this class:
    - This class is a template for entity type classes.
    - To change the class name:
        - Firstly, ctrl+d 'Entity_' and change it to the new class name (uppercase first character);
        - Secondly ctrl+d 'entity'  and change it to the new class name (lowercase first character);
        - Do this for both .h and .cpp files;
        - Change at the beginning of this comment section the full uppercase class name too.
          (In fact, change this entire comment section).
    - POSSIBLE ERRORS. Don't forget to add the new class name to the run.py and change the #include 
      and entities declaration at Game.h.
*/

class Entity_
{
private:
    //Variables
    //Global variables
    Global* global;

    //Custom constants (maxEntities, maxSize...)

    //Game logic (counters, nEntities...)

    //Game objects
    sf::Vector2f entityPos;
    sf::Vector2f entityVel;
    sf::CircleShape shape;
    
    //Private functions
    void initVariables();
    void initShape();

public:
    //Constructors / Destructors
    Entity_(Global* global);
    virtual ~Entity_();

    //Accessors
    Utilities utilities;

    //Functions
    void update(float dt);
    void render(sf::RenderTarget* target);
};