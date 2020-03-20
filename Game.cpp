#include "Game.h"

Game::Game(Abs::Factory* absFactory) {
    gameFactory = absFactory;
}

void Game::run() {
    Abs::Controller* controller = gameFactory->createController();
    Abs::PlayerShip* playerShip = gameFactory->createPlayerShip();
    gameEntities.push_front(playerShip);

    Abs::EnemyShip* enemyShip = gameFactory->createEnemyShip();
    gameEntities.push_front(enemyShip);

    while(controller->pollEvents() != CTRL_QUIT) {
        int event = controller->pollEvents();

        for (auto entity: gameEntities) {
            entity->update(event);
            entity->visualize();
        }

        gameFactory->draw();
    }
}
