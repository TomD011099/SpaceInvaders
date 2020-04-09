#ifndef SPACEINVADERS_SDLENEMYBULLET_H
#define SPACEINVADERS_SDLENEMYBULLET_H

#include "../../Abs/Entities/EnemyBullet.h"
#include "../Window/SDLWindow.h"

namespace Sdl{
    class SDLEnemyBullet: public Abs::EnemyBullet {
    public:
        SDLEnemyBullet(SDLWindow*, float, float, float, float);

        ~SDLEnemyBullet() = default;

        void visualize();

    private:
        SDLWindow* window;
    };
}

#endif