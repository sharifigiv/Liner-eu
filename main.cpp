#include <iostream>
#include <SDL2/SDL.h>

#include "transform.cpp"

using namespace std;

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;

#define FPS_INTERVAL 1.0 //seconds.

Uint32 fps_lasttime = SDL_GetTicks(); //the last recorded time.
Uint32 fps_current; //the current FPS.
Uint32 fps_frames = 0; //frames passed since the last recorded fps.


int main(int argc, char* args[]){
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    int i;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_WIDTH, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 10, 120, 255);
    for (i = 0; i < SCREEN_WIDTH; ++i)
        SDL_RenderDrawPoint(renderer, i, i);

    SDL_RenderPresent(renderer);

    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;

        fps_frames++;
        if (fps_lasttime < SDL_GetTicks() - FPS_INTERVAL*1000)
        {
            fps_lasttime = SDL_GetTicks();
            fps_current = fps_frames;
            fps_frames = 0;
        }

        cout << fps_current << endl;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}