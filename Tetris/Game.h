#pragma once
#pragma once
#include <SDL.h>
#include <iostream>

#include "Constants.h"
#include "Board.h"
#include "Tetromino.h"

class Game {
public:
	Game(SDL_Renderer* sdlRenderer);
	bool isRunning();
	void handleEvents();
	void update();
	void render();

private:
	SDL_Renderer* mSdlRenderer;
	bool mIsRunning;
	Board mBoard;
	Tetromino mTetromino;
	
	void renderWindow();
	void renderBoardMark();
	void renderBoard();
	void renderTetromino();
};