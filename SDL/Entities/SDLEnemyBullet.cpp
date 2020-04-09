#include "SDLEnemyBullet.h"

Sdl::SDLEnemyBullet::SDLEnemyBullet(Sdl::SDLWindow* window, float x, float y, float w, float h) : Abs::EnemyBullet(x, y, w, h){
    this->window = window;
}

void Sdl::SDLEnemyBullet::visualize() {
    window->render(xPos, yPos, width, height, ENEMYBULLET);
}
