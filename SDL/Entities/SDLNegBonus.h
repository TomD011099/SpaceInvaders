#ifndef SPACEINVADERS_SDLNEGBONUS_H
#define SPACEINVADERS_SDLNEGBONUS_H

#include "../../Abs/Entities/NegBonus.h"

namespace Sdl {
    class SDLNegBonus : public Abs::NegBonus {
    public:
        void visualize();
        void draw() {};
    };
}

#endif