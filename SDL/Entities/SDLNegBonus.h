#ifndef SPACEINVADERS_SDLNEGBONUS_H
#define SPACEINVADERS_SDLNEGBONUS_H

#include "../../Abs/Entities/NegBonus.h"
#include "../Window/SDLWindow.h"

namespace Sdl {
    /**
     * An implementation of Abs::NegBonus
     */
    class SDLNegBonus : public Abs::NegBonus {
    public:
        SDLNegBonus(SDLWindow*, double, double, double, double);

        ~SDLNegBonus() = default;

        void visualize();

    private:
        SDLWindow* window;      //The SDL game window
    };
}

#endif