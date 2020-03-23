#include "SDLWindow.h"

Sdl::SDLWindow::SDLWindow() {
    window = nullptr;
    renderer = nullptr;
    spriteSheetTexture = nullptr;

    countedFrames = 0;
    fpsTimer = new LTimer;
    capTimer = new LTimer;

    fpsTimer->start();
}

Sdl::SDLWindow::~SDLWindow() {
    close();
}

bool Sdl::SDLWindow::init() {
    //Initialization flag
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
        success = false;
    } //Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        std::cout << "Warning: Linear texture filtering not enabled!";
        success = false;
    }

    //Create window
    window = SDL_CreateWindow("SpaceInvaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DEFAULT_SCREEN_WIDTH,
                              DEFAULT_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
        }
    }

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    return success;
}

bool Sdl::SDLWindow::loadMedia() {
    //Loading success flag
    bool success = true;
    spriteSheetTexture = new Sdl::LTexture(renderer);

    //Load sprite sheet texture
    if (!spriteSheetTexture->loadFromFile("../Media/spritesheet.png")) {
        std::cout << "Failed to load sprite sheet texture!\n";
        success = false;
    } else {
        //Set top left sprite
        playerSprite.x = 150;
        playerSprite.y = 638;
        playerSprite.w = 73;
        playerSprite.h = 52;

        //Set enemy sprite
        enemySprite.x = 19;
        enemySprite.y = 14;
        enemySprite.w = 110;
        enemySprite.h = 80;
    }

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

    return success;
}

void Sdl::SDLWindow::close() {
    //Destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

void Sdl::SDLWindow::render(float x, float y, float w, float h, ENTITY type) {
    float SDLx, SDLy, SDLw, SDLh;

    //TODO change static_cast<float>(playerSprite.w) to SDLw and make sure sprites are scaled to w and h

    switch (type) {
        case PLAYERSHIP:
            SDLx = x * (DEFAULT_SCREEN_WIDTH - static_cast<float>(playerSprite.w));
            SDLy = y * (DEFAULT_SCREEN_HEIGHT - static_cast<float>(playerSprite.h));
            spriteSheetTexture->render(static_cast<int>(SDLx), static_cast<int>(SDLy), &playerSprite);
            break;
        case ENEMYSHIP:
            SDLx = x * (DEFAULT_SCREEN_WIDTH - static_cast<float>(enemySprite.w));
            SDLy = y * (DEFAULT_SCREEN_HEIGHT - static_cast<float>(enemySprite.h));
            spriteSheetTexture->render(static_cast<int>(SDLx), static_cast<int>(SDLy), &enemySprite);
            break;
        default:
            break;
    }
}

void Sdl::SDLWindow::draw() {
    capTimer->start();

    //Calculate and correct fps
    float avgFPS = countedFrames / (fpsTimer->getTicks() / 1000.f);
    if (avgFPS > 2000000) {
        avgFPS = 0;
    }

    //Update screen
    SDL_RenderPresent(renderer);
    ++countedFrames;

    int frameTicks = capTimer->getTicks();
    if (frameTicks < SCREEN_TICK_PER_FRAME) {
        //Wait remaining time
        SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
    }

    //Clear renderer
    SDL_RenderClear(renderer);
}

void Sdl::SDLWindow::setup() {
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
}
