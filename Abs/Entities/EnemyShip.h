#ifndef SPACEINVADERS_ENEMYSHIP_H
#define SPACEINVADERS_ENEMYSHIP_H

#include "EnemyEntity.h"

namespace Abs{
    class EnemyShip: public EnemyEntity {
    public:
        EnemyShip(float, float, float, float);
    };
}

#endif