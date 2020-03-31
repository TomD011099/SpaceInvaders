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

void Abs::Entity::move(float dx, float dy) {
    std::cout << xPos << "\t" << dx  << "\t" << width << "\n";

    if ((xPos + dx) < 0)
        xPos = 0;
    else if (xPos + dx > 1)
        xPos = 1;
    else
        xPos += dx;

    yPos += dy;
}
