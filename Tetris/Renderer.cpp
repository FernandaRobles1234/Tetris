#include "Renderer.h"

// Constructor implementation
Renderer::Renderer(SDL_Renderer* sdlRenderer)
	: mSdlRenderer(sdlRenderer) // Initialize mSdlRenderer with the provided SDL_Renderer pointer
{
	// Any other initialization logic can go here if necessary
}

void Renderer::renderBoard(const Board& board, int boardOffsetX, int boardOffsetY, int cellSize, int cellSpacing) {
	for (int x = 0; x < BOARD_WIDTH; x++) {
		for (int y = 0; y < BOARD_HEIGHT; y++) {
			int cellValue = board.getCell(x, y);

			if (cellValue == 0) {
				// Set the color and render based on the cellValue
				SDL_SetRenderDrawColor(mSdlRenderer, 211, 211, 211, 211);  // Example color for non-zero value

				int renderX = boardOffsetX + x * (cellSize + cellSpacing);
				int renderY = boardOffsetY + y * (cellSize + cellSpacing);

				SDL_Rect cellRect = { renderX, renderY, cellSize, cellSize };
				SDL_RenderFillRect(mSdlRenderer, &cellRect);
			}
		}
	}
}