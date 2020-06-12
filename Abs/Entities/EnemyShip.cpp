#include "EnemyShip.h"

/**
 *
 * @param x The relative x position
 * @param y The relative y position
 * @param w The relative width
 * @param h The relative height
 * @param e The type of enemy
 */
Abs::EnemyShip::EnemyShip(double x, double y, double w, double h, ENTITY e) : EnemyEntity(x, y, w, h) {
    type = e;
    alive = true;
    gone = false;
}

/**
 * Is the enemy alive?
 *
 * @return true if yes, false if not
 */
bool Abs::EnemyShip::isAlive() {
    return alive;
}

/**
 * The enemy is hit, change type to wreck and initialise the counter
 */
void Abs::EnemyShip::hit() {
    alive = false;
    type = ENEMY_WRECK;
    deathTime = 0;
}

/**
 * The explosion has finished and the enemy can be deleted
 *
 * @return true if yes, false if not
 */
bool Abs::EnemyShip::isGone() {
    return gone;
}

/**
 * Update the counter
 */
void Abs::EnemyShip::tick() {
    deathTime++;
    gone = (deathTime == NORMALISED_ENEMY_DEATH_TIME);
}

/**
 * Get the enemy type
 *
 * @return the enemy type
 */
ENTITY Abs::EnemyShip::getType() {
    return type;
}
