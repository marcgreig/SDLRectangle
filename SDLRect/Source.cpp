#include "SDL/include/SDL.h"
#pragma comment (lib, "SDL/libx86/SDL2.lib")
#pragma comment (lib, "SDL/libx86/SDL2main.lib")

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, 0);
	
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	
	SDL_Rect rect = { 550, 350, 150, 100 };
	
	SDL_Rect bullet;
	bullet.w = 15;
	bullet.h = 10;

	bool isRunning = true;
	SDL_Event event;

	while (isRunning) {

		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				isRunning = false;
			}
			/*const Uint8 *keystates = SDL_GetKeyboardState(NULL);
			
			if (keystates[SDLK_UP]) {
				if (rect.y > 0) {
					rect.y -= 10;
				}
				break;
			}

			if (keystates[SDLK_DOWN]) {
				if (rect.y + rect.h < 800) {
					rect.y += 10;
				}
				break;
			}

			if (keystates[SDLK_RIGHT]) {
				if (rect.x + rect.w < 1200) {
					rect.x += 10;
				}
				break;
			}

			if (keystates[SDLK_LEFT]) {
				if (rect.x > 0) {
					rect.x -= 10;
				}
				break;
			}

			if (keystates[SDLK_SPACE]) {
				bullet.x = rect.x + 150;
				bullet.y = rect.y + rect.h / 2 - bullet.h / 2;
				break;
			}*/

			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				
				case SDLK_UP:
					if (rect.y > 0) {
						rect.y -= 10;
					}
					break;

				case SDLK_DOWN:
					if (rect.y + rect.h < 800) {
						rect.y += 10;
					}
					break;

				case SDLK_RIGHT:
					if (rect.x +rect.w < 1200) {
						rect.x += 10;
					}
					break;

				case SDLK_LEFT:
					if (rect.x > 0) {
						rect.x -= 10;
					}
					break;

				case SDLK_SPACE:
					bullet.x = rect.x + 150;
					bullet.y = rect.y + rect.h / 2 - bullet.h /2;
					break;
				}
			}
		}
		
		if (bullet.x < 1200) {
			bullet.x += 1;
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(renderer, &bullet);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}