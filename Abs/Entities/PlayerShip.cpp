#include "PlayerShip.h"

Abs::PlayerShip::PlayerShip(float x, float y, float w, float h) : PlayerEntity(x, y, w, h){
    skin = PLAYERSHIP;
}

void Abs::PlayerShip::killed() {
    skin = PLAYER_WRECK;
}

ENTITY Abs::PlayerShip::getSkin() {
    return skin;
}
