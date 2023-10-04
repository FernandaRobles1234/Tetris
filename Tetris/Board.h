#pragma once
#include "Constants.h"


class Board {
public:
	Board(); // Constructor
	int getCell(int x, int y) const; //Getter for cell values

private:
	int mBoard[BOARD_HEIGHT][BOARD_WIDTH];	// Board that contains the pieces
	void initializeBoard(); // Initialize with zeros
};