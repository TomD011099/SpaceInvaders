#include "SDLEnemyBullet.h"

Sdl::SDLEnemyBullet::SDLEnemyBullet(Sdl::SDLWindow* window, double x, double y, double w, double h) : Abs::EnemyBullet(x, y, w, h){
    this->window = window;
}

void Sdl::SDLEnemyBullet::visualize() {
    window->render(xPos, yPos, width, height, ENEMYBULLET);
}
