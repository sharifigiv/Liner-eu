#include <iostream>
#include <SDL2/SDL.h>
#include "transform.cpp"

using namespace std;

int main() {
    const int windowHeight = 720;
    const int windowWidth = 1080;

    float zoomRatio = 1.0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return 1;
        cout << "Initialization failed" << endl;
    }

    SDL_Window *window = SDL_CreateWindow("Linear eu",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth,
            windowHeight, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        SDL_Quit();
        return 2;
    }

    SDL_Renderer *s = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) ;

    bool quit = false;
    SDL_Event event;

    Line L1 = Line();
    L1.m = 2; L1.b = 3;

    while (!quit) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_RenderClear(s);
        SDL_SetRenderDrawColor(s, 0xFF, 0xFF, 0xFF, 0xFF);

        for (int x = 0; x <= windowWidth; x++){
            SDL_RenderDrawPoint(s, x, windowHeight / 2);
        }

        for (int y = 0; y <= windowHeight; y++){
            SDL_RenderDrawPoint(s, windowWidth / 2, y);
        }

        for (int i = -windowWidth / 2; i <= windowWidth / 2; i++){
            SDL_RenderDrawPoint(s, float((windowWidth / 2) + i) * zoomRatio , float((windowHeight / 2) - L1.get_y(float(i))) * zoomRatio);

        }

        SDL_SetRenderDrawColor(s, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderPresent(s);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(s);
    SDL_Quit();
}