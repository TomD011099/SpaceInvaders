#include "SDLPlayerShip.h"

Sdl::SDLPlayerShip::SDLPlayerShip(Sdl::SDLWindow* window, float x, float y, float w, float h) : PlayerShip(x, y, w, h){
    this->window = window;
}

void Sdl::SDLPlayerShip::visualize() {
    window->render(xPos, yPos, width, height, PLAYERSHIP);
}
