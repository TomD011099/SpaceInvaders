#include "Game.h"
#include "SDL/SDLFactory.h"
#include "Util/ConfigLoader.h"
#include <map>

int main(int argc, char* argv[]) { //argc and argv aren't used, but necessary for SDL
    ConfigLoader* c = new ConfigLoader("../config.xml");
    std::map<std::string, std::string> settingsMap = c->load();
    GameConstants::initInstance(settingsMap);

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
