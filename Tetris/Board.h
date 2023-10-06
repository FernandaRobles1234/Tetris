#pragma once
#include <iostream>
#include "Constants.h"


class Board {
public:
	Board(); // Constructor

	const int getCell(int x, int y) const;
	const int getWidth() const;
	const int getHeight() const;

	void setCell(int x, int y, int newVal);


private:
	static const int mHeight = BOARD_HEIGHT;
	static const int mWidth = BOARD_WIDTH;

	int mBoard[mHeight][mWidth];	// Board that contains the pieces
	void initializeBoard(); // Initialize with zeros
};