#include "SDLEnemyShip.h"

Sdl::SDLEnemyShip::SDLEnemyShip(Sdl::SDLWindow* window, double x, double y, double w, double h, ENTITY e) : EnemyShip(x, y, w, h, e){
    this->window = window;
}

void Sdl::SDLEnemyShip::visualize() {
    window->render(xPos, yPos, width, height, type);
}

void Sdl::SDLEnemyShip::hit() {
    EnemyShip::hit();
    window->playSound(INVADER_KILLED);
}
