#ifndef SPACEINVADERS_SDLPOSBONUS_H
#define SPACEINVADERS_SDLPOSBONUS_H

#include "../../Abs/Entities/PosBonus.h"
#include "../Window/SDLWindow.h"

namespace Sdl{
    class SDLPosBonus: public Abs::PosBonus {
    public:
        SDLPosBonus(SDLWindow*, float, float, float, float);

        void visualize();

    private:
        SDLWindow* window;
    };
}

#endif