#ifndef SPACEINVADERS_PLAYERSHIP_H
#define SPACEINVADERS_PLAYERSHIP_H

#include "PlayerEntity.h"

namespace Abs {
    /**
     * The abstract playership, implement this to use it for a specific engine
     */
    class PlayerShip : public PlayerEntity {
    public:
        PlayerShip(double, double, double, double);

        virtual void killed();

        ENTITY getSkin();

    private:
        ENTITY skin;        //The skin of the player (used to display wreck)
    };
}

#endif