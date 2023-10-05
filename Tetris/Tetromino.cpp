#include "Tetromino.h"
#include <iostream>

const int Tetromino::mTetrominos[TETROMINO_TYPE][TETROMINO_ROT][TETROMINO_HEIGHT][TETROMINO_WIDTH] =
//Type
{
	//Rotation
	// Square
	{
		{
			{1,1,0,0,0},
			{1,1,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0}
		},
		{
			{1,1,0,0,0},
			{1,1,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0}
		},
		{
			{1,1,0,0,0},
			{1,1,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0}
		},
		{
			{1,1,0,0,0},
			{1,1,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0}
		}
	},

	// I
	{
		{
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,1,1,1,1},
			{0,0,0,0,0},
			{0,0,0,0,0}
		},
		{
			{0,0,0,0,0},
			{0,0,1,0,0},
			{0,0,1,0,0},
			{0,0,1,0,0},
			{0,0,1,0,0}
		},
		{
			{0,0,0,0,0},
			{0,0,0,0,0},
			{1,1,1,1,0},
			{0,0,0,0,0},
			{0,0,0,0,0}
		},
		{
			{0,0,1,0,0},
			{0,0,1,0,0},
			{0,0,1,0,0},
			{0,0,1,0,0},
			{0,0,0,0,0}
		}
	},

	// Null
	{
		{
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0}
		},
		{
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0}
		},
		{
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0}
		},
		{
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0}
		}
	}
	
};

const int Tetromino::mTetrominosInitPos[TETROMINO_TYPE][DIM2] =
{//Type
	{4, 0},
	{2, -2}
};

//TODO: Should we initialize mRot with literal 0?
Tetromino::Tetromino(int type): mType(type), mRot(0), mPosX(mTetrominosInitPos[mType][X]), mPosY(mTetrominosInitPos[mType][Y]){
	// TODO: Make constraints so we cant acces invalid data (Aka. type outside range)
	// TODO: Assertion or exception? When exception caught the SDL window crashes
}

const int Tetromino::getCell(int x, int y, int rot) const {
	if (x >= 0 && x < TETROMINO_WIDTH && y >= 0 && y < TETROMINO_HEIGHT)
		return mTetrominos[mType][rot][y][x];
	else
		// return a value indicating an invalid cell
		return -1;  
}

const int Tetromino::getCell(int x, int y) const {
	if (x >= 0 && x < TETROMINO_WIDTH && y >= 0 && y < TETROMINO_HEIGHT)
		return mTetrominos[mType][mRot][y][x];
	else
		// return a value indicating an invalid cell
		return -1;
}

bool Tetromino::moveRight(const Board& board) {
	int simulatedPosX = mPosX + 1;

	// Collision detection
	for (int y = 0; y < TETROMINO_HEIGHT; y++) {
		for (int x = 0; x < TETROMINO_WIDTH; x++) {
			
			if ((this->getCell(x, y) != 0) && (board.getCell(simulatedPosX + x, this->getPosY() + y) != 0)) {
				return false;
			}
		}
	}

	mPosX++;
	return true;
}

bool Tetromino::moveLeft(const Board& board) {
	int simulatedPosX = mPosX - 1;

	// Collision detection
	for (int y = 0; y < TETROMINO_HEIGHT; y++) {
		for (int x = 0; x < TETROMINO_WIDTH; x++) {

			if ((this->getCell(x, y) != 0) && (board.getCell(simulatedPosX + x, this->getPosY() + y) != 0)) {
				return false;
			}
		}
	}

	mPosX--;
	return true;
}

bool Tetromino::moveDown(const Board& board) {
	int simulatedPosY = mPosY + 1;

	// Collision detection
	for (int y = 0; y < TETROMINO_HEIGHT; y++) {
		for (int x = 0; x < TETROMINO_WIDTH; x++) {

			if ((this->getCell(x, y) != 0) && (board.getCell(this->getPosX() + x, simulatedPosY + y) != 0)) {
				return false;
			}
		}
	}

	mPosY++;
	return true;
}

bool Tetromino::rotate(const Board& board) {
	int simulatedRot = (mRot + 1) % TETROMINO_ROT;

	// Collision detection
	for (int y = 0; y < TETROMINO_HEIGHT; y++) {
		for (int x = 0; x < TETROMINO_WIDTH; x++) {

			if ((this->getCell(x, y, simulatedRot) != 0) && (board.getCell(this->getPosX() + x, this->getPosY() + y) != 0)) {
				return false;
			}
		}
	}

	mRot= (mRot + 1) % TETROMINO_ROT;
	return true;

}
