#include "Entity.h"

Abs::Entity::Entity(float x, float y, float w, float h) {
    xPos = x;
    yPos = y;
    width = w;
    height = h;
}

float Abs::Entity::getXPos() {
    return xPos;
}

float Abs::Entity::getYPos() {
    return yPos;
}
