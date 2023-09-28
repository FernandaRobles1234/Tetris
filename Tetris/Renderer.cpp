//void renderBoard(SDL_Renderer* renderer, const Board& board, int boardOffsetX, int boardOffsetY, int cellSize, int cellSpacing = 0) {
//	for (int x = 0; x < BOARD_WIDTH; x++) {
//		for (int y = 0; y < BOARD_HEIGHT; y++) {
//			int cellValue = board.getCell(x, y);
//
//			if (cellValue == 0) {
//				// Set the color and render based on the cellValue
//				SDL_SetRenderDrawColor(renderer, 211, 211, 211, 211);  // Example color for non-zero value
//
//				int renderX = boardOffsetX + x * (cellSize + cellSpacing);
//				int renderY = boardOffsetY + y * (cellSize + cellSpacing);
//
//				SDL_Rect cellRect = { renderX, renderY, cellSize, cellSize };
//				SDL_RenderFillRect(renderer, &cellRect);
//			}
//		}
//	}
//}