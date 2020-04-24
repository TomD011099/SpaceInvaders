#include "Game.h"

Game* Game::instance = nullptr;

/// The constructor of Game, it is private because of Game being a Singleton
/// \param absFactory an implementation of an abstract factory, this will define the engine
Game::Game(Abs::Factory* absFactory) {
    gameFactory = absFactory;
    lives = MAX_LIVES;
    score = 0;
    isQuit = false;
    isGameOver = false;
    showEndScore = false;
    hasSoundPlayed = false;
    isEnemyMovingLeft = true;
    isEnemyMovingHorizontal = true;
    enemyShootCooldownCounter = 0;
    enemyMoveCooldownCounter = 0;
    bonusSpawnCooldownCounter = 0;

    playerShip = nullptr;
    playerBullet = nullptr;
    controller = nullptr;
    bonusEntity = nullptr;

    srand(time(nullptr));
}

/// Destructor of game
Game::~Game() {

    //TODO delete factory

    delete playerShip;
    delete playerBullet;
    delete controller;
    delete bonusEntity;

    for (int i = 0; i < enemies.size(); i++) {
        for (int j = 0; j < enemies[i].size(); j++) {
            Abs::EnemyShip* enemyShip = enemies[i].at(j);
            delete enemyShip;
            enemies[i].erase(enemies[i].begin() + (j--));
        }
    }

    for (int i = 0; i < enemyBullets.size(); i++) {
        Abs::EnemyBullet* enemyBullet = enemyBullets.at(i);
        delete enemyBullet;
        enemyBullets.erase(enemyBullets.begin() + (i--));
    }
}

/// The way of getting the game object
/// \param absFactory an implementation of an abstract factory, this will define the engine
/// \return A new game instance or the current game instance
Game* Game::getInstance(Abs::Factory* absFactory) {
    if (instance == nullptr)
        instance = new Game(absFactory);
    return instance;
}

/// Destructor for singleton
void Game::destroyInstance() {
    delete instance;
    instance = nullptr;
}

/// Run the game
/// The game runs in three major parts: setup, main, loop, end
///     * setup: Entities are spawned and a controller is generated
///     * main: A timed loop which handles all of the game logic
///     * end: end screen and cleanup
void Game::run() {
    setup();

    while (!isQuit) {
        std::chrono::time_point start = std::chrono::system_clock::now();

        gameFactory->setupFrame();

        if (lives <= 0 || isGameOver) {
            if (!hasSoundPlayed) {
                if (lives <= 0) {
                    playerShip->killed();
                }
                gameFactory->playSound(LOSS);
                hasSoundPlayed = true;
                showEndScore = true;
            }
            isQuit = controller->isQuit();
            playerShip->visualize();
            drawEnemyShip();
        } else if (enemies.empty()) {
            if (!hasSoundPlayed) {
                gameFactory->playSound(VICTORY);
                score += lives * 500;
                hasSoundPlayed = true;
                showEndScore = true;
            }
            isQuit = controller->isQuit();
            playerShip->visualize();
        } else {

            playerShipHandler(&isQuit);

            playerBulletHandler();

            enemyShipHandler();

            enemyBulletHandler();

            bonusEntityHandler();
        }

        gameFactory->draw(score, lives, showEndScore);

        std::this_thread::sleep_until(start + SCREEN_TIME);
    }
}

/// Entities are spawned and a controller is generated
void Game::setup() {
    controller = gameFactory->createController();
    playerShip = gameFactory->createPlayerShip(0.5, 0.9, PLAYERSHIP_WIDTH, PLAYERSHIP_HEIGHT);
    generateEnemies();
}

/// The grid of enemies is generated
void Game::generateEnemies() {
    double x = ENEMYSHIP_WIDHT / 2, y;
    ENTITY e = ENEMYSHIP0;

    for (int i = 0; i < 11; i++) {
        std::vector<Abs::EnemyShip*> column;
        y = 0.1;

        for (int j = 0; j < 5; j++) {
            y += (ENEMYSHIP_HEIGHT + 0.015);

            switch (j) {
                case 0:
                    e = ENEMYSHIP0;
                    break;
                case 1:
                    e = ENEMYSHIP1;
                    break;
                case 2:
                    e = ENEMYSHIP2;
                    break;
                case 3:
                    e = ENEMYSHIP3;
                    break;
                case 4:
                    e = ENEMYSHIP4;
                    break;
                default:
                    break;
            }
            column.push_back(gameFactory->createEnemyShip(x, y, ENEMYSHIP_WIDHT, ENEMYSHIP_HEIGHT, e));
        }

        enemies.push_back(column);
        x += (ENEMYSHIP_WIDHT + 0.015); //Distance between
    }
}

