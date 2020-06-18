#ifndef SPACEINVADERS_GAMECONSTANTS_H
#define SPACEINVADERS_GAMECONSTANTS_H

#include <chrono>
#include <map>

#include "Enums.h"

/**
 * This file is a sort of config file for SpaceInvaders, here you can decide the screen size, FPS, lives, ...
 * [...] means the unit of the constant
 */
class GameConstants {
public:
    static void initInstance(std::map<std::string, std::string>);

    static GameConstants* getInstance();

    int getScreenWidth() const;

    int getScreenHeight() const;

    int getScreenFps() const;

    int getMaxLives() const;

    double getPlayerSpeed() const;

    double getBulletSpeed() const;

    double getEnemySpeed() const;

    double getBonusSpeed() const;

    double getPlayerWidth() const;

    double getPlayerHeight() const;

    double getEnemyWidth() const;

    double getEnemyHeight() const;

    double getBulletWidth() const;

    double getBulletHeight() const;

    double getBonusWidth() const;

    double getBonusHeight() const;

    double getEnemyShootCooldown() const;

    double getEnemyMovementDelay() const;

    double getEnemyDeathTime() const;

    int getBonusSpawnRate() const;

    double getBonusSpawnCooldown() const;

    double getLowerBound() const;

    const std::map<ENTITY, int> &getScores() const;

    double getNormPlayerSpeed() const;

    double getNormBulletSpeed() const;

    int getNormEnemyShootCooldown() const;

    int getNormEnemyMoveDelay() const;

    int getNormEnemyDeath() const;

    int getNormBonusSpawnCooldown() const;

    const std::chrono::milliseconds &getScreenTime() const;

private:
    GameConstants(std::map<std::string, std::string>);

    static GameConstants* instance;

    // Screen settings
    int screenWidth;        //[px]
    int screenHeight;       //[px]
    int screenFPS;          //[Frames per second]

    // Lives
    int maxLives;

    // Speed
    double playerSpeed;     //[Relative distance per second]
    double bulletSpeed;     //[Relative distance per second]
    double enemySpeed;      //[Relative distance per second]
    double bonusSpeed;      //[Relative distance per second]

    //Size
    //Playership
    double playerWidth;     //[Relative size]
    double playerHeight;    //[Relative size]

    //Enemyship
    double enemyWidth;      //[Relative size]
    double enemyHeight;     //[Relative size]

    //Bullets
    double bulletWidth;     //[Relative size]
    double bulletHeight;    //[Relative size]

    //Bonusentity
    double bonusWidth;      //[Relative size]
    double bonusHeight;     //[Relative size]

    //Cooldowns & delays
    //Enemy
    double enemyShootCooldown;      //[seconds]
    double enemyMovementDelay;      //[seconds]
    double enemyDeathTime;          //[seconds]

    //Bonusentity
    int bonusSpawnRate;             //[% chance evey BONUS_SPAWN_COOLDOWN seconds]
    double bonusSpawnCooldown;      //[seconds]

    //Game over when enemy crosses bound
    double lowerBound = 0.9;

    //Scores
    std::map<ENTITY, int> scores = {};

    //Normalized
    double normPlayerSpeed;                 //[Relative distance per frame]
    double normBulletSpeed;                 //[Relative distance per frame]
    int normEnemyShootCooldown;             //[Frames]
    int normEnemyMoveDelay;                 //[Frames]
    int normEnemyDeath;                     //[Frames]
    int normBonusSpawnCooldown;             //[Frames]
    std::chrono::milliseconds screenTime;   //[Seconds]
};

#endif
