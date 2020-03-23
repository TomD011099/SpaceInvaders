#include "Entity.h"

Abs::Entity::Entity(float x, float y, float w, float h) {
    xPos = x;
    yPos = y;
    width = w;
    height = h;
}

int Abs::Entity::getXPos() {
    return xPos;
}

int Abs::Entity::getYPos() {
    return yPos;
}
