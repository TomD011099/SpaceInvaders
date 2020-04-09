#ifndef SPACEINVADERS_FACTORY_H
#define SPACEINVADERS_FACTORY_H

#include "Entities/PlayerShip.h"
#include "Entities/EnemyShip.h"
#include "Entities/PlayerBullet.h"
#include "Entities/EnemyBullet.h"
#include "Controller.h"

namespace Abs{
    class Factory {
    public:
        virtual ~Factory() = default;

        virtual Abs::PlayerShip* createPlayerShip(float, float, float, float) = 0;

        virtual Abs::EnemyShip* createEnemyShip(float, float, float, float, ENTITY) = 0;

        virtual Abs::Controller* createController() = 0;

        virtual Abs::PlayerBullet* createPlayerBullet(float, float, float, float) = 0;

        virtual Abs::EnemyBullet* createEnemyBullet(float, float, float, float) = 0;

        virtual void draw() = 0;

        virtual void setupFrame() = 0;
    };
}

#endif