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

    static void destroyInstance();

    void run();

private:
    Game(Abs::Factory*);

    ~Game();

    static Game* instance;

    Abs::Factory* gameFactory;
    int lives, score, enemyShootCooldownCounter, enemyMoveCooldownCounter, bonusSpawnCooldownCounter;
    std::vector<EVENT> events;
    bool isQuit, isEnemyMovingLeft, isEnemyMovingHorizontal, isGameOver, hasSoundPlayed, showEndScore;

    Abs::PlayerShip* playerShip;
    Abs::Controller* controller;
    Abs::PlayerBullet* playerBullet;
    Abs::BonusEntity* bonusEntity;
    std::vector<std::vector<Abs::EnemyShip*>> enemies;
    std::vector<Abs::EnemyBullet*> enemyBullets;

    void setup();

    void generateEnemies();

    void playerShipHandler();

    void playerBulletHandler();

    void enemyShipHandler();

    void drawEnemyShip();

    void enemyBulletHandler();

    void bonusEntityHandler();

    bool isCollision(Abs::Entity*, Abs::Entity*);
};

#endif