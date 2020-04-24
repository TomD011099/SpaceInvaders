#include "SDLNegBonus.h"

Sdl::SDLNegBonus::SDLNegBonus(Sdl::SDLWindow* window, double x, double y, double w, double h) : Abs::NegBonus(x, y, w, h){
    this->window = window;
}

void Sdl::SDLNegBonus::visualize() {
    window->render(xPos, yPos, width, height, NEGBONUS);
}
