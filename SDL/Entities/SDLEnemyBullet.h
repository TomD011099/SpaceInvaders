#ifndef SPACEINVADERS_SDLENEMYBULLET_H
#define SPACEINVADERS_SDLENEMYBULLET_H

#include "../../Abs/Entities/EnemyBullet.h"

namespace Sdl{
    class SDLEnemyBullet: public Abs::EnemyBullet {
    public:
        void visualize();
    };
}

#endif