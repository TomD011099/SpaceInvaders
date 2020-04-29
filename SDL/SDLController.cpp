#include <vector>
#include "SDLController.h"

/**
 * Constructor for SDLController
 */
Sdl::SDLController::SDLController() {

}

/**
 * Get all events that are happening at this moment
 *
 * @return All events happening at this moment
 */
std::vector<EVENT> Sdl::SDLController::pollEvents() {
    std::vector<EVENT> events;

    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT)             //X button -> Quit
            events.push_back(CTRL_QUIT);
    }

    const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
    if (keyboardState[SDL_SCANCODE_SPACE])  //Space key -> Shoot
        events.push_back(CTRL_SHOOT);
    if (keyboardState[SDL_SCANCODE_LEFT])   //Left arrow key -> Move left
        events.push_back(CTRL_LEFT);
    if (keyboardState[SDL_SCANCODE_RIGHT])  //Right arrow key -> Move right
        events.push_back(CTRL_RIGHT);

    return events;
}

/**
 * See if the user wants to quit
 *
 * @return true if the application needs to stop, false if not
 */
bool Sdl::SDLController::isQuit() {
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT)             //X button -> Quit
            return true;
    }

    return false;
}
