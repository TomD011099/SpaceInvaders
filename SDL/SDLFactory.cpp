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
    return new Sdl::SDLPlayerShip(window, 0.5, 0.9, 0.05, 0.05);
}

Abs::EnemyShip* Sdl::SDLFactory::createEnemyShip() {
    return new Sdl::SDLEnemyShip(window, 0.1, 0.1, 0.1, 0.1);
}

Abs::Controller* Sdl::SDLFactory::createController() {
    return new Sdl::SDLController();
}

Abs::PlayerBullet* Sdl::SDLFactory::createPlayerBullet(float x, float y) {
    return new Sdl::SDLPlayerBullet(window, x, y, 0.01, 0.03);
}

void Sdl::SDLFactory::draw() {
    window->draw();
}

void Sdl::SDLFactory::setupFrame() {
    window->setup();
}
