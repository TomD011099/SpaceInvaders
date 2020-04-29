#ifndef SPACEINVADERS_SDLPLAYERBULLET_H
#define SPACEINVADERS_SDLPLAYERBULLET_H

#include "../../Abs/Entities/PlayerBullet.h"
#include "../Window/SDLWindow.h"

namespace Sdl {
    /**
     * An implementation of Abs::PlayerBullet
     */
    class SDLPlayerBullet : public Abs::PlayerBullet {
    public:
        SDLPlayerBullet(SDLWindow*, double, double, double, double);

        ~SDLPlayerBullet() = default;

        void visualize();

    private:
        SDLWindow* window;      //The SDL game window
    };
}

#endif