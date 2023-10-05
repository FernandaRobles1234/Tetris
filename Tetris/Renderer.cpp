#include "Renderer.h"



// Constructor
Renderer::Renderer(SDL_Renderer* sdlRenderer): mSdlRenderer(sdlRenderer) {
	// Any other initialization logic can go here if necessary
}


// Render Mark of Board
// TODO: Fix mark so it grows in thickness outside, no inside
void Renderer::renderBoardMarc() {
	// Setting the color
	SDL_SetRenderDrawColor(mSdlRenderer, 130, 130, 170, 255);

	SDL_Rect rect;
	int x = BOARD_OFFSET_MIDDLE_X - CELL_SPACING;  // X position
	int y = BOARD_OFFSET_MIDDLE_Y - CELL_SPACING ;  // Y position
	int w = BOARD_WIDTH * (CELL_SIZE + CELL_SPACING) + CELL_SPACING;  // Width
	int h = BOARD_HEIGHT * (CELL_SIZE + CELL_SPACING) + CELL_SPACING;  // Height

	// Top line
	SDL_Rect top = { x - BOARD_MARC_THICK, y - BOARD_MARC_THICK, w + BOARD_MARC_THICK*2, BOARD_MARC_THICK };
	SDL_RenderFillRect(mSdlRenderer, &top);

	// Bottom line
	SDL_Rect bottom = { x - BOARD_MARC_THICK, y + h, w + BOARD_MARC_THICK * 2, BOARD_MARC_THICK };
	SDL_RenderFillRect(mSdlRenderer, &bottom);

	// Left line
	SDL_Rect left = { x - BOARD_MARC_THICK ,y , BOARD_MARC_THICK, h };
	SDL_RenderFillRect(mSdlRenderer, &left);

	// Right line
	SDL_Rect right = { x + w, y, BOARD_MARC_THICK, h };
	SDL_RenderFillRect(mSdlRenderer, &right);

}

void Renderer::renderBoard(const Board& board) {
	for (int x = 0; x < board.getWidth(); x++) {
		for (int y = 0; y < board.getHeight(); y++) {
			int cellValue = board.getCell(x, y);
			if (cellValue == 0) {
				// Set the color and render based on the cellValue
				SDL_SetRenderDrawColor(mSdlRenderer, 200, 200, 255, 255);

				int renderX = BOARD_OFFSET_X + x * (CELL_SIZE + CELL_SPACING);
				int renderY = BOARD_OFFSET_Y + y * (CELL_SIZE + CELL_SPACING);

				SDL_Rect cellRect = { renderX, renderY, CELL_SIZE, CELL_SIZE};
				SDL_RenderFillRect(mSdlRenderer, &cellRect);
			}
			if (cellValue == 1) {
				// Change to red for debugging
				SDL_SetRenderDrawColor(mSdlRenderer, 255, 255, 255, 0);

				int renderX = BOARD_OFFSET_X + x * (CELL_SIZE + CELL_SPACING);
				int renderY = BOARD_OFFSET_Y + y * (CELL_SIZE + CELL_SPACING);

				SDL_Rect cellRect = { renderX, renderY, CELL_SIZE, CELL_SIZE };
				SDL_RenderFillRect(mSdlRenderer, &cellRect);
			}
		}
	}
}

void Renderer::renderTetromino(const Tetromino& tetromino) {
	//std::cout << tetromino.getRot() << std::endl;


	//TODO: Change so we extract the characteristics from tetromino class
	for (int x = 0; x < TETROMINO_WIDTH; x++) {
		for (int y = 0; y < TETROMINO_HEIGHT; y++) {
			int cellValue = tetromino.getCell(x, y);
			// Code for debugging
			//std::cout << x << ", " << y << std::endl;
			//std::cout << cellValue << std::endl;

			if (cellValue != 0) {
				// Set the color and render based on the cellValue
				SDL_SetRenderDrawColor(mSdlRenderer, 173, 216, 230, 255);

				int renderRelativeX = BOARD_OFFSET_X + (x + tetromino.getPosX()) * (CELL_SIZE + CELL_SPACING);
				int renderRelativeY = BOARD_OFFSET_Y + (y + tetromino.getPosY()) * (CELL_SIZE + CELL_SPACING);

				SDL_Rect cellRect = { renderRelativeX, renderRelativeY, CELL_SIZE, CELL_SIZE };
				SDL_RenderFillRect(mSdlRenderer, &cellRect);
			}
		}
	}
}