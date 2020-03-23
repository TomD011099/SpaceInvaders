#ifndef SPACEINVADERS_ENEMYENTITY_H
#define SPACEINVADERS_ENEMYENTITY_H

#include "Entity.h"

namespace Abs{
    class EnemyEntity: public Entity {
    public:
        EnemyEntity(float, float, int, int);

        virtual void visualize() = 0;
    };
}


#endif