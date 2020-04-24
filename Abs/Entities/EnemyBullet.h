#ifndef SPACEINVADERS_ENEMYBULLET_H
#define SPACEINVADERS_ENEMYBULLET_H

#include "EnemyEntity.h"

namespace Abs{
    class EnemyBullet: public EnemyEntity {
    public:
        EnemyBullet(double, double, double, double);

        virtual ~EnemyBullet() = default;

        virtual void visualize() = 0;
    };
}

#endif