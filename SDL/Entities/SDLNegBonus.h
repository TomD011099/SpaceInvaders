#ifndef SPACEINVADERS_SDLNEGBONUS_H
#define SPACEINVADERS_SDLNEGBONUS_H

#include "../../Abs/Entities/NegBonus.h"
#include "../Window/SDLWindow.h"

namespace Sdl {
    class SDLNegBonus : public Abs::NegBonus {
    public:
        SDLNegBonus(SDLWindow*, float, float, float, float);

        void visualize();

    private:
        SDLWindow* window;
    };
}

#endif