#ifndef SPACEINVADERS_FACTORY_H
#define SPACEINVADERS_FACTORY_H

#include "Entities/PlayerShip.h"
#include "Entities/EnemyShip.h"
#include "Entities/PlayerBullet.h"
#include "Controller.h"

namespace Abs{
    class Factory {
    public:
        virtual Abs::PlayerShip* createPlayerShip() = 0;

        virtual Abs::EnemyShip* createEnemyShip() = 0;

        virtual Abs::Controller* createController() = 0;

        virtual Abs::PlayerBullet* createPlayerBullet(float, float) = 0;

        virtual void draw() = 0;

        virtual void setupFrame() = 0;
    };
}

#endif