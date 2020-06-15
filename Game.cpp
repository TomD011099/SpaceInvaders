#include "Game.h"

/**
 * Instance is set to nullptr at the start of the program
 */
Game* Game::instance = nullptr;

/**
 * The constructor of Game, it is private because of Game being a Singleton
 *
 * @param absFactory An implementation of an abstract factory, this will define the engine
 */
Game::Game(Abs::Factory* absFactory) {
    gameFactory = absFactory;
    lives = MAX_LIVES;
    score = 0;
    isQuit = false;
    isGameOver = false;
    showEndScore = false;
    hasSoundPlayed = false;
    isEnemyMovingLeft = true;
    enemyMoveCooldownCounter = 0;
    enemyShootCooldownCounter = 0;
    bonusSpawnCooldownCounter = 0;
    isEnemyMovingHorizontal = true;

    playerShip = nullptr;
    playerBullet = nullptr;
    controller = nullptr;
    bonusEntity = nullptr;

    //Srand is technically not truly random, but good enough for this game
    srand(time(nullptr));
}

/**
 * Destructor of game
 */
Game::~Game() {
    delete playerShip;
    delete playerBullet;
    delete controller;
    delete bonusEntity;

    //Will loop over the vector<vector<Enemyship>> to delete them all
    for (int i = 0; i < enemies.size(); i++) {
        for (int j = 0; j < enemies[i].size(); j++) {
            Abs::EnemyShip* enemyShip = enemies[i].at(j);
            delete enemyShip;
            enemies[i].erase(enemies[i].begin() + (j--));
        }
    }

    //Will loop over the vector<Enemybullet> to delete them all
    for (int i = 0; i < enemyBullets.size(); i++) {
        Abs::EnemyBullet* enemyBullet = enemyBullets.at(i);
        delete enemyBullet;
        enemyBullets.erase(enemyBullets.begin() + (i--));
    }
}

/**
 * The way of getting the game object
 *
 * @param absFactory An implementation of an abstract factory, this will define the engine
 * @return A new game instance or the current game instance
 */
Game* Game::getInstance(Abs::Factory* absFactory) {
    if (instance == nullptr) {
        instance = new Game(absFactory);
    }
    return instance;
}

/**
 * Destructor for singleton
 * Will ensure no infinite loop is reached
 */
void Game::destroyInstance() {
    delete instance;
    instance = nullptr;
}

/**
 * Run the game
 *  The game runs in three major parts: setup, main, loop, end
 *  - setup: Entities are spawned and a controller is generated
 *  - main: A timed loop which handles all of the game logic
 *  - end: end screen and cleanup
 */
void Game::run() {
    setup();

    //Main game loop
    while (!isQuit) {
        //Start one frame
        std::chrono::time_point start = std::chrono::system_clock::now();

        gameFactory->setupFrame();

        isQuit = controller->isQuit();

        //Checks for end of game
        if (lives <= 0 || isGameOver) {
            if (!hasSoundPlayed) {
                if (lives <= 0) {
                    playerShip->killed();
                }
                gameFactory->playSound(LOSS);
                hasSoundPlayed = true;
                showEndScore = true;
            }
            playerShip->visualize();
            drawEnemyShip();
        } else if (enemies.empty()) {
            if (!hasSoundPlayed) {
                gameFactory->playSound(VICTORY);
                score += lives * 500;
                hasSoundPlayed = true;
                showEndScore = true;
            }
            playerShip->visualize();
        } else {

            playerShipHandler();

            playerBulletHandler();

            enemyShipHandler();

            enemyBulletHandler();

            bonusEntityHandler();
        }

        //Show the frame
        gameFactory->draw(score, lives, showEndScore);

        //Hold until frametime is reached
        std::this_thread::sleep_until(start + SCREEN_TIME);
    }
}

/**
 * Entities are spawned and a controller is generated
 */
void Game::setup() {
    controller = gameFactory->createController();
    playerShip = gameFactory->createPlayerShip(0.5, 0.9, PLAYERSHIP_WIDTH, PLAYERSHIP_HEIGHT);
    generateEnemies();
}

/**
 * The grid of enemies is generated
 * Each row has a different enemy, worth an increasing amount of points
 */
void Game::generateEnemies() {
    //Start value for x = left border
    double x = ENEMYSHIP_WIDHT / 2, y;
    ENTITY e = ENEMYSHIP0;

    for (int i = 0; i < 11; i++) {
        std::vector<Abs::EnemyShip*> column;
        //Start value for y
        y = 0.1;

        for (int j = 0; j < 5; j++) {
            //Vertical distance between the enemies
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
            //A new enemy is created with the calculated x and y values and of a specific type
            column.push_back(gameFactory->createEnemyShip(x, y, ENEMYSHIP_WIDHT, ENEMYSHIP_HEIGHT, e));
        }
        enemies.push_back(column);
        //Horizontal distance between the enemies
        x += (ENEMYSHIP_WIDHT + 0.015);
    }
}

/**
 * Handles the playerships movement and shooting
 */
