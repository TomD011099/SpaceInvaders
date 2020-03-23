#include "SDLController.h"

Sdl::SDLController::SDLController() {

}

EVENT Sdl::SDLController::pollEvents() {
    EVENT event = CTRL_IDLE;

    if (SDL_PollEvent(&e) != 0) {
        switch (e.type) {
            case SDL_QUIT:
                event = CTRL_QUIT;
                break;
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        event = CTRL_LEFT;
                        break;
                    case SDLK_RIGHT:
                        event = CTRL_RIGHT;
                        break;
                    case SDLK_SPACE:
                        event = CTRL_SHOOT;
                        break;
                    case SDLK_x:
                        event = CTRL_QUIT;
                        break;
                }
        }
    }

    return event;
}