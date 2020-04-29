#include "SDLPosBonus.h"

/**
 * Constructor for SDLPosBonus. Window is SDL-specific, the rest is used by the Abs:: classes
 *
 * @param window The SDLWindow on which the game will be rendered
 * @param x The relative x position
 * @param y The relative y position
 * @param w The relative width
 * @param h The relative height
 */
Sdl::SDLPosBonus::SDLPosBonus(Sdl::SDLWindow* window, double x, double y, double w, double h)
        : Abs::PosBonus(x, y, w, h) {
    this->window = window;
}

/**
 * Render the object
 */
void Sdl::SDLPosBonus::visualize() {
    window->render(xPos, yPos, width, height, POSBONUS);
}
