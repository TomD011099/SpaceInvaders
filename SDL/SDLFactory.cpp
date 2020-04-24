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
    window->playSound(SHOOT);
    return new Sdl::SDLPlayerBullet(window, x, y, w, h);
}

Abs::EnemyBullet* Sdl::SDLFactory::createEnemyBullet(float x, float y, float w, float h) {
    return new Sdl::SDLEnemyBullet(window, x, y, w, h);
}

Abs::PosBonus* Sdl::SDLFactory::createPosBonus(float x, float y, float w, float h) {
    window->playSound(BONUS_SPAWN);
    return new Sdl::SDLPosBonus(window, x, y, w, h);
}

Abs::NegBonus* Sdl::SDLFactory::createNegBonus(float x, float y, float w, float h) {
    window->playSound(BONUS_SPAWN);
    return new Sdl::SDLNegBonus(window, x, y, w, h);
}

void Sdl::SDLFactory::draw(int score, int lives, bool isEndScreen) {
    if (!isEndScreen) {
        window->printScore(score);
        window->printLives(lives);
    } else {
        window->printScoreEnd(score);
    }
    window->draw();
}

void Sdl::SDLFactory::setupFrame() {
    window->setup();
}

void Sdl::SDLFactory::playSound(SOUND s) {
    window->playSound(s);
}
