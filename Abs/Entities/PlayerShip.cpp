#include "PlayerShip.h"

/**
 * The constructor for Abs::PlayerShip
 *
 * @param x The relative x position
 * @param y The relative y position
 * @param w The relative width
 * @param h The relative height
 */
Abs::PlayerShip::PlayerShip(double x, double y, double w, double h) : PlayerEntity(x, y, w, h) {
    skin = PLAYERSHIP;
}

/**
 * When the player is killed, switch the skin to wreck
 */
void Abs::PlayerShip::killed() {
    skin = PLAYER_WRECK;
}

/**
 * Get the skin that needs to be displayed
 *
 * @return PLAYERSHIP or PLAYER_WRECK, depending on gamestate
 */
ENTITY Abs::PlayerShip::getSkin() {
    return skin;
}
