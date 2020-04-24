#ifndef SPACEINVADERS_PLAYERSHIP_H
#define SPACEINVADERS_PLAYERSHIP_H

#include "PlayerEntity.h"

namespace Abs{
    class PlayerShip: public PlayerEntity {
    public:
        PlayerShip(float, float, float, float);

        virtual void visualize() = 0;

        virtual void killed();

        ENTITY getSkin();

    private:
        ENTITY skin;
    };
}

#endif