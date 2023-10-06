#include "Game.h"

Game::Game(SDL_Renderer* sdlRenderer): mSdlRenderer(sdlRenderer), mIsRunning(true) {
}

const bool Game::isRunning() const {
	return mIsRunning;
}

void Game::handleEvents() {
	SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        switch (e.type) {

        //window's close button
        case SDL_QUIT:
            mIsRunning = false;
            break;
        
        // Handle key presses here
        case SDL_KEYDOWN:
            switch (e.key.keysym.sym) {
            case SDLK_ESCAPE:
                mIsRunning = false;
                break;
            case SDLK_UP:
                mTetromino.rotate(mBoard);
                break;
            case SDLK_DOWN:
                mTetromino.moveDown(mBoard);
                break;
            case SDLK_LEFT:
                mTetromino.moveLeft(mBoard);
                break;
            case SDLK_RIGHT:
                mTetromino.moveRight(mBoard);
                break;
            }
            break;
        }
    }
}

//Draw game board, tetrominoes, score, etc.
void Game::render() {
    
    renderWindow();
    renderBoardMark();
    renderBoard();
    renderTetromino();

    SDL_RenderPresent(mSdlRenderer);
}

void Game::renderWindow() {
    SDL_SetRenderDrawColor(mSdlRenderer, 180, 160, 250, 255);
    SDL_RenderClear(mSdlRenderer);
}

void Game::renderBoardMark() {
    // Setting the color
    SDL_SetRenderDrawColor(mSdlRenderer, 130, 130, 170, 255);

    int x = BOARD_OFFSET_MIDDLE_X - CELL_SPACING;  // X position
    int y = BOARD_OFFSET_MIDDLE_Y - CELL_SPACING;  // Y position
    int w = BOARD_WIDTH * (CELL_SIZE + CELL_SPACING) + CELL_SPACING;  // Width
    int h = BOARD_HEIGHT * (CELL_SIZE + CELL_SPACING) + CELL_SPACING;  // Height

    // Top line
    SDL_Rect top = { x - BOARD_MARC_THICK, y - BOARD_MARC_THICK, w + BOARD_MARC_THICK * 2, BOARD_MARC_THICK };
    SDL_RenderFillRect(mSdlRenderer, &top);

    // Bottom line
    SDL_Rect bottom = { x - BOARD_MARC_THICK, y + h, w + BOARD_MARC_THICK * 2, BOARD_MARC_THICK };
    SDL_RenderFillRect(mSdlRenderer, &bottom);

    // Left line
    SDL_Rect left = { x - BOARD_MARC_THICK ,y , BOARD_MARC_THICK, h };
    SDL_RenderFillRect(mSdlRenderer, &left);

    // Right line
    SDL_Rect right = { x + w, y, BOARD_MARC_THICK, h };
    SDL_RenderFillRect(mSdlRenderer, &right);
}

void Game::renderBoard() {
    for (int x = 0; x < mBoard.getWidth(); x++) {
        for (int y = 0; y < mBoard.getHeight(); y++) {
            int cellValue = mBoard.getCell(x, y);
            if (cellValue == 0) {
                SDL_SetRenderDrawColor(mSdlRenderer, 200, 200, 255, 255);

                int renderX = BOARD_OFFSET_X + x * (CELL_SIZE + CELL_SPACING);
                int renderY = BOARD_OFFSET_Y + y * (CELL_SIZE + CELL_SPACING);

                SDL_Rect cellRect = { renderX, renderY, CELL_SIZE, CELL_SIZE };
                SDL_RenderFillRect(mSdlRenderer, &cellRect);
            }
            else{
                SDL_SetRenderDrawColor(mSdlRenderer, 64, 64, 100, 255);

                int renderX = BOARD_OFFSET_X + x * (CELL_SIZE + CELL_SPACING);
                int renderY = BOARD_OFFSET_Y + y * (CELL_SIZE + CELL_SPACING);

                SDL_Rect cellRect = { renderX, renderY, CELL_SIZE, CELL_SIZE };
                SDL_RenderFillRect(mSdlRenderer, &cellRect);
            }
        }
    }
}

void Game::renderTetromino() {
    //TODO: Change so we extract the characteristics from tetromino class
    for (int x = 0; x < TETROMINO_WIDTH; x++) {
        for (int y = 0; y < TETROMINO_HEIGHT; y++) {
            int cellValue = mTetromino.getCell(x, y);
            // Debugging
            //std::cout << x << ", " << y << std::endl;
            //std::cout << cellValue << std::endl;

            if (cellValue != 0) {
                // Set the color
                SDL_SetRenderDrawColor(mSdlRenderer, 173, 216, 255, 255);

                int renderRelativeX = BOARD_OFFSET_X + (x + mTetromino.getPosX()) * (CELL_SIZE + CELL_SPACING);
                int renderRelativeY = BOARD_OFFSET_Y + (y + mTetromino.getPosY()) * (CELL_SIZE + CELL_SPACING);

                SDL_Rect cellRect = { renderRelativeX, renderRelativeY, CELL_SIZE, CELL_SIZE };
                SDL_RenderFillRect(mSdlRenderer, &cellRect);
            }
        }
    }
}

//Update
void Game::update() {
    updateAutomaticFall();

    if (mTetromino.mBlockMove) {
        merge();
    }
}

void Game::updateAutomaticFall() {
    // Check for automatic fall
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - mLastFallTime > mFallInterval) {
        mTetromino.moveDown(mBoard);
        mLastFallTime = currentTime;  // Reset the timer
    }
}

void Game::merge() {
    for (int y = 0; y < TETROMINO_HEIGHT; y++) {
        for (int x = 0; x < TETROMINO_WIDTH; x++) {
            int tetrominoValue = mTetromino.getCell(x, y);

            //Only write the figure
            if (tetrominoValue != 0){
                int globalX = mTetromino.getPosX() + x;
                int globalY = mTetromino.getPosY() + y;


                mBoard.setCell(globalX, globalY, tetrominoValue);
            }
        }
    }

    // Spawn a new Tetromino
    mTetromino = Tetromino();
}
