#include "SDLPlayerBullet.h"

Sdl::SDLPlayerBullet::SDLPlayerBullet(Sdl::SDLWindow* window, float x, float y, float w, float h) : Abs::PlayerBullet(x, y, w, h) {
    this->window = window;
}

void Sdl::SDLPlayerBullet::visualize() {
    window->render(xPos, yPos, width, height, PLAYERBULLET);
}

bool Sdl::SDLPlayerBullet::update(EVENT) {
    if (yPos < 0) {
        return false;
    } else {
        yPos -= NORMALISED_BULLET_SPEED;
    }

    visualize();
    return true;
}