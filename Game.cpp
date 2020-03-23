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
    gameEntities.push_front(playerShip);

    Abs::EnemyShip* enemyShip = gameFactory->createEnemyShip();
    gameEntities.push_front(enemyShip);

    EVENT event = CTRL_IDLE;

    while(event != CTRL_QUIT) {
        event = controller->pollEvents();

        gameFactory->setupFrame();

        for (Abs::Entity* entity: gameEntities) {
            entity->update(event);
        }

        gameFactory->draw();
    }
}
