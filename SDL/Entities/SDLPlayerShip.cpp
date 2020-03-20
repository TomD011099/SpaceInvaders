#include "SDLPlayerShip.h"

Sdl::SDLPlayerShip::SDLPlayerShip(Sdl::SDLWindow* window) : PlayerShip(0, 0){
    this->window = window;
}

Sdl::SDLPlayerShip::SDLPlayerShip(Sdl::SDLWindow* window, float x, float y) : PlayerShip(x, y){
    this->window = window;
}

void Sdl::SDLPlayerShip::visualize() {
    window->render(xPos, yPos, PLAYERSHIP);
}

void Sdl::SDLPlayerShip::update(int event) {
    switch (event) {
        case CTRL_PRESS_LEFT:
            if (xPos >= PLAYER_SPEED)
                xPos -= PLAYER_SPEED;
            else
                xPos = 0;
            break;
        case CTRL_PRESS_RIGHT:
            // TODO add width
            if (xPos <= SCREEN_WIDTH-PLAYER_SPEED)
                xPos += PLAYER_SPEED;
            else
                xPos = SCREEN_WIDTH;
            break;
        default:
            break;
    }

    visualize();
}
