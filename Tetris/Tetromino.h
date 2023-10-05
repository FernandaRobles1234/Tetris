#pragma once
#include "Constants.h"

class Tetromino {
public:
	Tetromino(int type);

	int mType;
	int mRot;
	int mPosX;
	int mPosY;
	

	const int getCell(int x, int y) const;
	const int getPosX() const { return mPosX; }
	const int getPosY() const { return mPosY; }
	const int getRot() const { return mRot; }

	void rotate();
	void moveRight();
	void moveLeft();
	void moveDown();

private:
	static const int mTetrominos[TETROMINO_TYPE][TETROMINO_ROT][TETROMINO_HEIGHT][TETROMINO_WIDTH];
	static const int mTetrominosInitPos[TETROMINO_TYPE][DIM2];
};
