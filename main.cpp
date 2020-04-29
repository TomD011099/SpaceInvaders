#include <iostream>
#include "Game.h"
#include "SDL/SDLFactory.h"

int main(int argc, char* argv[]) { //argc and argv aren't used, but necessary for SDL
    //Create an SDLFactory, disguised as an Abs::Factory
    Abs::Factory* factory = new Sdl::SDLFactory();

    //Create the game with the SDLFactory
    Game* g = Game::getInstance(factory);

    //Run the game
    g->run();

    //Delete everything
    Game::destroyInstance();
    delete factory;

    return 0;
}
