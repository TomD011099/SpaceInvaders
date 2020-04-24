#include "SDLPosBonus.h"

Sdl::SDLPosBonus::SDLPosBonus(Sdl::SDLWindow* window, double x, double y, double w, double h) : Abs::PosBonus(x, y, w, h){
    this->window = window;
}

void Sdl::SDLPosBonus::visualize() {
    window->render(xPos, yPos, width, height, POSBONUS);
}
