#pragma once
#include <iostream>
#include "Constants.h"


class Board {
public:
	Board(); // Constructor

	const int getCell(int x, int y) const;
	const int getWidth() const;
	const int getHeight() const;

private:
	static const int mHeight = BOARD_HEIGHT + BOARD_MARC_PADDING * 2;
	static const int mWidth = BOARD_WIDTH + BOARD_MARC_PADDING * 2;

	int mBoard[mHeight][mWidth];	// Board that contains the pieces
	void initializeBoard(); // Initialize with zeros
};