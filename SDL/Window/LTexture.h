#ifndef SPACEINVADERS_LTEXTURE_H
#define SPACEINVADERS_LTEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>

namespace Sdl {
    /**
     * This class is used for spritesheetrendering and text rendering
     *
     * Source: http://lazyfoo.net/tutorials/SDL/index.php
     */
    class LTexture {
    public:
        //Initializes variables
        LTexture();

        //Deallocates memory
        ~LTexture();

        //Loads image at specified path
        bool loadFromFile(std::string, SDL_Renderer*);

        //Creates image from font string
        bool loadFromRenderedText(std::string, SDL_Color, TTF_Font*, SDL_Renderer*);

        //Deallocates texture
        void free();

        //Renders texture at given point
        void render(int, int, int, int, SDL_Rect*, SDL_Renderer*);

    private:
        SDL_Texture* mTexture;      //The actual hardware texture
        int mWidth;                 //Image width
        int mHeight;                //Image height
    };
}

#endif