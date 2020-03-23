#include "SDLEnemyShip.h"

Sdl::SDLEnemyShip::SDLEnemyShip(Sdl::SDLWindow* window, float x, float y, int w, int h) : EnemyShip(x, y, w, h){
    this->window = window;
}

void Sdl::SDLEnemyShip::visualize() {
    window->render(xPos, yPos, ENEMYSHIP);
}

void Sdl::SDLEnemyShip::update(EVENT) {

}

