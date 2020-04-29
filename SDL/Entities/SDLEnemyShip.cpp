#include "SDLEnemyShip.h"

/**
 * Constructor for SDLEnemyShip. Window is SDL-specific, the rest is used by the Abs:: classes
 *
 * @param window The SDLWindow on which the game will be rendered
 * @param x The relative x position
 * @param y The relative y position
 * @param w The relative width
 * @param h The relative height
 */
Sdl::SDLEnemyShip::SDLEnemyShip(Sdl::SDLWindow* window, double x, double y, double w, double h, ENTITY e) : EnemyShip(x, y, w, h, e){
    this->window = window;
}

/**
 * Render the object
 */
void Sdl::SDLEnemyShip::visualize() {
    window->render(xPos, yPos, width, height, type);
}

/**
 * Override for Abs::PlayerShip::hit().
 *
 * Adds SDL sound
 */
void Sdl::SDLEnemyShip::hit() {
    EnemyShip::hit();
    window->playSound(INVADER_KILLED);
}
