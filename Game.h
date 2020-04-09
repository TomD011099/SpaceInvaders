#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include <list>
#include <chrono>
#include <thread>
#include <iostream>
#include <random>
#include "Abs/Factory.h"

class Game {
public:
    static Game* getInstance(Abs::Factory*);

    /**
     * Run the game
     */
    void run();

private:
    /**
     * Constructor of Game, takes a factory of your choosing (needs to inherit from Abs::Factory)
     */
    Game(Abs::Factory*);
    static Game* instance;

    Abs::Factory* gameFactory;                  //The factory that will create all specific items
    int lives, score, cooldownCounter;
    std::vector<EVENT> events;
    bool quit;

    Abs::PlayerShip* playerShip;
    Abs::Controller* controller;
    Abs::PlayerBullet* playerBullet;
    std::vector<std::vector<Abs::EnemyShip*>> enemies;
    std::vector<Abs::EnemyBullet*> enemyBullets;

    void setup();

    void generateEnemies();

    void playerShipHandler(bool*);

    void playerBulletHandler();

    void enemyShipHandler();

    void enemyBulletHandler();
};


#endif