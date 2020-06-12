#ifndef SPACEINVADERS_ENEMYBULLET_H
#define SPACEINVADERS_ENEMYBULLET_H

#include "EnemyEntity.h"

namespace Abs {
    /**
     * The abstract enemybullet, implement this to use it for a specific engine
     */
    class EnemyBullet : public EnemyEntity {
    public:
        EnemyBullet(double, double, double, double);

        virtual ~EnemyBullet() = default;
    };
}

#endif