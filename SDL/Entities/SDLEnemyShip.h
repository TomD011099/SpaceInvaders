#ifndef SPACEINVADERS_SDLENEMYSHIP_H
#define SPACEINVADERS_SDLENEMYSHIP_H

#include "../../Abs/Entities/EnemyShip.h"
#include "../Window/SDLWindow.h"

namespace Sdl {
    /**
     * An implementation of Abs::EnemyShip
     */
    class SDLEnemyShip : public Abs::EnemyShip {
    public:
        SDLEnemyShip(Sdl::SDLWindow*, double, double, double, double, ENTITY);

        ~SDLEnemyShip() = default;

        void visualize();

        void hit();

    private:
        SDLWindow* window;      //The SDL game window
    };
}

#endif