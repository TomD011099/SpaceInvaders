#ifndef SPACEINVADERS_ENEMYENTITY_H
#define SPACEINVADERS_ENEMYENTITY_H

#include "Entity.h"

namespace Abs{
    class EnemyEntity: public Entity {
    public:
        EnemyEntity(double, double, double, double);

        virtual void visualize() = 0;
    };
}


#endif