#include <iostream>
#include "Entity.h"

Abs::Entity::Entity(double x, double y, double w, double h) {
    xPos = x;
    yPos = y;
    width = w;
    height = h;
}

double Abs::Entity::getXPos() {
    return xPos;
}

double Abs::Entity::getYPos() {
    return yPos;
}

double Abs::Entity::getWidth() const {
    return width;
}

double Abs::Entity::getHeight() const {
    return height;
}

void Abs::Entity::move(double dx, double dy) {
    if ((xPos + dx) < (width/2))
        xPos = (width/2);
    else if (xPos + dx + (width/2) > 1)
        xPos = 1 - (width/2);
    else
        xPos += dx;

    yPos += dy;
}


