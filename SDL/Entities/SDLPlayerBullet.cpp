#include "SDLPlayerBullet.h"

Sdl::SDLPlayerBullet::SDLPlayerBullet(Sdl::SDLWindow* window, double x, double y, double w, double h) : Abs::PlayerBullet(x, y, w, h) {
    this->window = window;
}

void Sdl::SDLPlayerBullet::visualize() {
    window->render(xPos, yPos, width, height, PLAYERBULLET);
}