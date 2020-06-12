#ifndef SPACEINVADERS_FACTORY_H
#define SPACEINVADERS_FACTORY_H

#include "Entities/PlayerShip.h"
#include "Entities/EnemyShip.h"
#include "Entities/PlayerBullet.h"
#include "Entities/EnemyBullet.h"
#include "Entities/BonusEntity.h"
#include "Controller.h"

namespace Abs {
    /**
     * The abstract factory that has to be implemented to play the game for a specific game-engine (like SDL2)
     */
    class Factory {
    public:
        virtual ~Factory() = default;

        virtual Abs::PlayerShip* createPlayerShip(double, double, double, double) = 0;

        virtual Abs::EnemyShip* createEnemyShip(double, double, double, double, ENTITY) = 0;

        virtual Abs::Controller* createController() = 0;

        virtual Abs::PlayerBullet* createPlayerBullet(double, double, double, double) = 0;

        virtual Abs::EnemyBullet* createEnemyBullet(double, double, double, double) = 0;

        virtual Abs::BonusEntity* createBonusEntity(ENTITY, double, double, double, double) = 0;

        virtual void draw(int, int, bool) = 0;

        virtual void setupFrame() = 0;

        virtual void playSound(SOUND) = 0;
    };
}

#endif