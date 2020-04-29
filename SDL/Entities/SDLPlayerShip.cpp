#include "SDLPlayerShip.h"

/**
 * Constructor for SDLPlayerShip. Window is SDL-specific, the rest is used by the Abs:: classes
 *
 * @param window The SDLWindow on which the game will be rendered
 * @param x The relative x position
 * @param y The relative y position
 * @param w The relative width
 * @param h The relative height
 */
Sdl::SDLPlayerShip::SDLPlayerShip(Sdl::SDLWindow* window, double x, double y, double w, double h)
        : PlayerShip(x, y, w, h) {
    this->window = window;
}

/**
 * Render the object
 */
void Sdl::SDLPlayerShip::visualize() {
    window->render(xPos, yPos, width, height, getSkin());
}

/**
 * Override for Abs::PlayerShip::killed().
 *
 * Adds SDL sound
 */
void Sdl::SDLPlayerShip::killed() {
    PlayerShip::killed();
    window->playSound(EXPLOSION);
}
