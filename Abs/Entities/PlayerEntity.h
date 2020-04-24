#ifndef SPACEINVADERS_PLAYERENTITY_H
#define SPACEINVADERS_PLAYERENTITY_H

#include "Entity.h"

namespace Abs{
    class PlayerEntity: public Entity {
    public:
        PlayerEntity(double, double, double, double);

        virtual ~PlayerEntity() = default;

        virtual void visualize() = 0;
    };
}

#endif