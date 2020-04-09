#ifndef SPACEINVADERS_PLAYERBULLET_H
#define SPACEINVADERS_PLAYERBULLET_H

#include "PlayerEntity.h"

namespace Abs{
    class PlayerBullet: public PlayerEntity {
    public:
        PlayerBullet(float, float, float, float);

        virtual ~PlayerBullet() = default;

        virtual void visualize() = 0;
    };
}

#endif