#ifndef SPACEINVADERS_ENEMYSHIP_H
#define SPACEINVADERS_ENEMYSHIP_H

#include "EnemyEntity.h"

namespace Abs{
    class EnemyShip: public EnemyEntity {
    public:
        EnemyShip(float, float, float, float);

        virtual void visualize() = 0;
    };
}

#endif