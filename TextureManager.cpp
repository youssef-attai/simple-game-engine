#include "TextureManager.h"

SDL_Texture *TextureManager::loadTexture(const char *filename) {
//    Load the image
    SDL_Surface *image = IMG_Load(filename);
    
//    Create the texture from the image to the game renderer
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::renderer, image);
    
//    Delete the image after finish
    SDL_FreeSurface(image);
    
    return texture;
}

void TextureManager::drawTexture(SDL_Texture *_texture, SDL_Rect destRect) {
    SDL_RenderCopy(Game::renderer, _texture, nullptr, &destRect);
}
