#include "LTexture.h"

/**
 * Constructor of LTexture
 */
Sdl::LTexture::LTexture() {
    //Initialize
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
}

/**
 * Destructor of LTexture
 */
Sdl::LTexture::~LTexture() {
    //Deallocate
    free();
}

/**
 * Load ab LTexture from a file
 *
 * @param path The path of the file
 * @param renderer  The renderer
 * @return boolean for success
 */
bool Sdl::LTexture::loadFromFile(std::string path, SDL_Renderer* renderer) {
    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = nullptr;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    } else {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == nullptr) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        } else {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
    mTexture = newTexture;
    return mTexture != nullptr;
}

/**
 * Load an LTexture from a string
 *
 * @param textureText The text to be displayed
 * @param textColor The color of the text
 * @param font The font the text has to be rendered in
 * @param renderer The renderer
 * @return boolean for success
 */
bool Sdl::LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor, TTF_Font* font,
                                         SDL_Renderer* renderer) {
    //Get rid of preexisting texture
    free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
    if (textSurface == nullptr) {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    } else {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (mTexture == nullptr) {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        } else {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface(textSurface);
    }

    //Return success
    return mTexture != nullptr;
}

/**
 * Deallocates the texture
 */
void Sdl::LTexture::free() {
    //Free texture if it exists
    if (mTexture != nullptr) {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
    }
}

/**
 * Render the texture to the window
 *
 * @param x x position
 * @param y y position
 * @param w Width
 * @param h Height
 * @param clip The sprite to be rendered
 * @param renderer The renderer
 */
void Sdl::LTexture::render(int x, int y, int w, int h, SDL_Rect* clip, SDL_Renderer* renderer) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = {x, y, w, h};

    //Render to screen
    SDL_RenderCopy(renderer, mTexture, clip, &renderQuad);
}