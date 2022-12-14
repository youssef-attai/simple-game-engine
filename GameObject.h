#pragma once

#include "Game.h"

class GameObject {
public:
    GameObject(const char *_textureFilename, int _x, int _y, int _width, int _height);

    ~GameObject();

    void update();

    void render();

    void destroy();

private:
    int xPos, yPos;
    SDL_Texture *texture;
    SDL_Rect destRect;
};
