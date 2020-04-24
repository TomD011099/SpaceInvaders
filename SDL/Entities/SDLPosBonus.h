#ifndef SPACEINVADERS_SDLPOSBONUS_H
#define SPACEINVADERS_SDLPOSBONUS_H

#include "../../Abs/Entities/PosBonus.h"
#include "../Window/SDLWindow.h"

namespace Sdl{
    class SDLPosBonus: public Abs::PosBonus {
    public:
        SDLPosBonus(SDLWindow*, double, double, double, double);

        void visualize();

    private:
        SDLWindow* window;
    };
}

#endif