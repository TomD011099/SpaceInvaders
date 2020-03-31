#include <vector>
#include "SDLController.h"

Sdl::SDLController::SDLController() {

}

std::vector<EVENT> Sdl::SDLController::pollEvents() {
    std::vector<EVENT> events;

    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT)
            events.push_back(CTRL_QUIT);
    }

    const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
    if (keyboardState[SDL_SCANCODE_SPACE])
        events.push_back(CTRL_SHOOT);
    if (keyboardState[SDL_SCANCODE_LEFT])
        events.push_back(CTRL_LEFT);
    if (keyboardState[SDL_SCANCODE_RIGHT])
        events.push_back(CTRL_RIGHT);

    return events;
}