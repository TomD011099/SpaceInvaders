#include "SDLNegBonus.h"

Sdl::SDLNegBonus::SDLNegBonus(Sdl::SDLWindow* window, float x, float y, float w, float h) : Abs::NegBonus(x, y, w, h){
    this->window = window;
}

void Sdl::SDLNegBonus::visualize() {
    window->render(xPos, yPos, width, height, NEGBONUS);
}
