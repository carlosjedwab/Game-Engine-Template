# Game-Engine-Template
A series of model files that can be used as a basis for game development

Built with the SFML C++ library, which is necessary for running the game.

# Running on Linux
With SFML installed, run the run.py script to open the game.

# Files description
- run: It compiles and runs all the other files;
- main: It calls for the Game class and its update and render functions;
- Game: It acts as the game engine/Wrapper class;
- Global: It stores globaly used variables and constants for easy access.
- Utilities: It contains some useful functions;
- Entity_: It's a template for entity classes such as Player, Enemy, Background...<br/>
(instructions on how to use Entity_ to generate a new entity class can be found at the beginning of Entity_.h)

# How to use
Use the Entity_.h and Entity_.cpp files as models for your enty classes, such as Player, Enemy, Background...<br/>
Don't forget to add the new class name to the run.py and change the #include and entities declaration at Game.h.

The game logic is build inside the 'update' functions at each entity class. Feel free to add new functions directly at the class file or at the utilities file (utilities functions are those who are shared between entities, that is, they are not specific to any single entity). New variables that are not specific to any single entity can be stored at the global file, with it's respective 'get' and 'set' functions (an example would be screen related variables).
