#include <iostream>
#include<SDL2/SDL.h>

using namespace std;

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;

int main(int argc, char* args[]){
	SDL_Window* window = NULL;
	
	SDL_Surface* screenSurface = NULL;
	
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		cout << "SDL could not initialize! SDL_Error:\n" << SDL_GetError() << endl;
	}

	else
	{
		window = SDL_CreateWindow( "Linear eu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			cout << "Window could not be created! SDL_Error: \n" << SDL_GetError() << endl;
		}
		else
		{
			screenSurface = SDL_GetWindowSurface( window );

			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
			
			SDL_UpdateWindowSurface( window );
            
            SDL_Event e; 
			bool quit = false; 

			while( quit == false ){
				while( SDL_PollEvent( &e ) ){
					if( e.type == SDL_QUIT ) quit = true; 
				}
			}
		}
	}

	SDL_DestroyWindow( window );

	SDL_Quit();

	return 0;
}