#include "Entity.h"

/**
 * The constructor for Abs::Entity
 *
 * @param x The relative x position
 * @param y The relative y position
 * @param w The relative width
 * @param h The relative height
 */
Abs::Entity::Entity(double x, double y, double w, double h) {
    xPos = x;
    yPos = y;
    width = w;
    height = h;
}

/**
 * Get the x position
 *
 * @return the x position
 */
double Abs::Entity::getXPos() {
    return xPos;
}

/**
 * Get the y position
 *
 * @return the y position
 */
double Abs::Entity::getYPos() {
    return yPos;
}

/**
 * Get the width
 *
 * @return the width
 */
double Abs::Entity::getWidth() const {
    return width;
}

/**
 * Get the height
 *
 * @return the height
 */
double Abs::Entity::getHeight() const {
    return height;
}

/**
 * A general move function. Will prevent entities from moving beyond the game window
 *
 * @param dx relative x to move
 * @param dy relative y to move
 */
void Abs::Entity::move(double dx, double dy) {
    if ((xPos + dx) < (width / 2))
        xPos = (width / 2);
    else if (xPos + dx + (width / 2) > 1)
        xPos = 1 - (width / 2);
    else
        xPos += dx;

    yPos += dy;
}


