#ifndef SPACEINVADERS_LTEXTURE_H
#define SPACEINVADERS_LTEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

namespace Sdl {
    class LTexture {
    public:
        //Initializes variables
        LTexture(SDL_Renderer*);

        //Deallocates memory
        ~LTexture();

        //Loads image at specified path
        bool loadFromFile( std::string path );

        //Deallocates texture
        void free();

        //Renders texture at given point
        void render(int, int, int, int, SDL_Rect*);

        //Gets image dimensions
        int getWidth();
        int getHeight();

    private:
        SDL_Renderer* renderer;
        SDL_Texture* mTexture;      //The actual hardware texture
        int mWidth;                 //Image width
        int mHeight;                //Image height
    };
}

#endif