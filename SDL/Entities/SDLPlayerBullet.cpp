#include "SDLPlayerBullet.h"

Sdl::SDLPlayerBullet::SDLPlayerBullet(Sdl::SDLWindow* window, float x, float y, float w, float h) : Abs::PlayerBullet(x, y, w, h) {
    this->window = window;
}

Sdl::SDLPlayerBullet::~SDLPlayerBullet() = default;

void Sdl::SDLPlayerBullet::visualize() {
    window->render(xPos, yPos, width, height, PLAYERBULLET);
}