void Game::playerShipHandler() {
    events = controller->pollEvents();

    for (EVENT event : events) {
        switch (event) {
            case CTRL_LEFT:
                //Move left
                playerShip->move(-NORMALISED_SPEED, 0);
                break;
            case CTRL_RIGHT:
                //Move right
                playerShip->move(NORMALISED_SPEED, 0);
                break;
            case CTRL_SHOOT:
                //The bullet is created at the position of the player
                if (playerBullet == nullptr) {
                    playerBullet = gameFactory->createPlayerBullet(playerShip->getXPos(), playerShip->getYPos(),
                                                                   BULLET_WIDTH, BULLET_HEIGHT);
                }
                break;
            default:
                break;
        }
    }
    playerShip->visualize();
}

/**
 * Moves the playerbullet, checks if it goes out of bounds and does collision detection with all enemies
 * There can be only one bullet at the same time
 */
void Game::playerBulletHandler() {
    //Does the playerbullet exist?
    if (playerBullet != nullptr) {  //If playerbullet is already on the screen

        //Movement
        if (playerBullet->getYPos() < -playerBullet->getHeight() / 2) {  //If the bullet has passed the edge
            //Delete the bullet -> good for memory & a new bullet can be fired next frame
            delete playerBullet;
            playerBullet = nullptr;
            return;
        } else {                            //If the bullet hasn't passed the edge yet
            //Move the bullet
            playerBullet->move(0, -NORMALISED_BULLET_SPEED);
        }

        //Collision detection
        bool hit = false;
        //Detection with enemies
        for (int i = 0; (i < enemies.size() && !hit); i++) {
            for (int j = 0; (j < enemies[i].size() && !hit); j++) {
                Abs::EnemyShip* enemyShip = enemies[i].at(j);
                if (isCollision(playerBullet, enemyShip) && enemyShip->isAlive()) { //If there is collision
                    //Add the score
                    score += scores.at(enemyShip->getType());
                    //Let the enemy know it's hit -> sound + visual response
                    enemyShip->hit();
                    //Delete the bullet so a new one can be shot
                    delete playerBullet;
                    playerBullet = nullptr;
                    hit = true;
                }
            }
        }
        //Detection with bonusEntities
        if (bonusEntity != nullptr && !hit) {   //If the bonusEntity is on the screen and there wasn't a hit yet
            if (isCollision(playerBullet, bonusEntity)) {   //If there is collision
                //Add the score
                score += scores.at(bonusEntity->getEntity());
                //Delete the bullet so a new one can be shot
                delete playerBullet;
                playerBullet = nullptr;
                //Delete the bonusEntity so a new one can spawn
                delete bonusEntity;
                bonusEntity = nullptr;
                hit = true;
            }
        }
        if (!hit)   //If there is no collision
            //Render the bullet
            playerBullet->visualize();
    }
}

/**
 * Draws the enemyships to the screen
 */
void Game::drawEnemyShip() {
    for (const std::vector<Abs::EnemyShip*> &column : enemies) {
        for (Abs::EnemyShip* enemyShip : column) {
            //Both ships and explosions will be shown
            if (enemyShip->isAlive() || !enemyShip->isGone())
                enemyShip->visualize();
        }
    }
}

/**
 * Handles the enemyship movements and decides when they can shoot
 */
