#include <SDL.h>
#include <iostream>
#include <cassert>

#include "Board.h"
#include "Tetromino.h"
#include "Renderer.h"
#include "Constants.h"

int main(int argc, char* argv[]) {
	// Initialization, Main Loop (with Event Handling, Update, and Render phases), and Cleanup.

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	// Create window
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

	// Initialize renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	
	//Initialize game renderer
	Renderer fRenderer(renderer);

	//Initialize Board
	// TODO: Should we initialize it here?
	Board gameBoard;

	bool quit = false;
	SDL_Event e;

	// We create a piece for game
	int gameTetrominoType = 1;
	assert(gameTetrominoType >= 0 && gameTetrominoType < TETROMINO_TYPE);
	Tetromino gameTetromino(gameTetrominoType);
	
	while (!quit) {
		
		// Event Handling
		// Check for keyboard events
		// TODO: Should we separate the update game and event handling? Two whiles?
		while (SDL_PollEvent(&e) != 0) {
			// TODO: Fix escape key
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					
					gameTetromino.rotate(gameBoard);
					
					break;
				case SDLK_DOWN:
					
					gameTetromino.moveDown(gameBoard);
					
					break;
				case SDLK_LEFT:
					
					gameTetromino.moveLeft(gameBoard);
					
					break;
				case SDLK_RIGHT:
					
					gameTetromino.moveRight(gameBoard);
					
					break;
				}
			}
			// TODO: Handle other events, like keyboard input
		}

		// Update game state
		// TODO: Move tetrominoes, check for collisions, line clears, etc.
		
		// Render
		SDL_SetRenderDrawColor(renderer, 180, 160, 250, 255);
		SDL_RenderClear(renderer);

		// TODO: Draw game board, tetrominoes, score, etc.
		fRenderer.renderBoardMarc();
		fRenderer.renderBoard(gameBoard);
		fRenderer.renderTetromino(gameTetromino);

		
		SDL_RenderPresent(renderer);
	}


	//clean up and free resources.
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}