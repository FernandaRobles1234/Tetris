#pragma once
#include <random>
#include <iostream>
#include <assert.h>

#include "Constants.h"
#include "Board.h"


class Tetromino{
public:
	Tetromino(int type);
	Tetromino();

	int mType;
	int mRot;
	int mPosX;
	int mPosY;

	bool mBlockMove= false;
	
	const int getCell(int x, int y) const;
	const int getCell(int x, int y, int rot) const;
	const int getPosX() const { return mPosX; }
	const int getPosY() const { return mPosY; }
	const int getRot() const { return mRot; }

	bool rotate(const Board& board);
	bool moveRight(const Board& board);
	bool moveLeft(const Board& board);
	bool moveDown(const Board& board);

private:
	static const int mTetrominos[TETROMINO_TYPE][TETROMINO_ROT][TETROMINO_HEIGHT][TETROMINO_WIDTH];
	static const int mTetrominosInitPos[TETROMINO_TYPE][DIM2];
};
