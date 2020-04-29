#ifndef SPACEINVADERS_SDLPOSBONUS_H
#define SPACEINVADERS_SDLPOSBONUS_H

#include "../../Abs/Entities/PosBonus.h"
#include "../Window/SDLWindow.h"

namespace Sdl {
    /**
     * An implementation of Abs::PosBonus
     */
    class SDLPosBonus : public Abs::PosBonus {
    public:
        SDLPosBonus(SDLWindow*, double, double, double, double);

        ~SDLPosBonus() = default;

        void visualize();

    private:
        SDLWindow* window;      //The SDL game window
    };
}

#endif