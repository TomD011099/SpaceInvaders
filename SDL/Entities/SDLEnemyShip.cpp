#include "SDLEnemyShip.h"

Sdl::SDLEnemyShip::SDLEnemyShip(Sdl::SDLWindow* window, float x, float y, float w, float h) : EnemyShip(x, y, w, h){
    this->window = window;
}

void Sdl::SDLEnemyShip::visualize() {
    window->render(xPos, yPos, width, height, ENEMYSHIP);
}