/// Handles the playerships movement and shooting
/// There can be only one bullet at the same time
void Game::playerShipHandler(bool* quit_psh) {
    events = controller->pollEvents();

    for (EVENT event : events) {
        switch (event) {
            case CTRL_LEFT:
                playerShip->move(-NORMALISED_SPEED, 0);
                break;
            case CTRL_RIGHT:
                playerShip->move(NORMALISED_SPEED, 0);
                break;
            case CTRL_SHOOT:
                if (playerBullet == nullptr) {
                    playerBullet = gameFactory->createPlayerBullet(playerShip->getXPos(), playerShip->getYPos(),
                                                                   BULLET_WIDTH, BULLET_HEIGHT);
                }
                break;
            case CTRL_QUIT:
                *quit_psh = true;
                break;
            default:
                break;
        }
    }
    playerShip->visualize();
}

/// Moves the playerbullet, checks if it goes out of bounds and does collisio detection with all enemies
void Game::playerBulletHandler() {
    if (playerBullet != nullptr) {
        if (playerBullet->getYPos() < 0) {
            delete playerBullet;
            playerBullet = nullptr;
            return;
        } else {
            playerBullet->move(0, -NORMALISED_BULLET_SPEED);
        }
        bool hit = false;
        for (int i = 0; (i < enemies.size() && !hit); i++) {
            for (int j = 0; (j < enemies[i].size() && !hit); j++) {
                Abs::EnemyShip* enemyShip = enemies[i].at(j);
                if (isCollision(playerBullet, enemyShip) && enemyShip->isAlive()) {
                    score += getScore(enemyShip->getType());
                    enemyShip->hit();
                    delete playerBullet;
                    playerBullet = nullptr;
                    hit = true;
                }
            }
        }
        if (bonusEntity != nullptr && !hit) {
            if (isCollision(playerBullet, bonusEntity)) {
                score += getScore(bonusEntity->getEntity());
                delete playerBullet;
                playerBullet = nullptr;
                delete bonusEntity;
                bonusEntity = nullptr;
                hit = true;
            }
        }
        if (!hit)
            playerBullet->visualize();
    }
}

void Game::drawEnemyShip() {
    for (const std::vector<Abs::EnemyShip*> &column : enemies) {
        for (Abs::EnemyShip* enemyShip : column) {
            if (enemyShip->isAlive() || !enemyShip->isGone())
                enemyShip->visualize();
        }
    }
}

/// Handles the enemyship movements and decides when they can shoot
void Game::enemyShipHandler() {
    for (int i = 0; i < enemies.size(); i++) {
        bool isColumnAlive = false;
        for (int j = 0; j < enemies[i].size(); j++) {
            Abs::EnemyShip* enemyShip = enemies[i].at(j);
            if (enemyShip->isAlive()) {
                isColumnAlive = true;
            } else {
                enemyShip->tick();
                if (enemyShip->isGone()) {
                    delete enemyShip;
                    enemies[i].erase(enemies[i].begin() + (j--));
                } else {
                    isColumnAlive = true;
                }
            }
        }

        if (!isColumnAlive) {
            enemies.erase(enemies.begin() + (i--));
        }
    }

    if (enemyMoveCooldownCounter == NORMALIZED_ENEMY_MOVEMENT_DELAY) {
        enemyMoveCooldownCounter = 0;

        double minX = enemies[0][0]->getXPos();
        double maxX = enemies[enemies.size() - 1][0]->getXPos();
        double movement = 0;

        if (isEnemyMovingLeft) {
            if (minX - ENEMY_SPEED <= ENEMYSHIP_WIDHT / 2 && isEnemyMovingHorizontal) {
                isEnemyMovingHorizontal = false;
                isEnemyMovingLeft = false;
            } else {
                movement = -ENEMY_SPEED;
            }
        } else {
            if (maxX + ENEMY_SPEED >= (1 - ENEMYSHIP_WIDHT / 2) && isEnemyMovingHorizontal) {
                isEnemyMovingHorizontal = false;
                isEnemyMovingLeft = true;
            } else {
                movement = ENEMY_SPEED;
            }
        }

        double lowestY = 0;

        for (const std::vector<Abs::EnemyShip*> &column : enemies) {
            for (Abs::EnemyShip* enemyShip : column) {
                if (isEnemyMovingHorizontal) {
                    enemyShip->move(movement, 0);
                } else {
                    enemyShip->move(0, ENEMY_SPEED);
                    double y = enemyShip->getYPos();
                    if (y > lowestY) {
                        lowestY = y;
                    }
                }

                if (isCollision(enemyShip, playerShip)) {
                    lives = 0;
                }
            }
        }

        if (lowestY >= ENEMY_LOWER_BOUND) {
            isGameOver = true;
        }

        isEnemyMovingHorizontal = true;

    } else {
        enemyMoveCooldownCounter++;
    }

    drawEnemyShip();

    if (enemyShootCooldownCounter == NORMALIZED_ENEMY_COOLDOWN) {
        enemyShootCooldownCounter = 0;
        int shootingColumn = rand() % 11;
        for (auto it = enemies[shootingColumn].rbegin(); it != enemies[shootingColumn].rend(); ++it) {
            Abs::EnemyShip* ship = *it;
            if (ship->isAlive()) {
                enemyBullets.push_back(
                        gameFactory->createEnemyBullet(ship->getXPos(), ship->getYPos(), BULLET_WIDTH, BULLET_HEIGHT));
                break;
            }
        }
    } else {
        enemyShootCooldownCounter++;
    }
}

