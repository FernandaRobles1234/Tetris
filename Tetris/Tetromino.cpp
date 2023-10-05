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
Tetromino::Tetromino(int type): mType(type), mRot(0), mPosX(mTetrominosInitPos[mType][X]), mPosY(mTetrominosInitPos[mType][Y]) {
	// TODO: Make constraints so we cant acces invalid data (Aka. type outside range)
	// TODO: Assertion or exception? When exception caught the SDL window crashes
}

const int Tetromino::getCell(int x, int y) const {
	if (x >= 0 && x < TETROMINO_WIDTH && y >= 0 && y < TETROMINO_HEIGHT)
		return mTetrominos[mType][mRot][y][x];
	else
		// return a value indicating an invalid cell
		return -1;  
}

void Tetromino::moveRight() {
	//TODO: implement Collision detection?
	mPosX++;
}

void Tetromino::moveLeft() {
	//TODO: implement Collision detection?
	mPosX--;
}

void Tetromino::moveDown() {
	//TODO: implement Collision detection?
	mPosY++;
}

void Tetromino::rotate() {
	//TODO: implement Collision detection?
	mRot = (mRot + 1) % TETROMINO_ROT;
}

bool Tetromino::collidesWith(const Board& board) const {
	std::cout << board.getCell(this->getPosX(), this->getPosY()) << std::endl;

	return false;
}