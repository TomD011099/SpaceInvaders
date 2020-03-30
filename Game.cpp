#include "Game.h"

Game::Game(Abs::Factory* absFactory) {
    gameFactory = absFactory;
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
    Abs::Controller* controller = gameFactory->createController();
    Abs::PlayerShip* playerShip = gameFactory->createPlayerShip();

    Abs::EnemyShip* enemyShip = gameFactory->createEnemyShip();
    gameEntities.push_front(enemyShip);

    EVENT event = CTRL_IDLE;

    while (event != CTRL_QUIT) {
        event = controller->pollEvents();

        gameFactory->setupFrame();

        playerShip->update(event);

        if (event == CTRL_SHOOT) {
            Abs::PlayerBullet* playerBullet = gameFactory->createPlayerBullet(playerShip->getXPos(), playerShip->getYPos());
            gameEntities.push_front(playerBullet);
        }

        std::list<Abs::Entity*>::iterator it = gameEntities.begin();
        while (it != gameEntities.end()) {
            Abs::Entity* e = *it;
            bool res = e->update(event);
            if (!res) {
                gameEntities.erase(it++);
            } else {
                ++it;
            }
        }

        gameFactory->draw();
    }
}
