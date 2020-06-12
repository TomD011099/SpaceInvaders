#ifndef SPACEINVADERS_PLAYERENTITY_H
#define SPACEINVADERS_PLAYERENTITY_H

#include "Entity.h"

namespace Abs {
    /**
     * The abstract playerEntity super class for PlayerShip and PlayerBullet
     */
    class PlayerEntity : public Entity {
    public:
        PlayerEntity(double, double, double, double);

        virtual ~PlayerEntity() = default;
    };
}

#endif