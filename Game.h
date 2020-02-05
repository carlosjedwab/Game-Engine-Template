#pragma once

#include <iostream>
#include <vector>

#include "Entity_.h"

/*
    GAME CLASS

    Constructor's parameters: none;

    About this class:
    - It acts as the game engine/
      Wrapper class.
*/

class Game
{
private:
    //Variables
    Global global;

    //Window
    sf::RenderWindow* window;

    //Game objects
    Entity_ entity = Entity_(&global);
    
    //Private functions
    void initWindow();

public:
    //Constructors / Destructors
    Game();
    virtual ~Game();

    //Accessors
    const bool running() const;

    //Functions
    void pollEvents();
    void updateMousePositions();
    void update(float dt);
    void render();
};