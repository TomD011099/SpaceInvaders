#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include <list>
#include <chrono>
#include <thread>
#include <iostream>
#include <random>
#include "Abs/Factory.h"
#include "Const/Enums.h"
#include "Const/GameConstants.h"

class Game {
public:
    static Game* getInstance(Abs::Factory*);

    static void destroyInstance();

    void run();

private:
    Game(Abs::Factory*);

    ~Game();

    static Game* instance;          //The game-instance

    GameConstants* gameConstants;

    Abs::Factory* gameFactory;      //An implementation of an Abs::Factory
    int lives, score, enemyShootCooldownCounter, enemyMoveCooldownCounter, bonusSpawnCooldownCounter;
    std::vector<EVENT> events;
    bool isQuit, isEnemyMovingLeft, isEnemyMovingHorizontal, isGameOver, hasSoundPlayed, showEndScore;

    Abs::PlayerShip* playerShip;                        //The playership
    Abs::Controller* controller;                        //The controller
    Abs::PlayerBullet* playerBullet;                    //The playerbullet
    Abs::BonusEntity* bonusEntity;                      //The bonusentity
    std::vector<std::vector<Abs::EnemyShip*>> enemies;  //The enemies
    std::vector<Abs::EnemyBullet*> enemyBullets;        //The enemybullets

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