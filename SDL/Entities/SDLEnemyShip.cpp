#include "SDLEnemyShip.h"

Sdl::SDLEnemyShip::SDLEnemyShip(Sdl::SDLWindow* window) : EnemyShip(0, 0){
    this->window = window;
}

Sdl::SDLEnemyShip::SDLEnemyShip(Sdl::SDLWindow* window, float x, float y) : EnemyShip(x, y){
    this->window = window;
}

void Sdl::SDLEnemyShip::visualize() {
    window->render(xPos, yPos, ENEMYSHIP);
}

void Sdl::SDLEnemyShip::update(int) {

}

