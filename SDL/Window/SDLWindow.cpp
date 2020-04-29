#include "SDLWindow.h"

/**
 * Initialization of instance
 */
Sdl::SDLWindow* Sdl::SDLWindow::instance = nullptr;

/**
 * Get the instance
 *
 * @return the window instance
 */
Sdl::SDLWindow* Sdl::SDLWindow::getInstance() {
    if (instance == nullptr) {
        instance = new SDLWindow();
    }
    return instance;
}

/**
 * Destructor for singelton
 */
void Sdl::SDLWindow::destroyInstance() {
    delete instance;
    instance = nullptr;
}

/**
 * Constructor for SDLWindow
 */
Sdl::SDLWindow::SDLWindow() {
    window = nullptr;
    renderer = nullptr;
    font = nullptr;
}

/**
 * Destructor for SDLWindow
 */
Sdl::SDLWindow::~SDLWindow() {
    //Destroy fonts
    TTF_CloseFont(font);
    font = nullptr;

    //Destroy sounds
    std::map<SOUND, Mix_Chunk*>::iterator it;
    for (it = soundMap.begin(); it != soundMap.end(); it++) {
        Mix_FreeChunk(it->second);
        it->second = nullptr;
    }

    //Destroy Ltextures
    spriteSheetTexture.free();
    lives.free();
    score.free();
    endScore.free();

    //Destroy renderer
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    //Destroy window
    SDL_DestroyWindow(window);
    window = nullptr;

    //Quit SDL subsystems
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

/**
 * Initialise the SDLWindow
 *
 * @return boolean if everything went successfully
 */
bool Sdl::SDLWindow::init() {
    //Initialization flag
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
        success = false;
    } //Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        std::cout << "Warning: Linear texture filtering not enabled!";
        success = false;
    }

    //Create window
    window = SDL_CreateWindow("SpaceInvaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
        success = false;
    } else {
        //Create renderer for window
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr) {
            std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
            success = false;
        } else {
            //Initialize renderer color
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags)) {
                std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << "\n";
                success = false;
            }

            //Initialize SDL_ttf
            if (TTF_Init() == -1) {
                printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                success = false;
            }

            //Initialize SDL_mixer
            if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
                printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
                success = false;
            }
        }
    }

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    return success;
}

/**
 * Load all images, fonts and sounds
 *
 * @return boolean if everything went successfully
 */
