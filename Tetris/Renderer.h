#pragma once

#include <SDL.h>
#include "Board.h"



// This would include drawing the board, the active tetromino, scores, and any other visual elements.

class Renderer {
public:
    Renderer(SDL_Renderer* sdlRenderer);
    void renderBoard(const Board& board, int boardOffsetX, int boardOffsetY, int cellSize, int cellSpacing = 0);

private:
    SDL_Renderer* mSdlRenderer;
};