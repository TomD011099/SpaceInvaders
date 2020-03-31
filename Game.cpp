#include "Game.h"

Game* Game::instance = nullptr;

Game::Game(Abs::Factory* absFactory) {
    gameFactory = absFactory;
    lives = LIVES;
    score = 0;
    quit = false;

    playerShip = nullptr;
    playerBullet = nullptr;
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
 *
 */
void Game::run() {
    controller = gameFactory->createController();
    playerShip = gameFactory->createPlayerShip();

    Abs::EnemyShip* enemyShip = gameFactory->createEnemyShip();
    gameEntities.push_front(enemyShip);

    while (!quit) {
        gameFactory->setupFrame();

        playerShipHandler(&quit);

        playerBulletHandler();

        gameFactory->draw();
    }
}

void Game::playerShipHandler(bool *quit) {
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
                if (playerBullet == nullptr)
                    playerBullet = gameFactory->createPlayerBullet(playerShip->getXPos(), playerShip->getYPos());
                break;
            case CTRL_QUIT:
                *quit = true;
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
            delete(playerBullet);
        } else {
            playerBullet->move(0, -NORMALISED_BULLET_SPEED);
        }

        playerBullet->visualize();
    }
}


