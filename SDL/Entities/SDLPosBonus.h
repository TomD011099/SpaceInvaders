#ifndef SPACEINVADERS_SDLPOSBONUS_H
#define SPACEINVADERS_SDLPOSBONUS_H

#include "../../Abs/Entities/PosBonus.h"

namespace Sdl{
    class SDLPosBonus: public Abs::PosBonus {
    public:
        void visualize();
    };
}

#endif