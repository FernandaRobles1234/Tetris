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
	const bool isRunning() const;
	void handleEvents();
	void update();
	void render();

private:
	SDL_Renderer* mSdlRenderer;
	bool mIsRunning;
	Board mBoard;
	Tetromino mTetromino;

	Uint32 mLastFallTime= 0;    // Records the time of the last automatic fall
	const Uint32 mFallInterval = 1000; // Interval in milliseconds (1 second in this example)
	
	void renderWindow();
	void renderBoardMark();
	void renderBoard();
	void renderTetromino();

	void merge();

	void updateAutomaticFall();
};