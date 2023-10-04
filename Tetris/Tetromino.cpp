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
	}
};

const int Tetromino::mTetrominosInitPos[TETROMINO_TYPE][DIM2] =
{//Type
	{4, 0},
	{2, -2}
};

Tetromino::Tetromino(int type): mType(type), mRot(0), mPosX(mTetrominosInitPos[mType][X]), mPosY(mTetrominosInitPos[mType][Y]) {
	// TODO: Make constraints so we cant acces invalid data
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
	mPosX++;
}

void Tetromino::moveLeft() {
	mPosX--;
}

void Tetromino::moveDown() {
	mPosY++;
}

void Tetromino::rotate() {
	mRot = (mRot + 1) % TETROMINO_ROT;
}

bool Tetromino::isPosValid() {
	return false;
}