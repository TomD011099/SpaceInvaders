#ifndef SPACEINVADERS_SDLFACTORY_H
#define SPACEINVADERS_SDLFACTORY_H

#include <iostream>
#include "../Const/GameConstants.h"
#include "../Abs/Factory.h"
#include "Window/SDLWindow.h"
#include "Entities/SDLPlayerShip.h"
#include "Entities/SDLEnemyShip.h"
#include "Entities/SDLPlayerBullet.h"
#include "Entities/SDLEnemyBullet.h"
#include "Entities/SDLBonusEntity.h"
#include "SDLController.h"
#include "Window/SDLWindow.h"

namespace Sdl {
    /**
     * This class will be used to make the game in SDL. Because of the abstarction, the bulk of the logic doesn't need to be specific to SDL.
     */
    class SDLFactory : public Abs::Factory {
    public:

        SDLFactory();

        ~SDLFactory();

        Abs::PlayerShip* createPlayerShip(double, double, double, double);

        Abs::EnemyShip* createEnemyShip(double, double, double, double, ENTITY);

        Abs::Controller* createController();

        Abs::PlayerBullet* createPlayerBullet(double, double, double, double);

        Abs::EnemyBullet* createEnemyBullet(double, double, double, double);

        Abs::BonusEntity* createBonusEntity(ENTITY, double, double, double, double);

        void draw(int, int, bool);

        void setupFrame();

        void playSound(SOUND);

    private:
        SDLWindow* window;      //The window where the game will be shown
    };
}

#endif
