#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include <list>
#include "Abs/Factory.h"

class Game {
public:
    static Game* getInstance(Abs::Factory*);

    /**
     * Run the game
     */
    void run();

private:
    /**
     * Constructor of Game, takes a factory of your choosing (needs to inherit from Abs::Factory)
     */
    Game(Abs::Factory*);
    static Game* instance;

    Abs::Factory* gameFactory;                  //The factory that will create all specific items
    std::list<Abs::Entity*> gameEntities;        //A list of all entities in the game
    int lives, score;
    std::vector<EVENT> events;
    bool quit;

    Abs::PlayerShip* playerShip;
    Abs::Controller* controller;
    Abs::PlayerBullet* playerBullet;

    void playerShipHandler(bool*);

    void playerBulletHandler();
};


#endif