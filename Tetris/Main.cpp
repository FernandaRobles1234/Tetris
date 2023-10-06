#include <SDL.h>
#include <iostream>
#include <cassert>
#include <random>

#include "Board.h"
#include "Tetromino.h"
#include "Renderer.h"
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



int main(int argc, char* argv[]) {

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	if (!initializeSDL(window, renderer)) {
		return 1;
	}

	//Initialize game renderer
	Renderer fRenderer(renderer);
	//Game game(render)

	//while (game.isRunning()) {
//	game.handleEvents();
//	game.update();
//	game.render();
//}

	//Initialize Board
	Board gameBoard;

	//Event
	bool quit = false;
	SDL_Event e;

	//We create a random generator
	std::default_random_engine generator(static_cast<long unsigned int>(time(0)));
	std::uniform_int_distribution<int> distribution(0, TETROMINO_TYPE);

	// We create a piece for game
	int gameTetrominoType = distribution(generator);
	assert(gameTetrominoType >= 0 && gameTetrominoType < TETROMINO_TYPE);
	Tetromino gameTetromino(gameTetrominoType);
	

	// Main Loop
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