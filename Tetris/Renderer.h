#pragma once
#include <SDL.h>
#include <iostream>

#include "Board.h"
#include "Tetromino.h"
#include "Constants.h"


// This would include drawing the board, the active tetromino, scores, and any other visual elements.
class Renderer {
public:
    Renderer(SDL_Renderer* sdlRenderer);
    void renderBoardMarc();
    void renderBoard(const Board& board);
    void renderTetromino(const Tetromino& tetromino);

private:
    SDL_Renderer* mSdlRenderer;
};