/// Moves the enemybullets, checks if they go out of bounds and detects collision with the player
void Game::enemyBulletHandler() {
    for (int i = 0; i < enemyBullets.size(); i++) {
        Abs::EnemyBullet* bullet = enemyBullets.at(i);
        if (bullet->getYPos() < 0) {
            delete bullet;
            enemyBullets.erase(enemyBullets.begin() + (i--));
            return;
        } else {
            bullet->move(0, NORMALISED_BULLET_SPEED);
        }

        if (isCollision(bullet, playerShip)) {
            lives--;
            gameFactory->playSound(HIT);
            delete bullet;
            enemyBullets.erase(enemyBullets.begin() + (i--));
        } else {
            bullet->visualize();
        }
    }
}

/// Moves the bonusEntity, if there is none, there is a chance one spawns
void Game::bonusEntityHandler() {
    if (bonusEntity != nullptr) {
        if ((bonusEntity->getXPos()) >= (1 + (bonusEntity->getWidth() / 2.0))) {
            delete bonusEntity;
            bonusEntity = nullptr;
            std::cout << "deleted\n";
            return;
        } else {
            bonusEntity->move(BONUS_SPEED, 0);
            bonusEntity->visualize();
        }
    } else {
        if (bonusSpawnCooldownCounter >= NORMALISED_BONUS_SPAWN_COOLDOWN) {
            if (rand() % 100 <= BONUS_SPAWN_RATE) {
                if (rand() % 100 <= 50) {
                    bonusEntity = gameFactory->createPosBonus(-BONUS_WIDTH/2, 0.09, BONUS_WIDTH, BONUS_HEIGHT);
                    bonusEntity->visualize();
                } else {
                    bonusEntity = gameFactory->createNegBonus(-BONUS_WIDTH/2, 0.09, BONUS_WIDTH, BONUS_HEIGHT);
                    bonusEntity->visualize();
                }
            }
            bonusSpawnCooldownCounter = 0;
        } else {
            bonusSpawnCooldownCounter++;
        }
    }
}

/// Checks if two entities collide
/// \param e1 The first entity
/// \param e2 The second entity
/// \return True if there is collision, false if not
bool Game::isCollision(Abs::Entity* e1, Abs::Entity* e2) {
    //The sides of the rectangles
    double left1, left2, right1, right2, top1, top2, bottom1, bottom2;

    //Calculate the sides of rect 1
    left1 = e1->getXPos() - (e1->getWidth() / 2);
    right1 = e1->getXPos() + (e1->getWidth() / 2);
    top1 = e1->getYPos() - (e1->getHeight() / 2);
    bottom1 = e1->getYPos() + (e1->getHeight() / 2);

    //Calculate the sides of rect 2
    left2 = e2->getXPos() - (e2->getWidth() / 2);
    right2 = e2->getXPos() + (e2->getWidth() / 2);
    top2 = e2->getYPos() - (e2->getHeight() / 2);
    bottom2 = e2->getYPos() + (e2->getHeight() / 2);

    //If any of the sides from A are outside of B
    if (bottom1 <= top2) {
        return false;
    }

    if (top1 >= bottom2) {
        return false;
    }

    if (right1 <= left2) {
        return false;
    }

    if (left1 >= right2) {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

/// Gives the score of an entity
/// \param e the entity of which you want the score
/// \return the score
int Game::getScore(ENTITY e) {
    switch (e) {
        case ENEMYSHIP0:
            return 100;
        case ENEMYSHIP1:
            return 80;
        case ENEMYSHIP2:
            return 60;
        case ENEMYSHIP3:
            return 40;
        case ENEMYSHIP4:
            return 20;
        case POSBONUS:
            return 200;
        case NEGBONUS:
            return -200;
        default:
            return 0;
    }
}