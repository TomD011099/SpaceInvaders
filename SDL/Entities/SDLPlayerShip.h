#ifndef SPACEINVADERS_SDLPLAYERSHIP_H
#define SPACEINVADERS_SDLPLAYERSHIP_H

#include "../../Abs/Entities/PlayerShip.h"
#include "../Window/SDLWindow.h"

namespace Sdl {
    class SDLPlayerShip : public Abs::PlayerShip {
    public:
        SDLPlayerShip(Sdl::SDLWindow*, double, double, double, double);

        void visualize();

        void killed();

    private:
        SDLWindow* window;

    };
}

#endif