#include "Entity.h"

Abs::Entity::Entity(float x, float y) {
    xPos = x;
    yPos = y;
}

int Abs::Entity::getXPos() {
    return xPos;
}

int Abs::Entity::getYPos() {
    return yPos;
}