void Game::enemyShipHandler() {
    //Loop over enemies to delete them or tick them
    for (int i = 0; i < enemies.size(); i++) {
        //If false at the end of the column loop -> delete column
        bool isColumnAlive = false;
        for (int j = 0; j < enemies[i].size(); j++) {
            Abs::EnemyShip* enemyShip = enemies[i].at(j);
            if (enemyShip->isAlive()) {
                isColumnAlive = true;
            } else {
                //Used for timing how long the explosion is shown
                enemyShip->tick();
                if (enemyShip->isGone()) {  //If enemy is dead & explosion has finished
                    //Delete the enemy
                    delete enemyShip;
                    enemies[i].erase(enemies[i].begin() + (j--));
                } else {
                    isColumnAlive = true;
                }
            }
        }

        if (!isColumnAlive) {
            //Delete the column because it's not useful
            enemies.erase(enemies.begin() + (i--));
        }
    }

    //Movement
    //On a cooldown
    if (enemyMoveCooldownCounter >= NORMALIZED_ENEMY_MOVEMENT_DELAY) {  //If time to move
        //Reset counter
        enemyMoveCooldownCounter = 0;

        //Find left- and rightmost aliens
        double minX = enemies[0][0]->getXPos();
        double maxX = enemies[enemies.size() - 1][0]->getXPos();
        double movement = 0;

        //Calculate movement
        if (isEnemyMovingLeft) { //If moving left
            //If moving left won't keep the aliens on the screen
            if (minX - ENEMY_SPEED <= ENEMYSHIP_WIDHT / 2 && isEnemyMovingHorizontal) {
                //Move down
                isEnemyMovingHorizontal = false;
                //After that move right
                isEnemyMovingLeft = false;
            } else {
                //The aliens will move to the left
                movement = -ENEMY_SPEED;
            }
        } else {    //If moving right or vertically
            //If moving right won't keep the aliens on the screen
            if (maxX + ENEMY_SPEED >= (1 - ENEMYSHIP_WIDHT / 2) && isEnemyMovingHorizontal) {
                //Move down
                isEnemyMovingHorizontal = false;
                //After that move left
                isEnemyMovingLeft = true;
            } else {
                //The aliens will move to the right
                movement = ENEMY_SPEED;
            }
        }

        double lowestY = 0;

        //Actual movement
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

                //Test for collision between enemies and player
                if (isCollision(enemyShip, playerShip)) {
                    //Player dies
                    lives = 0;
                }
            }
        }

        //See if the aliens have crossed the lower bound
        if (lowestY >= ENEMY_LOWER_BOUND) {
            //Game over
            isGameOver = true;
        }

        //The enemies will always only move vertically once, so this resets the value
        isEnemyMovingHorizontal = true;

    } else {    //If not time to move, add to counter
        enemyMoveCooldownCounter++;
    }

    //Draw the enemies
    drawEnemyShip();

    //Shooting logic
    if (enemyShootCooldownCounter >= NORMALIZED_ENEMY_COOLDOWN) { //If time to shoot
        //Reset counter
        enemyShootCooldownCounter = 0;
        //Choose random column
        int shootingColumn = rand() % enemies.size();
        //Reverse iterator to find the lowest enemy still alive
        for (auto it = enemies[shootingColumn].rbegin(); it != enemies[shootingColumn].rend(); ++it) {
            Abs::EnemyShip* ship = *it;
            if (ship->isAlive()) {
                //Create a bullet at the enemies location
                enemyBullets.push_back(
                        gameFactory->createEnemyBullet(ship->getXPos(), ship->getYPos(), BULLET_WIDTH, BULLET_HEIGHT));
                break;
            }
        }
    } else {
        //Increase the counter
        enemyShootCooldownCounter++;
    }
}

/**
 * Moves the enemybullets, checks if they go out of bounds and detects collision with the player
 */
void Game::enemyBulletHandler() {
    //Iterate over all the bullets
    for (int i = 0; i < enemyBullets.size(); i++) {
        Abs::EnemyBullet* bullet = enemyBullets.at(i);
        //Test if they've gone too far
        if (bullet->getYPos() > 1 + (bullet->getHeight() / 2)) {
            //Remove them if they've gone too far
            delete bullet;
            enemyBullets.erase(enemyBullets.begin() + (i--));
        } else {
            //Move the bullet
            bullet->move(0, NORMALISED_BULLET_SPEED);

            //Test collision with playership
            if (isCollision(bullet, playerShip)) {  //If hit
                //Life lost
                lives--;
                //Sound
                gameFactory->playSound(HIT);
                //Remove bullet
                delete bullet;
                enemyBullets.erase(enemyBullets.begin() + (i--));
            } else { //If no hit
                //Show the bullet
                bullet->visualize();
            }
        }
    }
}

/**
 * Moves the bonusEntity. If there isn't one, there is a chance one spawns
 */
void Game::bonusEntityHandler() {
    //Test if the bonusentity already exists on the screen
    if (bonusEntity != nullptr) {   //If the bonusentity already exists
        if ((bonusEntity->getXPos()) >=
            (1 + (bonusEntity->getWidth() / 2.0))) { //If the bonusentity will move out of bounds
            //Remove bonusentity so a new one can spawn
            delete bonusEntity;
            bonusEntity = nullptr;
            return;
        } else {    //If the bonusentity will stay between the bounds
            //Move the bonusentity
            bonusEntity->move(BONUS_SPEED, 0);
            bonusEntity->visualize();
        }
    } else {    //If the bonusentity doesn't exist yet
        if (bonusSpawnCooldownCounter >= NORMALISED_BONUS_SPAWN_COOLDOWN) { //A delay between spawn attempts
            //Reset counter
            bonusSpawnCooldownCounter = 0;
            if (rand() % 100 <= BONUS_SPAWN_RATE) { //A chance to spawn a bonusentity
                if (rand() % 100 <= 50) { //50/50 chance
                    //Spawn posbonus
                    bonusEntity = gameFactory->createBonusEntity(POSBONUS, -BONUS_WIDTH / 2, 0.09, BONUS_WIDTH,
                                                                 BONUS_HEIGHT);
                } else {
                    //Spawn negbonus
                    bonusEntity = gameFactory->createBonusEntity(NEGBONUS, -BONUS_WIDTH / 2, 0.09, BONUS_WIDTH,
                                                                 BONUS_HEIGHT);
                }
                bonusEntity->visualize();
            }
        } else {
            //Increase the counter
            bonusSpawnCooldownCounter++;
        }
    }
}

/**
 * Checks if two entities collide
 *
 * @param e1 The first entity
 * @param e2 The second entity
 * @return True if there is collision, false if not
 */
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