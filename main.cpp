#include <iostream>
#include "Game.h"
#include "SDL/SDLFactory.h"

int main(int argc, char* argv[]) {
    Abs::Factory* factory = new Sdl::SDLFactory();
    Game* g = Game::getInstance(factory);
    g->run();
    delete g;
    delete factory;

    return 0;
}
