#include <iostream>
#include "Game.h"
#include "SDL/SDLFactory.h"

int main(int argc, char* argv[]) {
    Abs::Factory* factory = new Sdl::SDLFactory();
    Game* g = new Game(factory);
    g->run();

    return 0;
}
