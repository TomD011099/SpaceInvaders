#include "EnemyShip.h"

Abs::EnemyShip::EnemyShip(float x, float y, float w, float h, ENTITY e) : EnemyEntity(x, y, w, h) {
    type = e;
    alive = true;
    gone = false;
}

bool Abs::EnemyShip::isAlive() {
    return alive;
}

void Abs::EnemyShip::hit() {
    alive = false;
    type = ENEMY_WRECK;
    deathTime = 0;
}

bool Abs::EnemyShip::isGone() {
    return gone;
}

void Abs::EnemyShip::tick() {
    deathTime++;
    gone = (deathTime == NORMALISED_ENEMY_DEATH_TIME);
}

ENTITY Abs::EnemyShip::getType() {
    return type;
}
