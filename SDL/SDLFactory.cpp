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

Abs::PlayerShip* Sdl::SDLFactory::createPlayerShip(float x, float y, float w, float h) {
    return new Sdl::SDLPlayerShip(window, x, y, w, h);
}

Abs::EnemyShip* Sdl::SDLFactory::createEnemyShip(float x, float y, float w, float h, ENTITY e) {
    return new Sdl::SDLEnemyShip(window, x, y, w, h, e);
}

Abs::Controller* Sdl::SDLFactory::createController() {
    return new Sdl::SDLController();
}

Abs::PlayerBullet* Sdl::SDLFactory::createPlayerBullet(float x, float y, float w, float h) {
    return new Sdl::SDLPlayerBullet(window, x, y, w, h);
}

void Sdl::SDLFactory::draw() {
    window->draw();
}

void Sdl::SDLFactory::setupFrame() {
    window->setup();
}

Abs::EnemyBullet* Sdl::SDLFactory::createEnemyBullet(float x, float y, float w, float h) {
    return new Sdl::SDLEnemyBullet(window, x, y, w, h);
}
