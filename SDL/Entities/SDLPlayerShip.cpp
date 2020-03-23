#include "SDLPlayerShip.h"

Sdl::SDLPlayerShip::SDLPlayerShip(Sdl::SDLWindow* window, float x, float y, int w, int h) : PlayerShip(x, y, w, h){
    this->window = window;
}

void Sdl::SDLPlayerShip::visualize() {
    window->render(xPos, yPos, PLAYERSHIP);
}

void Sdl::SDLPlayerShip::update(EVENT event) {
    switch (event) {
        case CTRL_LEFT:
            if (xPos - NORMALISED_SPEED >= 0)
                xPos -= NORMALISED_SPEED;
            else
                xPos = 0;
            break;
        case CTRL_RIGHT:
            if (xPos + NORMALISED_SPEED <= 1)
                xPos += NORMALISED_SPEED;
            else
                xPos = 1;
            break;
        default:
            break;
    }

    visualize();
}
