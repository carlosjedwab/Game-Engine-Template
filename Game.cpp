#include "Game.h"

//Private functions
void Game::initWindow()
{
    this->window = new sf::RenderWindow(this->global.getScreenSize(), "Game", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

//Constructors / Destructors
Game::Game()
{
    this->initWindow();
}
Game::~Game()
{
    delete this->window;
}

//Accessors
const bool Game::running() const
{
    return this->window->isOpen();
}

//Functions
void Game::pollEvents()
{
    /*
        @return void

        Event polling (buttons and keys)
    */

    sf::Event event;
    this->global.setEvent(event);
    while (this->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            this->window->close();
            break;
        }
    }
}

void Game::updateMousePositions()
{
    /*
        @return void

        Updates mouse positions.
        - Mouse position relative to window (Vector2i);
        - Mouse position relative to view (Vector2f).
    */
   
    sf::Vector2i mousePosWindow = sf::Mouse::getPosition(*this->window);
    sf::Vector2f mousePosView = this->window->mapPixelToCoords(mousePosWindow);
    this->global.setMousePos(mousePosView);
}

void Game::update(float dt)
{
    /*
        @return void

        - Updates the external inputs;
        - Updates the game objects:
            - Player;
            - Enemies;
            - Background.
    */
    this->pollEvents();

    this->updateMousePositions();

    //Update game objects
    this->entity.update(dt);
}

void Game::render()
{
    /*
        @return void

        - Clear old frame;
        - Render objects:
            - Background; //example
            - Player;     //example
            - Enemies.    //example
        - Display frame in window.
    */

    //Clear old frame
    this->window->clear(sf::Color::Black);

    //Draw game objects
    this->entity.render(window);

    //Display window
    this->window->display();
}