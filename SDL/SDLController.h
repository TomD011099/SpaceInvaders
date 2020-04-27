#ifndef SPACEINVADERS_SDLCONTROLLER_H
#define SPACEINVADERS_SDLCONTROLLER_H

#include "../Abs/Controller.h"
#include <SDL2/SDL.h>
#include <iostream>

namespace Sdl {

    class SDLController : public Abs::Controller {
    public:
        SDLController();

        ~SDLController() = default;

        std::vector<EVENT> pollEvents();

        bool isQuit();

    private:
        //The SDL event checker
        SDL_Event e;
    };
}

#endif