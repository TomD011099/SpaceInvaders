#ifndef SPACEINVADERS_SDLPLAYERBULLET_H
#define SPACEINVADERS_SDLPLAYERBULLET_H

#include "../../Abs/Entities/PlayerBullet.h"
#include "../Window/SDLWindow.h"

namespace Sdl{
    class SDLPlayerBullet: public Abs::PlayerBullet{
    public:
        SDLPlayerBullet(SDLWindow*, float, float, float, float);

        ~SDLPlayerBullet();

        void visualize();

    private:
        SDLWindow* window;
    };
}

#endif