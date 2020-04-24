#ifndef SPACEINVADERS_SDLENEMYSHIP_H
#define SPACEINVADERS_SDLENEMYSHIP_H

#include "../../Abs/Entities/EnemyShip.h"
#include "../Window/SDLWindow.h"

namespace Sdl {
    class SDLEnemyShip : public Abs::EnemyShip {
    public:
        SDLEnemyShip(Sdl::SDLWindow*, double, double, double , double, ENTITY);

        void visualize();

        void hit();

    private:
        SDLWindow* window;
    };
}

#endif