#include "SDLPlayerShip.h"

Sdl::SDLPlayerShip::SDLPlayerShip(Sdl::SDLWindow* window, float x, float y, float w, float h) : PlayerShip(x, y, w, h){
    this->window = window;
}

void Sdl::SDLPlayerShip::visualize() {
    window->render(xPos, yPos, width, height, PLAYERSHIP);
}

bool Sdl::SDLPlayerShip::update(EVENT event) {
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
    return true;
}
