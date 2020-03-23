#ifndef SPACEINVADERS_PLAYERSHIP_H
#define SPACEINVADERS_PLAYERSHIP_H

#include "PlayerEntity.h"

namespace Abs{
    class PlayerShip: public PlayerEntity {
    public:
        PlayerShip(float, float, int, int);

        virtual void visualize() = 0;
    };
}

#endif