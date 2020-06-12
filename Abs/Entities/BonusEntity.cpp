#include "BonusEntity.h"

/**
 * The constructor for Abs::BonusEntity
 *
 * @param e The type of bonus
 * @param x The relative x position
 * @param y The relative y position
 * @param w The relative width
 * @param h The relative height
 */
Abs::BonusEntity::BonusEntity(ENTITY e, double x, double y, double w, double h) : Entity(x, y, w, h) {
    entity = e;
}

/**
 * Get the type of bonus
 *
 * @return the type of bonus (POSBONUS or NEGBONUS)
 */
ENTITY Abs::BonusEntity::getEntity() {
    return entity;
}

/**
 * Override of Abs::Entity::move.
 * This allows the entity to move partially beyond the borders of the game
 *
 * @param dx x difference
 * @param dy y difference
 */
void Abs::BonusEntity::move(double dx, double dy) {
    if ((xPos + dx) < -(width / 2))
        xPos = -(width / 2);
    else if (xPos + dx - (width / 2) > 1)
        xPos = 1 + (width / 2);
    else
        xPos += dx;

    yPos += dy;
}
