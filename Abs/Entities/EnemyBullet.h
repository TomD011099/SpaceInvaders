#ifndef SPACEINVADERS_ENEMYBULLET_H
#define SPACEINVADERS_ENEMYBULLET_H

#include "EnemyEntity.h"

namespace Abs{
    class EnemyBullet: public EnemyEntity {
    public:
        virtual void visualize() = 0;
    };
}

#endif