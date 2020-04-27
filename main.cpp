#include <iostream>
#include "Game.h"
#include "SDL/SDLFactory.h"

int main(int argc, char* argv[]) {
    Abs::Factory* factory = new Sdl::SDLFactory();
    Game* g = Game::getInstance(factory);

    //Run the game
    g->run();

    Game::destroyInstance();
    delete factory;

    return 0;
}
