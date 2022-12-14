#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(
        const char *_textureFilename,
        int _x,
        int _y,
        int _width,
        int _height
) : texture{TextureManager::loadTexture(_textureFilename)},
    xPos{_x},
    yPos{_y},
    destRect{xPos, yPos, _width, _height} {}

GameObject::~GameObject() = default;

void GameObject::update() {
    xPos++;
    yPos++;
}

void GameObject::render() {
    destRect.x = xPos;
    destRect.y = yPos;

    TextureManager::drawTexture(texture, destRect);
}

void GameObject::destroy() {
    SDL_DestroyTexture(texture);
}
