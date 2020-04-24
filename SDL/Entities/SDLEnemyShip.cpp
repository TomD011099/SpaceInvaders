#include "SDLEnemyShip.h"

Sdl::SDLEnemyShip::SDLEnemyShip(Sdl::SDLWindow* window, float x, float y, float w, float h, ENTITY e) : EnemyShip(x, y, w, h, e){
    this->window = window;
}

void Sdl::SDLEnemyShip::visualize() {
    window->render(xPos, yPos, width, height, type);
}

void Sdl::SDLEnemyShip::hit() {
    EnemyShip::hit();
    window->playSound(INVADER_KILLED);
}
