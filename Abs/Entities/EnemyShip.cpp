#include "EnemyShip.h"

Abs::EnemyShip::EnemyShip(float x, float y, float w, float h, ENTITY e) : EnemyEntity(x, y, w, h){
    type = e;
    alive = true;
}

bool Abs::EnemyShip::isAlive() {
    return alive;
}

void Abs::EnemyShip::hit() {
    alive = false;
}
