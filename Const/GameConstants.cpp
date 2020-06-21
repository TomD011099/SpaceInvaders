#include "GameConstants.h"

GameConstants* GameConstants::instance = nullptr;

void GameConstants::initInstance(std::map<std::string, std::string> settings) {
    if (instance == nullptr) {
        instance = new GameConstants(settings);
    }
}

GameConstants* GameConstants::getInstance() {
    return instance;
}

void GameConstants::setInt(std::string xmlEntry, int defaultVal, int &var) {
    auto it = settings.find(xmlEntry);
    var = defaultVal;
    if (it != settings.end()) {
        if (it->second != "default") {
            try {
                var = stoi(it->second);
            } catch (const std::invalid_argument &e) {
                std::cout << "ERR: " << xmlEntry << " not valid\n";
            }
        }
    }
}

void GameConstants::setDouble(std::string xmlEntry, double defaultVal, double &var) {
    auto it = settings.find(xmlEntry);
    var = defaultVal;
    if (it != settings.end()) {
        if (it->second != "default") {
            try {
                var = stod(it->second);
            } catch (const std::invalid_argument &e) {
                std::cout << "ERR: " << xmlEntry << " not valid\n";
            }
        }
    }
}

GameConstants::GameConstants(std::map<std::string, std::string> settings) {
    this->settings = settings;

    setInt("Screen.Width", 1000, screenWidth);

    setInt("Screen.Height", 700, screenHeight);

    setInt("Screen.FPS", 60, screenFPS);

    setInt("Lives", 3, maxLives);

    setDouble("Speed.Player", 0.5, playerSpeed);

    setDouble("Speed.Bullet", 0.8, bulletSpeed);

    setDouble("Speed.Enemy", 0.04, enemySpeed);

    setDouble("Speed.Bonus", 0.005, bonusSpeed);

    setDouble("Size.Player.Width", 0.05, playerWidth);

    setDouble("Size.Player.Height", 0.05, playerHeight);

    setDouble("Size.Enemy.Width", 0.05, enemyWidth);

    setDouble("Size.Enemy.Height", 0.04, enemyHeight);

    setDouble("Size.Bullet.Width", 0.005, bulletWidth);

    setDouble("Size.Bullet.Height", 0.03, bulletHeight);

    setDouble("Size.Bonus.Width", 0.1, bonusWidth);

    setDouble("Size.Bonus.Height", 0.05, bonusHeight);

    setDouble("Cooldown.Enemy.Shooting", 0.35, enemyShootCooldown);

    setDouble("Cooldown.Enemy.Movement", 1, enemyMovementDelay);

    setDouble("Cooldown.Enemy.Death", 0.5, enemyDeathTime);

    setInt("Cooldown.Bonus.SpawnRate", 5, bonusSpawnRate);

    setDouble("Cooldown.Bonus.SpawnCooldown", 0.25, bonusSpawnCooldown);

    setDouble("LowerBound", 0.9, lowerBound);

    setInt("Scores.E0", 100, scores[ENEMYSHIP0]);

    setInt("Scores.E1", 80, scores[ENEMYSHIP1]);

    setInt("Scores.E2", 60, scores[ENEMYSHIP2]);

    setInt("Scores.E3", 40, scores[ENEMYSHIP3]);

    setInt("Scores.E4", 20, scores[ENEMYSHIP4]);

    setInt("Scores.Pos", 200, scores[POSBONUS]);

    setInt("Scores.Neg", -200, scores[NEGBONUS]);

    normPlayerSpeed = playerSpeed / screenFPS;
    normBulletSpeed = bulletSpeed / screenFPS;
    normEnemyShootCooldown = enemyShootCooldown * screenFPS;
    normEnemyMoveDelay = enemyMovementDelay * screenFPS;
    normEnemyDeath = enemyDeathTime * screenFPS;
    normBonusSpawnCooldown = bonusSpawnCooldown * screenFPS;
    screenTime = std::chrono::milliseconds(1000 / screenFPS);
}

int GameConstants::getScreenWidth() const {
    return screenWidth;
}

int GameConstants::getScreenHeight() const {
    return screenHeight;
}

int GameConstants::getScreenFps() const {
    return screenFPS;
}

int GameConstants::getMaxLives() const {
    return maxLives;
}

double GameConstants::getPlayerSpeed() const {
    return playerSpeed;
}

double GameConstants::getBulletSpeed() const {
    return bulletSpeed;
}

double GameConstants::getEnemySpeed() const {
    return enemySpeed;
}

double GameConstants::getBonusSpeed() const {
    return bonusSpeed;
}

double GameConstants::getPlayerWidth() const {
    return playerWidth;
}

double GameConstants::getPlayerHeight() const {
    return playerHeight;
}

double GameConstants::getEnemyWidth() const {
    return enemyWidth;
}

double GameConstants::getEnemyHeight() const {
    return enemyHeight;
}

double GameConstants::getBulletWidth() const {
    return bulletWidth;
}

double GameConstants::getBulletHeight() const {
    return bulletHeight;
}

double GameConstants::getBonusWidth() const {
    return bonusWidth;
}

double GameConstants::getBonusHeight() const {
    return bonusHeight;
}

double GameConstants::getEnemyShootCooldown() const {
    return enemyShootCooldown;
}

double GameConstants::getEnemyMovementDelay() const {
    return enemyMovementDelay;
}

double GameConstants::getEnemyDeathTime() const {
    return enemyDeathTime;
}

int GameConstants::getBonusSpawnRate() const {
    return bonusSpawnRate;
}

double GameConstants::getBonusSpawnCooldown() const {
    return bonusSpawnCooldown;
}

double GameConstants::getLowerBound() const {
    return lowerBound;
}

const std::map<ENTITY, int> &GameConstants::getScores() const {
    return scores;
}

double GameConstants::getNormPlayerSpeed() const {
    return normPlayerSpeed;
}

double GameConstants::getNormBulletSpeed() const {
    return normBulletSpeed;
}

int GameConstants::getNormEnemyShootCooldown() const {
    return normEnemyShootCooldown;
}

int GameConstants::getNormEnemyMoveDelay() const {
    return normEnemyMoveDelay;
}

int GameConstants::getNormEnemyDeath() const {
    return normEnemyDeath;
}

int GameConstants::getNormBonusSpawnCooldown() const {
    return normBonusSpawnCooldown;
}

const std::chrono::milliseconds &GameConstants::getScreenTime() const {
    return screenTime;
}