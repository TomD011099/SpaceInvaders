#ifndef SPACEINVADERS_SDLFACTORY_H
#define SPACEINVADERS_SDLFACTORY_H

#include <iostream>
#include "../GameConstants.h"
#include "../Abs/Factory.h"
#include "Window/SDLWindow.h"
#include "Entities/SDLPlayerShip.h"
#include "Entities/SDLEnemyShip.h"
#include "Entities/SDLPlayerBullet.h"
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
        Abs::PlayerShip* createPlayerShip();

        /**
         * Creates a new enemy
         *
         * @return EnemyShip* a pointer to an SDLEnemyShip
         */
        Abs::EnemyShip* createEnemyShip();

        /**
         * Creates a controller, which will check player input
         *
         * @return Controller* a pointer to an SDLController
         */
        Abs::Controller* createController();


        Abs::PlayerBullet* createPlayerBullet(float, float);

        void draw();

        void setupFrame();

    private:
        SDLWindow* window;
    };
}

#endif
