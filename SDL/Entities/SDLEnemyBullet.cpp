#include "SDLEnemyBullet.h"

/**
 * Constructor for SDLEnemyBullet. Window is SDL-specific, the rest is used by the Abs:: classes
 *
 * @param window The SDLWindow on which the game will be rendered
 * @param x The relative x position
 * @param y The relative y position
 * @param w The relative width
 * @param h The relative height
 */
Sdl::SDLEnemyBullet::SDLEnemyBullet(Sdl::SDLWindow* window, double x, double y, double w, double h)
        : Abs::EnemyBullet(x, y, w, h) {
    this->window = window;
}

/**
 * Render the object
 */
void Sdl::SDLEnemyBullet::visualize() {
    window->render(xPos, yPos, width, height, ENEMYBULLET);
}
