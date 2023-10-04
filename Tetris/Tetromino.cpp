#include "Tetromino.h"
#include <iostream>

const int Tetromino::mTetrominos[TETROMINO_TYPE][TETROMINO_ROT][TETROMINO_HEIGHT][TETROMINO_WIDTH] =
{//Type
	{//Rotation
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,0,0,0},
			{0,0,0,0}
		}
	}
};

Tetromino::Tetromino(int type): mType(type), mRot(0), mPosX(0), mPosY(0) {
	//TODO: Make constraints so we cant acces invalid data
	if (type < 0 || type >= TETROMINO_TYPE) {
		throw std::out_of_range("Invalid tetromino type provided");
	}

}

// Deprecated, just an example on how to do 2d array functions
const int(*Tetromino::getTetromino() const)[TETROMINO_HEIGHT][TETROMINO_WIDTH]{
	return &mTetrominos[mType][mRot];
}

const int Tetromino::getTetrominoCell(int x, int y) const {
	if (x >= 0 && x < TETROMINO_WIDTH && y >= 0 && y < TETROMINO_HEIGHT)
		return mTetrominos[mType][mRot][x][y];
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