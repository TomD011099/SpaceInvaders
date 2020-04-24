#include "BonusEntity.h"

Abs::BonusEntity::BonusEntity(ENTITY e, float x, float y, float w, float h) : Entity(x, y, w, h) {
    entity = e;
}

ENTITY Abs::BonusEntity::getEntity() {
    return entity;
}

void Abs::BonusEntity::move(float dx, float dy) {
    if ((xPos + dx) < -(width/2))
        xPos = -(width/2);
    else if (xPos + dx - (width/2) > 1)
        xPos = 1 + (width/2);
    else
        xPos += dx;

    yPos += dy;
}
