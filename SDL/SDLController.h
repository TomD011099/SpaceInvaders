#ifndef SPACEINVADERS_SDLCONTROLLER_H
#define SPACEINVADERS_SDLCONTROLLER_H

#include "../Abs/Controller.h"
#include <SDL2/SDL.h>
#include <iostream>

namespace Sdl {
    class SDLController : public Abs::Controller {
    public:
        SDLController();

        int pollEvents();

    private:
        SDL_Event e;
    };
}

#endif