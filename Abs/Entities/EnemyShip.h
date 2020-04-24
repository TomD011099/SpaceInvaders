#ifndef SPACEINVADERS_ENEMYSHIP_H
#define SPACEINVADERS_ENEMYSHIP_H

#include "EnemyEntity.h"

namespace Abs {
    class EnemyShip : public EnemyEntity {
    public:
        EnemyShip(double, double, double, double, ENTITY);

        bool isAlive();

        virtual void hit();

        bool isGone();

        void tick();

        ENTITY getType();

    protected:
        ENTITY type;

    protected:
        bool alive, gone;
        int deathTime;
    };
}

#endif