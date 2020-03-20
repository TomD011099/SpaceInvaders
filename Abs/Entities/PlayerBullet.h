#ifndef SPACEINVADERS_PLAYERBULLET_H
#define SPACEINVADERS_PLAYERBULLET_H

#include "PlayerEntity.h"

namespace Abs{
    class PlayerBullet: public PlayerEntity {
    public:
        virtual void visualize() = 0;
    };
}

#endif