#include "Game.h"

Game *game = nullptr;

int main(int argc, const char *argv[]) {
    game = new Game();
    game->init("My game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640);

//    Frames to render per second
    const int FPS = 60;

//    Time each frame should take before next frame is rendered
//    1000/FPS means each frame should take not a whole second rendering
//    but a part of the second so that the number of frames rendered per second is FPS
    const int frameDelay = 1000 / FPS;

    unsigned long frameStart;
    unsigned long frameTime;

    while (game->running()) {
        frameStart = SDL_GetTicks();

        game->handleEvent();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

//        If the frame took less time than it should
        if (frameTime < frameDelay)
//            Delay the frame till it has taken the time it should
            SDL_Delay(frameDelay - frameTime);
    }

    game->clean();

    return 0;
}
