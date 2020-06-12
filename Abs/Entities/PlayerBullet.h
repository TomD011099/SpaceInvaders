#ifndef SPACEINVADERS_PLAYERBULLET_H
#define SPACEINVADERS_PLAYERBULLET_H

#include "PlayerEntity.h"

namespace Abs {
    /**
     * The abstract playerbullet, implement this to use it for a specific engine
     */
    class PlayerBullet : public PlayerEntity {
    public:
        PlayerBullet(double, double, double, double);

        virtual ~PlayerBullet() = default;
    };
}

#endif