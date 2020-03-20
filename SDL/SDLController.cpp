#include "SDLController.h"

Sdl::SDLController::SDLController() {

}

int Sdl::SDLController::pollEvents() {
    if (SDL_PollEvent(&e) != 0) {
        switch (e.type) {
            case SDL_QUIT:
                std::cout << "Exit\n";
                return CTRL_QUIT;
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        std::cout << "Left\n";
                        return CTRL_PRESS_LEFT;
                    case SDLK_RIGHT:
                        std::cout << "Right\n";
                        return CTRL_PRESS_RIGHT;
                    case SDLK_SPACE:
                        std::cout << "Space\n";
                        return CTRL_PRESS_SPACE;
                    case SDLK_x:
                        std::cout << "Exit\n";
                        return CTRL_QUIT;
                }
        }
    }

    return CTRL_IDLE;
}