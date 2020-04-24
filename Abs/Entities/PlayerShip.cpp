#include "PlayerShip.h"

Abs::PlayerShip::PlayerShip(double x, double y, double w, double h) : PlayerEntity(x, y, w, h){
    skin = PLAYERSHIP;
}

void Abs::PlayerShip::killed() {
    skin = PLAYER_WRECK;
}

ENTITY Abs::PlayerShip::getSkin() {
    return skin;
}
