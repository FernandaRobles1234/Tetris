#pragma once

// Define board size
constexpr int BOARD_WIDTH = 10;
constexpr int BOARD_HEIGHT = 20;
constexpr int BOARD_MARC_PADDING = 1;

// Define cell size
constexpr int CELL_SIZE = 15;
constexpr int CELL_SPACING = 2;

// Define screen dimensions
constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

// Calculate vanilla middle positioning 
constexpr int BOARD_OFFSET_MIDDLE_X = (SCREEN_WIDTH / 2) - (BOARD_WIDTH * (CELL_SIZE + CELL_SPACING)) / 2 ;
constexpr int BOARD_OFFSET_MIDDLE_Y = (SCREEN_HEIGHT / 2) - (BOARD_HEIGHT * (CELL_SIZE + CELL_SPACING)) / 2;

// Define board position considering mark
constexpr int BOARD_OFFSET_X = BOARD_OFFSET_MIDDLE_X - (BOARD_MARC_PADDING * (CELL_SIZE + CELL_SPACING));
constexpr int BOARD_OFFSET_Y = BOARD_OFFSET_MIDDLE_Y - (BOARD_MARC_PADDING * (CELL_SIZE + CELL_SPACING));

// Define board's mark
constexpr int BOARD_MARC_THICK = 3;


// Tetrominos characteristics
constexpr int TETROMINO_TYPE = 3;
constexpr int TETROMINO_ROT = 4;
constexpr int TETROMINO_HEIGHT = 5;
constexpr int TETROMINO_WIDTH = 5;

// Coordinate system
constexpr int DIM2 = 2;
constexpr int X = 0;
constexpr int Y = 1;
