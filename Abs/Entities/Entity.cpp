#include <iostream>
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

float Abs::Entity::getWidth() const {
    return width;
}

float Abs::Entity::getHeight() const {
    return height;
}

void Abs::Entity::move(float dx, float dy) {
    if ((xPos + dx) < (width/2))
        xPos = (width/2);
    else if (xPos + dx + (width/2) > 1)
        xPos = 1 - (width/2);
    else
        xPos += dx;

    yPos += dy;
}


