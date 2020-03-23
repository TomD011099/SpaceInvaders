#ifndef SPACEINVADERS_SDLENEMYSHIP_H
#define SPACEINVADERS_SDLENEMYSHIP_H

#include "../../Abs/Entities/EnemyShip.h"
#include "../Window/SDLWindow.h"

namespace Sdl {
    class SDLEnemyShip : public Abs::EnemyShip {
    public:
        SDLEnemyShip(Sdl::SDLWindow*, float, float, int, int);

        void visualize();

        void update(EVENT);

    private:
        SDLWindow* window;
    };
}

#endif