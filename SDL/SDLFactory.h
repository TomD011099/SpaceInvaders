#ifndef SPACEINVADERS_SDLFACTORY_H
#define SPACEINVADERS_SDLFACTORY_H

#include <iostream>
#include "../GameConstants.h"
#include "../Abs/Factory.h"
#include "Window/SDLWindow.h"
#include "Entities/SDLPlayerShip.h"
#include "Entities/SDLEnemyShip.h"
#include "Entities/SDLPlayerBullet.h"
#include "Entities/SDLEnemyBullet.h"
#include "Entities/SDLPosBonus.h"
#include "Entities/SDLNegBonus.h"
#include "SDLController.h"
#include "Window/SDLWindow.h"

namespace Sdl {
    /**
     * This class will be used to make the game in SDL. Because of the abstarction, the bulk of the logic doesn't need to be specific to SDL.
     */
    class SDLFactory : public Abs::Factory {
    public:
        /**
         * The constructor of the SDLFactory
         * This will initialize the SDL window
         */
        SDLFactory();

        /**
         * The destructor of the SDLFactory
         */
        ~SDLFactory();

        /**
         * Creates a new player
         *
         * @return Playership* a pointer to an SDLPlayership
         */
        Abs::PlayerShip* createPlayerShip(double, double, double, double);

        /**
         * Creates a new enemy
         *
         * @return EnemyShip* a pointer to an SDLEnemyShip
         */
        Abs::EnemyShip* createEnemyShip(double, double, double, double, ENTITY);

        /**
         * Creates a controller, which will check player input
         *
         * @return Controller* a pointer to an SDLController
         */
        Abs::Controller* createController();


        Abs::PlayerBullet* createPlayerBullet(double, double, double, double);

        Abs::EnemyBullet* createEnemyBullet(double, double, double, double);

        Abs::PosBonus* createPosBonus(double, double, double, double);

        Abs::NegBonus* createNegBonus(double, double, double, double);

        void draw(int, int, bool);

        void setupFrame();

        void playSound(SOUND);

    private:
        SDLWindow* window;
    };
}

#endif
