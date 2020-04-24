#include "SDLPosBonus.h"

Sdl::SDLPosBonus::SDLPosBonus(Sdl::SDLWindow* window, float x, float y, float w, float h) : Abs::PosBonus(x, y, w, h){
    this->window = window;
}

void Sdl::SDLPosBonus::visualize() {
    window->render(xPos, yPos, width, height, POSBONUS);
}
