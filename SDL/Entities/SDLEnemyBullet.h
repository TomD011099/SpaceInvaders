#ifndef SPACEINVADERS_SDLENEMYBULLET_H
#define SPACEINVADERS_SDLENEMYBULLET_H

#include "../../Abs/Entities/EnemyBullet.h"
#include "../Window/SDLWindow.h"

namespace Sdl {
    /**
     * An implementation of Abs::EnemyBullet
     */
    class SDLEnemyBullet : public Abs::EnemyBullet {
    public:
        SDLEnemyBullet(SDLWindow*, double, double, double, double);

        ~SDLEnemyBullet() = default;

        void visualize();

    private:
        SDLWindow* window;      //The SDL game window
    };
}

#endif