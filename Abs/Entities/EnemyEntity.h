#ifndef SPACEINVADERS_ENEMYENTITY_H
#define SPACEINVADERS_ENEMYENTITY_H

#include "Entity.h"

namespace Abs {
    /**
     * The abstract enemyEntity super class for enemyShip and enemyBullet
     */
    class EnemyEntity : public Entity {
    public:
        EnemyEntity(double, double, double, double);

        virtual ~EnemyEntity() = default;
    };
}


#endif