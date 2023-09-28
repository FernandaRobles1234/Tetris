#pragma once

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;

class Board {
public:
	Board(); // Constructor
	int getCell(int x, int y) const; //Getter for cell values

private:
	int mBoard[BOARD_HEIGHT][BOARD_WIDTH];	// Board that contains the pieces
	void initializeBoard(); // Initialize with zeros
};