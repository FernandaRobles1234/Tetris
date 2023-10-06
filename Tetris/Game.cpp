#include "Game.h"

Game::Game(SDL_Renderer* sdlRenderer): mSdlRenderer(sdlRenderer), mIsRunning(true) {

}

bool Game::isRunning() {
	return mIsRunning;
}

void Game::handleEvents() {
	SDL_Event e;

    while (SDL_PollEvent(&e) != 0) {
        switch (e.type) {
        case SDL_QUIT:
            mIsRunning = false;
            break;
        case SDL_KEYDOWN:
            //TODO: Do I add collision checks here?
            // Handle key presses here
            break;
            // Add other event types as needed...
        }
    }
}