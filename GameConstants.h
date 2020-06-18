#ifndef SPACEINVADERS_GAMECONSTANTS_H
#define SPACEINVADERS_GAMECONSTANTS_H

#include <chrono>
#include <map>

///This file is a sort of config file for SpaceInvaders, here you can decide the screen size, FPS, lives, ...
/// [...] means the unit of the constant

// Screen settings
const int SCREEN_WIDTH = 1000;  //[px]
const int SCREEN_HEIGHT = 700;  //[px]
const int SCREEN_FPS = 60;      //[Frames per second]

// Lives
const int MAX_LIVES = 3;

// Speed
const double PLAYER_SPEED = 0.5;    //[Relative distance per second]
const double BULLET_SPEED = 0.8;    //[Relative distance per second]
const double ENEMY_SPEED = 0.04;    //[Relative distance per second]
const double BONUS_SPEED = 0.005;   //[Relative distance per second]

//Size
//Playership
const double PLAYERSHIP_WIDTH = 0.05;   //[Relative size]
const double PLAYERSHIP_HEIGHT = 0.05;  //[Relative size]

//Enemyship
const double ENEMYSHIP_WIDHT = 0.05;    //[Relative size]
const double ENEMYSHIP_HEIGHT = 0.04;   //[Relative size]

//Bullets
const double BULLET_WIDTH = 0.005;      //[Relative size]
const double BULLET_HEIGHT = 0.03;      //[Relative size]

//Bonusentity
const double BONUS_WIDTH = 0.1;         //[Relative size]
const double BONUS_HEIGHT = 0.05;       //[Relative size]

//Cooldowns & delays
//Enemy
const double ENEMY_COOLDOWN = 0.35;         //[seconds]
const double ENEMY_MOVEMENT_DELAY = 1;      //[seconds]
const double ENEMY_DEATH_TIME = 0.5;        //[seconds]

//Bonusentity
const int BONUS_SPAWN_RATE = 5;             //[% chance evey BONUS_SPWAN_COOLDOWN seconds]
const double BONUS_SPAWN_COOLDOWN = 0.25;   //[seconds]

//Game over when enemy crosses bound
const double ENEMY_LOWER_BOUND = 0.9;

// Enumerators
enum EVENT {
    CTRL_QUIT, CTRL_LEFT, CTRL_RIGHT, CTRL_SHOOT
};

enum ENTITY {
    PLAYERSHIP,
    ENEMYSHIP0,
    ENEMYSHIP1,
    ENEMYSHIP2,
    ENEMYSHIP3,
    ENEMYSHIP4,
    ENEMY_WRECK,
    PLAYER_WRECK,
    PLAYERBULLET,
    ENEMYBULLET,
    POSBONUS,
    NEGBONUS
};

enum SOUND {
    EXPLOSION, INVADER_KILLED, SHOOT, HIT, LOSS, VICTORY, BONUS_SPAWN
};

//Scores
const std::map<ENTITY, int> scores = {
        {ENEMYSHIP0, 100},
        {ENEMYSHIP1, 80},
        {ENEMYSHIP2, 60},
        {ENEMYSHIP3, 40},
        {ENEMYSHIP4, 20},
        {POSBONUS,   200},
        {NEGBONUS,   -200}
};

//Calculations
const double NORMALISED_SPEED = PLAYER_SPEED / SCREEN_FPS;                      //[Relative distance per frame]
const double NORMALISED_BULLET_SPEED = BULLET_SPEED / SCREEN_FPS;               //[Relative distance per frame]
const int NORMALIZED_ENEMY_COOLDOWN = ENEMY_COOLDOWN * SCREEN_FPS;              //[Frames]
const int NORMALIZED_ENEMY_MOVEMENT_DELAY = ENEMY_MOVEMENT_DELAY * SCREEN_FPS;  //[Frames]
const int NORMALISED_ENEMY_DEATH_TIME = ENEMY_DEATH_TIME * SCREEN_FPS;          //[Frames]
const int NORMALISED_BONUS_SPAWN_COOLDOWN = BONUS_SPAWN_COOLDOWN * SCREEN_FPS;  //[Frames]
const auto SCREEN_TIME = std::chrono::milliseconds(1000 / SCREEN_FPS);      //[Seconds]

#endif
