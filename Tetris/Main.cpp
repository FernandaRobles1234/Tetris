#include <SDL.h>
#include <iostream>

#include "Board.h"
#include "Renderer.h"


// Define screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Define cell size
const int CELL_SIZE = 15; // for instance
const int CELL_SPACING = 2; // for instance, optional

// Calculate middle positioning
const int BOARD_OFFSET_MIDDLE_X = (SCREEN_WIDTH / 2) - (BOARD_WIDTH * (CELL_SIZE + CELL_SPACING)) / 2;
const int BOARD_OFFSET_MIDDLE_Y = (SCREEN_HEIGHT / 2) - (BOARD_HEIGHT * (CELL_SIZE + CELL_SPACING)) / 2;

// Define board position
const int BOARD_OFFSET_X = BOARD_OFFSET_MIDDLE_X;
const int BOARD_OFFSET_Y = BOARD_OFFSET_MIDDLE_Y;


Board gameBoard;


int main(int argc, char* argv[]) {
	// At its core, it'll have Initialization, Main Loop (with Event Handling, Update, and Render phases), and Cleanup.
	//Initialize the game windowand renderer.

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	// Create window
	//If successful, the function will return a pointer to an SDL_Window structure. If it fails, it will return NULL. It's a good practice to check the return value to ensure the window was created successfully.
	SDL_Window* window = SDL_CreateWindow("Tetris",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);

	if (!window) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	// Create renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	Renderer fRenderer(renderer);

	bool quit = false;
	SDL_Event e;

	while (!quit) {
		// Event Handling
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			// TODO: Handle other events, like keyboard input
		}

		// Update game state
		// TODO: Move tetrominoes, check for collisions, line clears, etc.

		// Render
		SDL_SetRenderDrawColor(renderer, 255, 182, 193, 255); // White background
		SDL_RenderClear(renderer);

		// TODO: Draw game board, tetrominoes, score, etc.
		fRenderer.renderBoard(gameBoard, BOARD_OFFSET_X, BOARD_OFFSET_Y, CELL_SIZE, CELL_SPACING);

		SDL_RenderPresent(renderer);
	}


	//clean up and free resources.
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}