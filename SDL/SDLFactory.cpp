#include "SDLFactory.h"

/**
 * The constructor of the SDLFactory
 * This will initialize the SDL window
 */
Sdl::SDLFactory::SDLFactory() {
    window = SDLWindow::getInstance();
    window->init();
    if (window->loadMedia())
        std::cout << "Successfully loaded media\n";
}

/**
 * The destructor of the SDLFactory
 */
Sdl::SDLFactory::~SDLFactory() {
    Sdl::SDLWindow::destroyInstance();
    window = nullptr;
}

/**
 * Creates a new player
 *
 * @param x start x position
 * @param y start y position
 * @param w width
 * @param h height
 * @return A pointer to an SDLPlayership
 */
Abs::PlayerShip* Sdl::SDLFactory::createPlayerShip(double x, double y, double w, double h) {
    return new Sdl::SDLPlayerShip(window, x, y, w, h);
}

/**
 * Creates a new enemy
 *
 * @param x start x position
 * @param y start y position
 * @param w width
 * @param h height
 * @param e type of enemy
 * @return A pointer to an SDLEnemyShip
 */
Abs::EnemyShip* Sdl::SDLFactory::createEnemyShip(double x, double y, double w, double h, ENTITY e) {
    return new Sdl::SDLEnemyShip(window, x, y, w, h, e);
}

/**
 * Creates a controller, which will check player input
 *
 * @return A pointer to an SDLController
 */
Abs::Controller* Sdl::SDLFactory::createController() {
    return new Sdl::SDLController();
}

/**
 * Creates a new playerbullet
 *
 * @param x start x position
 * @param y start y position
 * @param w width
 * @param h height
 * @return A pointer to an SDLPlayerBullet
 */
Abs::PlayerBullet* Sdl::SDLFactory::createPlayerBullet(double x, double y, double w, double h) {
    window->playSound(SHOOT);
    return new Sdl::SDLPlayerBullet(window, x, y, w, h);
}

/**
 * Creates a new enemybullet
 *
 * @param x start x position
 * @param y start y position
 * @param w width
 * @param h height
 * @return A pointer to an SDLEnemyBullet
 */
Abs::EnemyBullet* Sdl::SDLFactory::createEnemyBullet(double x, double y, double w, double h) {
    return new Sdl::SDLEnemyBullet(window, x, y, w, h);
}

/**
 * Creates a new posbonus
 *
 * @param x start x position
 * @param y start y position
 * @param w width
 * @param h height
 * @return A pointer to an SDLPosBonus
 */
Abs::PosBonus* Sdl::SDLFactory::createPosBonus(double x, double y, double w, double h) {
    window->playSound(BONUS_SPAWN);
    return new Sdl::SDLPosBonus(window, x, y, w, h);
}

/**
 * Creates a new negbonus
 *
 * @param x start x position
 * @param y start y position
 * @param w width
 * @param h height
 * @return A pointer to an SDLNegBonus
 */
Abs::NegBonus* Sdl::SDLFactory::createNegBonus(double x, double y, double w, double h) {
    window->playSound(BONUS_SPAWN);
    return new Sdl::SDLNegBonus(window, x, y, w, h);
}

/**
 * Draw everything on the screen
 *
 * @param score The score
 * @param lives Remaining lives
 * @param isEndScreen Can the score be shown in the middle of the screen? Is the game over?
 */
void Sdl::SDLFactory::draw(int score, int lives, bool isEndScreen) {
    if (!isEndScreen) {
        window->printScore(score);
        window->printLives(lives);
    } else {
        window->printScoreEnd(score);
    }
    window->draw();
}

/**
 * Set up each frame
 */
void Sdl::SDLFactory::setupFrame() {
    window->setup();
}

/**
 * Play a sound
 *
 * @param s The sound to be played (form SOUND)
 */
void Sdl::SDLFactory::playSound(SOUND s) {
    window->playSound(s);
}
