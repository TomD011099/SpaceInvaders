#ifndef SPACEINVADERS_SDLWINDOW_H
#define SPACEINVADERS_SDLWINDOW_H

#include "LTexture.h"
#include "../../GameConstants.h"
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <map>

namespace Sdl {
    class SDLWindow {
    public:
        SDLWindow();

        ~SDLWindow();

        bool init();

        bool loadMedia();

        void printScore(int);

        void printScoreEnd(int);

        void printLives(int);

        void playSound(SOUND);

        void render(double, double, double, double, ENTITY);

        void draw();

        void setup();

    private:
        SDL_Window* window;         //The window we'll render to
        SDL_Renderer* renderer;     //The use of a renderer means we can use the GPU for our display
        SDL_Texture* background;

        TTF_Font* font;

        LTexture spriteSheetTexture;
        LTexture score;
        LTexture lives;
        LTexture endScore;

        std::map<ENTITY, SDL_Rect> spriteMap;
        std::map<SOUND, Mix_Chunk*> soundMap;
    };
}

#endif