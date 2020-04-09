#ifndef SPACEINVADERS_PLAYERENTITY_H
#define SPACEINVADERS_PLAYERENTITY_H

#include "Entity.h"

namespace Abs{
    class PlayerEntity: public Entity {
    public:
        PlayerEntity(float, float, float, float);

        virtual ~PlayerEntity() = default;

        virtual void visualize() = 0;
    };
}

#endif