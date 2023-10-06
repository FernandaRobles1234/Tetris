#pragma once
#pragma once
#include <SDL.h>
#include <iostream>


class Game {
public:
	Game(SDL_Renderer* sdlRenderer);
	bool isRunning();
	void handleEvents();
	void update();
	void render();

private:
	SDL_Renderer* mSdlRenderer;
	bool mIsRunning;
};