#ifndef SPACEINVADERS_SDLWINDOW_H
#define SPACEINVADERS_SDLWINDOW_H

#include "LTexture.h"
#include "../../GameConstants.h"

namespace Sdl {
    class SDLWindow {
    public:
        SDLWindow();

        ~SDLWindow();

        bool init();

        bool loadMedia();

        void close();

        void render(float, float, float, float, ENTITY);

        void draw();

        void setup();

    private:
        SDL_Window* window;         //The window we'll render to
        SDL_Renderer* renderer;     //The use of a renderer means we can use the GPU for our display
        SDL_Texture* background;
        SDL_Rect playerSprite;
        SDL_Rect enemySprites[5];
        SDL_Rect bulletSprite;
        SDL_Rect wreckSprite;
        //TODO add other sprites
        LTexture* spriteSheetTexture;
        int countedFrames;
    };
}

#endif