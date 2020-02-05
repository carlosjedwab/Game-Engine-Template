#include "Entity_.h"
 
//Private functions
void Entity_::initVariables()
{
    //Custom constants

    //Game logic

    //Game objects
    entityPos = sf::Vector2f(0.f, 0.f);
    entityVel = sf::Vector2f(0.f, 0.f);
}
void Entity_::initShape()
{
    /*
        @return void

        Entity_'s default shape: //shape example
            - Green circle of radius rad=10.
    */
    const float rad = 10.f;
    this->shape.setRadius(rad);
    this->shape.setOrigin(rad,rad);
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setOutlineColor(sf::Color::Green);
    this->shape.setOutlineThickness(1.f);
    this->entityPos = sf::Vector2f(global->getScreenSize().width/2.f, global->getScreenSize().height/2.f);
}

//Constructors / Destructors
Entity_::Entity_(Global* global)
{
    this->global = global;
    this->initVariables();
    this->initShape();
}
Entity_::~Entity_()
{

}

//Accessors

//Functions
void Entity_::update(float dt)
{
    /*
        @return void

        Updates the entity: //game logic example
            - Suffers drag;
            - Accelerates due to the arrow keys
            - Bounce off the boundaries
    */

    entityVel /= 1.01f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        entityVel += sf::Vector2f(5.f,0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        entityVel += sf::Vector2f(-5.f,0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        entityVel += sf::Vector2f(0.f,-5.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        entityVel += sf::Vector2f(0.f,5.f);
    
    entityVel = utilities.boundaryCollision(global, entityPos, entityVel);
    entityPos += entityVel*dt;

    this->shape.setPosition(utilities.adjustToCamera(global, entityPos));
}

void Entity_::render(sf::RenderTarget* target)
{
    /*
        @return void

        Renders the entity.
    */

    target->draw(this->shape);
}