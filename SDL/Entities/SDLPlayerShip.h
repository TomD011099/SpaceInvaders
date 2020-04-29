#ifndef SPACEINVADERS_SDLPLAYERSHIP_H
#define SPACEINVADERS_SDLPLAYERSHIP_H

#include "../../Abs/Entities/PlayerShip.h"
#include "../Window/SDLWindow.h"

namespace Sdl {
    /**
     * An implementation of Abs::PlayerShip
     */
    class SDLPlayerShip : public Abs::PlayerShip {
    public:
        SDLPlayerShip(Sdl::SDLWindow*, double, double, double, double);

        ~SDLPlayerShip() = default;

        void visualize();

        void killed();

    private:
        SDLWindow* window;      //The SDL game window

    };
}

#endif