bool Sdl::SDLWindow::loadMedia() {
    //Loading success flag
    bool success = true;

    //Load sprite sheet texture
    if (!spriteSheetTexture.loadFromFile("../Media/spritesheet.png", renderer)) {
        std::cout << "Failed to load sprite sheet texture!\n";
        success = false;
    } else {
        //Create sprites

        spriteMap[PLAYERSHIP].x = 150;
        spriteMap[PLAYERSHIP].y = 638;
        spriteMap[PLAYERSHIP].w = 73;
        spriteMap[PLAYERSHIP].h = 52;

        spriteMap[ENEMYSHIP0].x = 19;
        spriteMap[ENEMYSHIP0].y = 14;
        spriteMap[ENEMYSHIP0].w = 110;
        spriteMap[ENEMYSHIP0].h = 80;

        spriteMap[ENEMYSHIP1].x = 165;
        spriteMap[ENEMYSHIP1].y = 14;
        spriteMap[ENEMYSHIP1].w = 110;
        spriteMap[ENEMYSHIP1].h = 80;

        spriteMap[ENEMYSHIP2].x = 312;
        spriteMap[ENEMYSHIP2].y = 14;
        spriteMap[ENEMYSHIP2].w = 80;
        spriteMap[ENEMYSHIP2].h = 80;

        spriteMap[ENEMYSHIP3].x = 145;
        spriteMap[ENEMYSHIP3].y = 374;
        spriteMap[ENEMYSHIP3].w = 100;
        spriteMap[ENEMYSHIP3].h = 80;

        spriteMap[ENEMYSHIP4].x = 377;
        spriteMap[ENEMYSHIP4].y = 374;
        spriteMap[ENEMYSHIP4].w = 80;
        spriteMap[ENEMYSHIP4].h = 80;

        spriteMap[PLAYERBULLET].x = 533;
        spriteMap[PLAYERBULLET].y = 394;
        spriteMap[PLAYERBULLET].w = 9;
        spriteMap[PLAYERBULLET].h = 51;

        spriteMap[ENEMYBULLET].x = 533;
        spriteMap[ENEMYBULLET].y = 394;
        spriteMap[ENEMYBULLET].w = 9;
        spriteMap[ENEMYBULLET].h = 51;

        spriteMap[ENEMY_WRECK].x = 359;
        spriteMap[ENEMY_WRECK].y = 632;
        spriteMap[ENEMY_WRECK].w = 96;
        spriteMap[ENEMY_WRECK].h = 58;

        spriteMap[POSBONUS].x = 20;
        spriteMap[POSBONUS].y = 635;
        spriteMap[POSBONUS].w = 123;
        spriteMap[POSBONUS].h = 57;

        spriteMap[NEGBONUS].x = 364;
        spriteMap[NEGBONUS].y = 509;
        spriteMap[NEGBONUS].w = 123;
        spriteMap[NEGBONUS].h = 57;

        spriteMap[PLAYER_WRECK].x = 241;
        spriteMap[PLAYER_WRECK].y = 634;
        spriteMap[PLAYER_WRECK].w = 91;
        spriteMap[PLAYER_WRECK].h = 60;
    }

    //Load background
    SDL_Surface* loadedSurface = IMG_Load("../Media/background.jpeg");
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", "../Media/background.jpeg", IMG_GetError());
    } else {
        //Create texture from surface pixels
        background = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (background == nullptr) {
            printf("Unable to create texture from %s! SDL Error: %s\n", "../Media/background.jpeg", SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Open the font
    font = TTF_OpenFont("../Media/font.ttf", 128);
    if (font == nullptr) {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    } else {
        //Render text
        SDL_Color textColor = {255, 255, 255};
        if (!score.loadFromRenderedText("Score ", textColor, font, renderer)) {
            printf("Failed to render text texture!\n");
            success = false;
        }
    }

    //Load the invader killed sound
    soundMap[INVADER_KILLED] = Mix_LoadWAV("../Media/invaderkilled.wav");
    if (soundMap[INVADER_KILLED] == nullptr) {
        printf("Failed to load invaderkilled sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    //Load the shoot sound
    soundMap[SHOOT] = Mix_LoadWAV("../Media/shoot.wav");
    if (soundMap[SHOOT] == nullptr) {
        printf("Failed to load shoot sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    //Load the explosion sound
    soundMap[EXPLOSION] = Mix_LoadWAV("../Media/explosion.wav");
    if (soundMap[EXPLOSION] == nullptr) {
        printf("Failed to load explosion sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    //Load the hit sound
    soundMap[HIT] = Mix_LoadWAV("../Media/hit.wav");
    if (soundMap[HIT] == nullptr) {
        printf("Failed to load hit sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    //Load the loss sound
    soundMap[LOSS] = Mix_LoadWAV("../Media/loss.wav");
    if (soundMap[LOSS] == nullptr) {
        printf("Failed to load loss sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    //Load the victory sound
    soundMap[VICTORY] = Mix_LoadWAV("../Media/victory.wav");
    if (soundMap[VICTORY] == nullptr) {
        printf("Failed to load victory sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    //Load the spawn bonus sound
    soundMap[BONUS_SPAWN] = Mix_LoadWAV("../Media/bonusSpawn.wav");
    if (soundMap[BONUS_SPAWN] == nullptr) {
        printf("Failed to load bonusSpawn sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    return success;
}

/**
 * Show the score on the window
 *
 * @param points The amount of points to be displayed
 */
void Sdl::SDLWindow::printScore(int points) {
    //Render text
    SDL_Color textColor = {255, 255, 255};
    if (!score.loadFromRenderedText("Score " + std::to_string(points), textColor, font, renderer)) {
        printf("Failed to render text texture!\n");
    }

    //Change to SDL coordinates
    double scoreW = 0.1 * SCREEN_WIDTH;
    double scoreH = 0.02 * SCREEN_HEIGHT;
    double scoreX = (0.5 * SCREEN_WIDTH) - scoreW / 2;
    double scoreY = (0.02 * SCREEN_HEIGHT) - scoreH / 2;

    //Render the score
    score.render(static_cast<int>(scoreX), static_cast<int>(scoreY), static_cast<int>(scoreW), static_cast<int>(scoreH),
                 nullptr, renderer);
}

/**
 * Show the score on the window at the end of the game
 *
 * @param points The amount of points to be displayed
 */
void Sdl::SDLWindow::printScoreEnd(int points) {
    SDL_Color textColor = {133, 133, 133};
    if (!endScore.loadFromRenderedText("Score " + std::to_string(points), textColor, font, renderer)) {
        printf("Failed to render text texture!\n");
    }

    //Change to SDL coordinates
    double scoreW = 0.5 * SCREEN_WIDTH;
    double scoreH = 0.2 * SCREEN_HEIGHT;
    double scoreX = (0.5 * SCREEN_WIDTH) - scoreW / 2;
    double scoreY = (0.5 * SCREEN_HEIGHT) - scoreH / 2;

    //Render the score
    endScore.render(static_cast<int>(scoreX), static_cast<int>(scoreY), static_cast<int>(scoreW),
                    static_cast<int>(scoreH),
                    nullptr, renderer);
}

/**
 * Show the amount of lives the player has left
 *
 * @param lifeCount The amount of lives the player has left
 */
void Sdl::SDLWindow::printLives(int lifeCount) {
    //Render text
    SDL_Color textColor = {255, 255, 255};
    if (!this->lives.loadFromRenderedText(std::to_string(lifeCount), textColor, font, renderer)) {
        printf("Failed to render text texture!\n");
    }

    //Change to SDL coordinates
    double livesW = 0.03 * SCREEN_WIDTH;
    double livesH = 0.03 * SCREEN_HEIGHT;
    double livesX = (0.93 * SCREEN_WIDTH) - livesW / 2;
    double livesY = (0.03 * SCREEN_HEIGHT) - livesH / 2;

    //Render the lives
    lives.render(static_cast<int>(livesX), static_cast<int>(livesY), static_cast<int>(livesW), static_cast<int>(livesH),
                 nullptr, renderer);

    //Change to SDL coordinates
    double livesIconW = 0.03 * SCREEN_WIDTH;
    double livesIconH = 0.03 * SCREEN_HEIGHT;
    double livesIconX = (0.97 * SCREEN_WIDTH) - livesIconW / 2;
    double livesIconY = (0.03 * SCREEN_HEIGHT) - livesIconH / 2;

    //Render the playericon
    spriteSheetTexture.render(static_cast<int>(livesIconX), static_cast<int>(livesIconY), static_cast<int>(livesIconW),
                              static_cast<int>(livesIconH), &spriteMap[PLAYERSHIP], renderer);
}

/**
 * Play a specific sound
 *
 * @param s The sound that has to be played
 */
void Sdl::SDLWindow::playSound(SOUND s) {
    Mix_PlayChannel(-1, soundMap[s], 0);
}

/**
 * Render an SDL_Rect (sprite)
 *
 * @param x x position
 * @param y y position
 * @param w width
 * @param h height
 * @param type the entity to be rendered
 */
void Sdl::SDLWindow::render(double x, double y, double w, double h, ENTITY type) {
    double SDLx, SDLy, SDLw, SDLh;

    //Change to SDL coordinates
    SDLw = w * SCREEN_WIDTH;
    SDLh = h * SCREEN_HEIGHT;
    SDLx = (x * SCREEN_WIDTH) - SDLw / 2;
    SDLy = (y * SCREEN_HEIGHT) - SDLh / 2;

    //Render the sprite
    spriteSheetTexture.render(static_cast<int>(SDLx), static_cast<int>(SDLy), static_cast<int>(SDLw),
                              static_cast<int>(SDLh), &spriteMap[type], renderer);
}

/**
 * Update screen
 */
void Sdl::SDLWindow::draw() {
    SDL_RenderPresent(renderer);
}

/**
 * Clear the screen and render the background
 */
void Sdl::SDLWindow::setup() {
    //Clear renderer
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
}