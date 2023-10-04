#pragma once

constexpr int BOARD_WIDTH = 10;
constexpr int BOARD_HEIGHT = 20;

// Define cell size
constexpr int CELL_SIZE = 15;
constexpr int CELL_SPACING = 2;

// Define screen dimensions
constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

// Calculate middle positioning
constexpr int BOARD_OFFSET_MIDDLE_X = (SCREEN_WIDTH / 2) - (BOARD_WIDTH * (CELL_SIZE + CELL_SPACING)) / 2;
constexpr int BOARD_OFFSET_MIDDLE_Y = (SCREEN_HEIGHT / 2) - (BOARD_HEIGHT * (CELL_SIZE + CELL_SPACING)) / 2;

// Define board position
constexpr int BOARD_OFFSET_X = BOARD_OFFSET_MIDDLE_X;
constexpr int BOARD_OFFSET_Y = BOARD_OFFSET_MIDDLE_Y;

// Define board position
constexpr int BOARD_MARC_THICK = 1;

// Tetrominos characteristics
constexpr int TETROMINO_TYPE = 2;
constexpr int TETROMINO_ROT = 4;
constexpr int TETROMINO_HEIGHT = 5;
constexpr int TETROMINO_WIDTH = 5;

// Coordinate system
constexpr int DIM2 = 2;
constexpr int X = 0;
constexpr int Y = 1;
