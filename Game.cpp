#include "Game.h"


Game* Game::instance = nullptr;

Game::Game(Abs::Factory* absFactory) {
    gameFactory = absFactory;
    lives = MAX_LIVES;
    score = 0;
    isQuit = false;
    isEnemyMovingLeft = true;
    isEnemyMovingHorizontal = true;
    enemyShootCooldownCounter = 0;
    enemyMoveCooldownCounter = 0;

    playerShip = nullptr;
    playerBullet = nullptr;
    controller = nullptr;

    srand(time(nullptr));
}

Game* Game::getInstance(Abs::Factory* absFactory) {
    if (instance == nullptr)
        instance = new Game(absFactory);
    return instance;
}

/*
 * Coordinates:
 *
 *    0                             1
 *  0 x----------------------------->
 *    |
 *    |
 *    |
 *    |
 *    |
 *  1 v
 */
void Game::run() {
    setup();

    while (!isQuit && !enemies.empty()) {
        std::chrono::time_point start = std::chrono::system_clock::now();

        gameFactory->setupFrame();

        playerShipHandler(&isQuit);

        playerBulletHandler();

        enemyShipHandler();

        enemyBulletHandler();

        gameFactory->draw();

        std::this_thread::sleep_until(start + SCREEN_TIME);
    }
}

void Game::setup() {
    controller = gameFactory->createController();
    playerShip = gameFactory->createPlayerShip(0.5, 0.9, PLAYERSHIP_WIDTH, PLAYERSHIP_HEIGHT);
    generateEnemies();
}

void Game::generateEnemies() {
    float x = ENEMYSHIP_WIDHT / 2, y;
    ENTITY e = ENEMYSHIP0;

    for (int i = 0; i < 11; i++) {
        std::vector<Abs::EnemyShip*> column;
        y = 0.05;

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
                    enemyShip->hit();
                    delete playerBullet;
                    playerBullet = nullptr;
                    hit = true;
                }
            }
        }
        if (!hit)
            playerBullet->visualize();
    }
}

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
                    std::cout << "Enemy erased\n";
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

        float minX = enemies[0][0]->getXPos();
        float maxX = enemies[enemies.size() - 1][0]->getXPos();
        float movement = 0;

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

        for (std::vector<Abs::EnemyShip*> column : enemies) {
            for (Abs::EnemyShip* enemyShip : column) {
                if (isEnemyMovingHorizontal) {
                    enemyShip->move(movement, 0);
                } else {
                    enemyShip->move(0, ENEMY_SPEED);
                }
            }
        }

        isEnemyMovingHorizontal = true;
    } else {
        enemyMoveCooldownCounter++;
    }

    for (std::vector<Abs::EnemyShip*> column : enemies) {
        for (Abs::EnemyShip* enemyShip : column) {
            if (enemyShip->isAlive() || !enemyShip->isGone())
                enemyShip->visualize();
        }
    }

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

void Game::enemyBulletHandler() {
    for (int i = 0; i < enemyBullets.size(); i++) {
        Abs::EnemyBullet* bullet = enemyBullets.at(i);
        float y = bullet->getYPos();

        if (y > 1) {
            delete bullet;
            enemyBullets.erase(enemyBullets.begin() + (i--));
        } else {
            bullet->move(0, NORMALISED_BULLET_SPEED);
            bullet->visualize();
        }
    }
}

bool Game::isCollision(Abs::Entity* e1, Abs::Entity* e2) {
    //The sides of the rectangles
    float left1 = 0, left2 = 0, right1 = 0, right2 = 0, top1 = 0, top2 = 0, bottom1 = 0, bottom2 = 0;

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



