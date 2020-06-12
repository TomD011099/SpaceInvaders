#ifndef SPACEINVADERS_ENEMYSHIP_H
#define SPACEINVADERS_ENEMYSHIP_H

#include "EnemyEntity.h"

namespace Abs {
    /**
     * The abstract playership, implement this to use it for a specific engine
     */
    class EnemyShip : public EnemyEntity {
    public:
        EnemyShip(double, double, double, double, ENTITY);

        bool isAlive();

        virtual void hit();

        bool isGone();

        void tick();

        ENTITY getType();

    protected:
        ENTITY type;            //The type of enemy, dictates visuals and score

    protected:
        bool alive, gone;       //Status of the enemy
        int deathTime;          //A counter for how far in the explosion we are
    };
}

#endif