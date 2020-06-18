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

GameConstants::GameConstants(std::map<std::string, std::string> settings) {
    auto it = settings.find("Screen.Width");
    screenWidth = 1000;
    if (it != settings.end()) {
        if (it->second != "default") {
            screenWidth = stoi(it->second);
        }
    }

    it = settings.find("Screen.Height");
    screenHeight = 700;
    if (it != settings.end()) {
        if (it->second != "default") {
            screenHeight = stoi(it->second);
        }
    }

    it = settings.find("Screen.FPS");
    screenFPS = 60;
    if (it != settings.end()) {
        if (it->second != "default") {
            screenFPS = stoi(it->second);
        }
    }

    it = settings.find("Lives");
    maxLives = 3;
    if (it != settings.end()) {
        if (it->second != "default") {
            maxLives = stoi(it->second);
        }
    }

    it = settings.find("Speed.Player");
    playerSpeed = 0.5;
    if (it != settings.end()) {
        if (it->second != "default") {
            playerSpeed = stod(it->second);
        }
    }

    it = settings.find("Speed.Bullet");
    bulletSpeed = 0.8;
    if (it != settings.end()) {
        if (it->second != "default") {
            bulletSpeed = stod(it->second);
        }
    }

    it = settings.find("Speed.Enemy");
    enemySpeed = 0.04;
    if (it != settings.end()) {
        if (it->second != "default") {
            enemySpeed = stod(it->second);
        }
    }

    it = settings.find("Speed.Bonus");
    bonusSpeed = 0.005;
    if (it != settings.end()) {
        if (it->second != "default") {
            bonusSpeed = stod(it->second);
        }
    }

    it = settings.find("Size.Player.Width");
    playerWidth = 0.05;
    if (it != settings.end()) {
        if (it->second != "default") {
            playerWidth = stod(it->second);
        }
    }

    it = settings.find("Size.Player.Height");
    playerHeight = 0.05;
    if (it != settings.end()) {
        if (it->second != "default") {
            playerHeight = stod(it->second);
        }
    }

    it = settings.find("Size.Enemy.Width");
    enemyWidth = 0.05;
    if (it != settings.end()) {
        if (it->second != "default") {
            enemyWidth = stod(it->second);
        }
    }

    it = settings.find("Size.Enemy.Height");
    enemyHeight = 0.04;
    if (it != settings.end()) {
        if (it->second != "default") {
            enemyHeight = stod(it->second);
        }
    }

    it = settings.find("Size.Bullet.Width");
    bulletWidth = 0.005;
    if (it != settings.end()) {
        if (it->second != "default") {
            bulletWidth = stod(it->second);
        }
    }

    it = settings.find("Size.Bullet.Height");
    bulletHeight = 0.03;
    if (it != settings.end()) {
        if (it->second != "default") {
            bulletHeight = stod(it->second);
        }
    }

    it = settings.find("Size.Bonus.Width");
    bonusWidth = 0.1;
    if (it != settings.end()) {
        if (it->second != "default") {
            bonusWidth = stod(it->second);
        }
    }

    it = settings.find("Size.Bonus.Height");
    bonusHeight = 0.05;
    if (it != settings.end()) {
        if (it->second != "default") {
            bonusHeight = stod(it->second);
        }
    }

    it = settings.find("Cooldown.Enemy.Shooting");
    enemyShootCooldown = 0.35;
    if (it != settings.end()) {
        if (it->second != "default") {
            enemyShootCooldown = stod(it->second);
        }
    }

    it = settings.find("Cooldown.Enemy.Movement");
    enemyMovementDelay = 1;
    if (it != settings.end()) {
        if (it->second != "default") {
            enemyMovementDelay = stod(it->second);
        }
    }

    it = settings.find("Cooldown.Enemy.Death");
    enemyDeathTime = 0.5;
    if (it != settings.end()) {
        if (it->second != "default") {
            enemyDeathTime = stod(it->second);
        }
    }

    it = settings.find("Cooldown.Bonus.SpawnRate");
    bonusSpawnRate = 5;
    if (it != settings.end()) {
        if (it->second != "default") {
            bonusSpawnRate = stoi(it->second);
        }
    }

    it = settings.find("Cooldown.Bonus.SpawnCooldown");
    bonusSpawnCooldown = 0.25;
    if (it != settings.end()) {
        if (it->second != "default") {
            bonusSpawnCooldown = stod(it->second);
        }
    }

    it = settings.find("LowerBound");
    lowerBound = 0.9;
    if (it != settings.end()) {
        if (it->second != "default") {
            lowerBound = stod(it->second);
        }
    }

    it = settings.find("LowerBound");
    lowerBound = 0.9;
    if (it != settings.end()) {
        if (it->second != "default") {
            lowerBound = stod(it->second);
        }
    }

    it = settings.find("Scores.E0");
    scores[ENEMYSHIP0] = 100;
    if (it != settings.end()) {
        if (it->second != "default") {
            scores[ENEMYSHIP0] = stoi(it->second);
        }
    }

    it = settings.find("Scores.E1");
    scores[ENEMYSHIP1] = 80;
    if (it != settings.end()) {
        if (it->second != "default") {
            scores[ENEMYSHIP1] = stoi(it->second);
        }
    }

    it = settings.find("Scores.E2");
    scores[ENEMYSHIP2] = 60;
    if (it != settings.end()) {
        if (it->second != "default") {
            scores[ENEMYSHIP2] = stoi(it->second);
        }
    }

    it = settings.find("Scores.E3");
    scores[ENEMYSHIP3] = 40;
    if (it != settings.end()) {
        if (it->second != "default") {
            scores[ENEMYSHIP3] = stoi(it->second);
        }
    }

    it = settings.find("Scores.E4");
    scores[ENEMYSHIP4] = 20;
    if (it != settings.end()) {
        if (it->second != "default") {
            scores[ENEMYSHIP4] = stoi(it->second);
        }
    }

    it = settings.find("Scores.Pos");
    scores[POSBONUS] = 200;
    if (it != settings.end()) {
        if (it->second != "default") {
            scores[POSBONUS] = stoi(it->second);
        }
    }

    it = settings.find("Scores.Neg");
    scores[NEGBONUS] = -200;
    if (it != settings.end()) {
        if (it->second != "default") {
            scores[NEGBONUS] = stoi(it->second);
        }
    }

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