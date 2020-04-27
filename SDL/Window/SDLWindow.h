#ifndef SPACEINVADERS_SDLWINDOW_H
#define SPACEINVADERS_SDLWINDOW_H

#include "LTexture.h"
#include "../../GameConstants.h"
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <map>

namespace Sdl {
    /**
     * The class that will do most of the SDL visualization
     */
    class SDLWindow {
    public:
        static SDLWindow* getInstance();

        static void destroyInstance();

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
        SDLWindow();

        ~SDLWindow();

        static SDLWindow* instance;     //The Window instance

        SDL_Window* window;             //The window we'll render to
        SDL_Renderer* renderer;         //The use of a renderer means we can use the GPU for our display
        SDL_Texture* background;        //The background

        TTF_Font* font;                 //Used font

        LTexture spriteSheetTexture;    //The spritesheet
        LTexture score;                 //Display for score
        LTexture lives;                 //Display for lives
        LTexture endScore;              //Display for score at the end of the game

        std::map<ENTITY, SDL_Rect> spriteMap;   //All sprites from the spritesheet
        std::map<SOUND, Mix_Chunk*> soundMap;   //All sounds
    };
}

#endif