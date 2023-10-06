#include "Board.h"

Board::Board() {
    initializeBoard();
}

// Initialize all cells to 0 (empty) and initialize limit with 1
void Board::initializeBoard() {
    for (int y = 0; y < mHeight; y++) {
        for (int x = 0; x < mWidth; x++) {
           
            mBoard[y][x] = 0;
            //std::cout << 0;
        }
        //std::cout << std::endl;
    }
    //std::cout << std::endl;
}

// Board's cells getter
const int Board::getCell(int x, int y) const {
    if (x >= 0 && x < mWidth && y >= 0 && y < mHeight)
        return mBoard[y][x];
    else
        return -1;  // return a value indicating an invalid cell
}

const int Board::getWidth() const {
    return mWidth;
}

const int Board::getHeight() const {
    return mHeight;
}

void Board::setCell(int x, int y, int newVal) {
    if (x >= 0 && x < mWidth && y >= 0 && y < mHeight)
        mBoard[y][x] = newVal;

    // TODO: What to do in case of invalid value?
}

void Board::clearCompletedLines()
{
    
    // Check for zeros in each line
    for (int y = 0; y < this->getHeight(); y++) {
        bool lineComplete = true;
        for (int x = 0; x < this->getWidth(); x++) {
            if (this->getCell(x, y) == 0) {
                lineComplete = false;
                break;
            }
        }

        // If no zeros, shift the rows down
        if (lineComplete) {
            //std::cout << "Clearing completed lines" << std::endl;

            for (int aboveRow = y - 1; aboveRow >= 0; aboveRow--) {
                for (int x = 0; x < this->getWidth(); x++) {
                    this->setCell(x, aboveRow + 1, this->getCell(x, aboveRow));
                    this->setCell(x, aboveRow, 0);
                }
            }


        }
    }
}

bool Board::isFull() {
    for (int x = 0; x < this->getWidth(); x++) {
        if (this->getCell(x, 0) != 0) {
            return true;
        }
    }

    return false;
}
