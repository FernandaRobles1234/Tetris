#include "Board.h"


Board::Board() {
    initializeBoard();
}


// Initialize all cells to 0 (empty).
void Board::initializeBoard() {
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            mBoard[y][x] = 0;
        }
    }
}

// Board's cells getter
int Board::getCell(int x, int y) const {
    if (x >= 0 && x < BOARD_WIDTH && y >= 0 && y < BOARD_HEIGHT)
        return mBoard[x][y];
    else
        return -1;  // return a value indicating an invalid cell
}