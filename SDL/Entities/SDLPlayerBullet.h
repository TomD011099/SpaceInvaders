#ifndef SPACEINVADERS_SDLPLAYERBULLET_H
#define SPACEINVADERS_SDLPLAYERBULLET_H

#include "../../Abs/Entities/PlayerBullet.h"

namespace Sdl{
    class SDLPlayerBullet: Abs::PlayerBullet{
    public:
        void visualize();
        void draw() {};
    };
}

#endif