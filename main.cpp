#include <iostream>
#include <SDL2/SDL.h>
#include "transform.cpp"

using namespace std;

pair<Line, int> Lines[99]; 
Line2 Lines2[99][2]; 

int Line_i = 0;
int Line2_i = 0;

void newLine (int m, int b, int r, int g, int b1){
    Line l = Line();
    l.b = b; l.m = m;

    Line_i++;

    int color[3] = {r, g, b1};

    Lines[Line_i].first = l;
    Lines[Line_i].second = *color;
}

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

    newLine(2, 3, 200, 100, 2);
    newLine(5, 300, 200, 100, 2);

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

        

        for (int i = 0; i <= sizeof(Lines) / sizeof(int); i++){
            Line l = Lines[i].first;

            for (int x = -windowWidth / 2; x <= windowWidth / 2; x++ ){
                SDL_RenderDrawPoint(s,(windowWidth / 2 + x) * zoomRatio, (windowHeight / 2 - l.get_y(x)) * zoomRatio);
            }
        }

        SDL_SetRenderDrawColor(s, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderPresent(s);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(s);
    SDL_Quit();
}

