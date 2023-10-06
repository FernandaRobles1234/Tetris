#include <SDL.h>
#include <iostream>
#include <cassert>
#include <random>

#include "Board.h"
#include "Tetromino.h"
#include "Game.h"
#include "Constants.h"

bool initializeSDL(SDL_Window* &window, SDL_Renderer* &renderer) {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	// Create window
	window = SDL_CreateWindow("Tetris",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);

	if (!window) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		return false;
	}

	// Initialize renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}
	//For opacity
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	return true;
}

bool cleanupSDL(SDL_Window*& window, SDL_Renderer*& renderer) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return true;
}

int main(int argc, char* argv[]) {

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	if (!initializeSDL(window, renderer)) {
		return 1;
	}

	//Initialize game renderer
	Game game(renderer);

	//Game loop
	while (game.isRunning()) {
		game.handleEvents();
		game.update();
		game.render();
	}

	//clean up and free resources.
	cleanupSDL(window, renderer);

	return 0;
}