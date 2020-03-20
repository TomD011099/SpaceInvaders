#ifndef SPACEINVADERS_GAMECONSTANTS_H
#define SPACEINVADERS_GAMECONSTANTS_H

const int SCREEN_HEIGHT = 500;
const int SCREEN_WIDTH = 500;

const int SCREEN_FPS = 60;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

const int CTRL_QUIT = 1;
const int CTRL_IDLE = 0;
const int CTRL_PRESS_LEFT = 2;
const int CTRL_REL_LEFT = 3;
const int CTRL_PRESS_RIGHT = 4;
const int CTRL_REL_RIGHT = 5;
const int CTRL_PRESS_SPACE = 6;

const int PLAYERSHIP = 10;
const int ENEMYSHIP = 11;

const float PLAYER_SPEED = 10;

#endif