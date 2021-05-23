#include "Engine.h"
#include <algorithm>
#include <iostream>
#include <xml_parser/XMLParser.h>
#include "../TextureLoaders/SDLInit.h"

Engine::Engine() : startTime(0), endTime(0), interval(0)
{
	if (!initGame()) {
		quit = true;
	}
}

Engine::~Engine()
{
	SDL::quit();
}

void Engine::updateItems()
{
	SDL::mainWindow->Update(SDL::elapsedTime());
}

bool Engine::gameOver()
{
	return false;
}

bool Engine::initGame()
{
	if (!(SDL::initialise()))
	{
	#ifdef DEBUG
		std::cout << "SDL_Init() failed.\n";
	#endif
		return false;
	}
	else return true;
}

void Engine::startLoop()
{
	SDL_Event eventLast;
	while (!quit) {
		while (SDL_PollEvent(&eventLast) != 0)
		{
			if (eventLast.type == SDL_QUIT) {
				quitGame();
			}
			else
			{
				switch (eventLast.type)
				{
				case SDL_MOUSEMOTION:
					SDL::mainWindow->mouseHover(eventLast.motion);
					break;
				case SDL_MOUSEBUTTONUP:
				case SDL_MOUSEBUTTONDOWN:
					SDL::mainWindow->mouseClick(eventLast.button);
					break;
				case SDL_KEYUP:
				case SDL_KEYDOWN:
					SDL::mainWindow->onKeyPress(eventLast.key);
				}
			}
		}
		updateItems();
	}
}

void Engine::quitGame() {
	quit = true;
}