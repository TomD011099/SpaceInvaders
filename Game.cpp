#include "Game.h"


Game* Game::instance = nullptr;

Game::Game(Abs::Factory* absFactory) {
    gameFactory = absFactory;
    lives = MAX_LIVES;
    score = 0;
    quit = false;
    cooldownCounter = 0;

    playerShip = nullptr;
    playerBullet = nullptr;
    controller = nullptr;
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

    while (!quit) {
        std::chrono::time_point start = std::chrono::system_clock::now();

        gameFactory->setupFrame();

        playerShipHandler(&quit);

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
        float y = playerBullet->getYPos();

        if (y < 0) {
            delete playerBullet;
            playerBullet = nullptr;
        } else {
            playerBullet->move(0, -NORMALISED_BULLET_SPEED);
            playerBullet->visualize();
        }
    }
}

void Game::enemyShipHandler() {
    for (std::vector<Abs::EnemyShip*> column : enemies) {
        for (Abs::EnemyShip* enemyShip : column) {
            if (enemyShip->isAlive())
                enemyShip->visualize();
        }
    }

    if (cooldownCounter == NORMALIZED_ENEMY_COOLDOWN) {
        cooldownCounter = 0;
        int shootingColumn = rand() % 11;
        for (auto it = enemies[shootingColumn].rbegin(); it != enemies[shootingColumn].rend(); ++it) {
            Abs::EnemyShip* ship = *it;
            if (ship->isAlive()) {
                enemyBullets.push_back(
                        gameFactory->createEnemyBullet(ship->getXPos(), ship->getYPos(), BULLET_WIDTH, BULLET_HEIGHT));
                std::cout << enemyBullets.size() << "\n";
                break;
            }
        }
    } else {
        cooldownCounter++;
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



