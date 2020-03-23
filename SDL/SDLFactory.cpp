#include "SDLFactory.h"

Sdl::SDLFactory::SDLFactory() {
    window = new SDLWindow();
    window->init();
    if (window->loadMedia())
        std::cout << "Successfully loaded media\n";
}

Sdl::SDLFactory::~SDLFactory() {
    delete window;
}

Abs::PlayerShip* Sdl::SDLFactory::createPlayerShip() {
    return new Sdl::SDLPlayerShip(window, 0.5, 0.9, 73, 52);
}

Abs::EnemyShip* Sdl::SDLFactory::createEnemyShip() {
    return new Sdl::SDLEnemyShip(window, 0.1, 0.1, 110, 80);
}

Abs::Controller* Sdl::SDLFactory::createController() {
    return new Sdl::SDLController();
}

void Sdl::SDLFactory::draw() {
    window->draw();
}
