#include "game.h"
#include <menu/Menu.h>
#include <algorithm>
#include <iostream>
#include <xml_parser/XMLParser.h>
#include <scene/SceneFactory.h>
#include <timer\Timer.h>

Game::Game()
{
	if (!initGame()) {
		#ifdef DEBUG
			std::cout << "initWindow() failed.\n";
		#endif
		quit = true;
	}
	else {
		gameInfo = XMLParser::getGameInfoFrom(initFileLocation);
		setNextScene();
	}
}

Game::~Game()
{
	if (windowOfGame != NULL) {
		SDL_DestroyWindow(windowOfGame);
	}
	if (surfaceOfWindow != NULL) {
		SDL_FreeSurface(surfaceOfWindow);
	}
}

bool Game::initWindow()
{
	windowOfGame = SDL_CreateWindow("Breakout Reforged", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	if (windowOfGame == NULL) {
	#ifdef DEBUG
		std::cout << "initWindow() failed.\n";
	#endif
		return false;
	}
	surfaceOfWindow = SDL_GetWindowSurface(windowOfGame);
	return true;
}

bool Game::initSDL() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		#ifdef DEBUG
		std::cout << "initSDL() failed.\n";
		#endif
		return false;
	}
	return true;
}

bool Game::initGame()
{
	if (!initSDL()) { return false; }
	else { return initWindow(); }
}

void Game::setNextScene()
{
	if (!gameOver()) {
		currentScreen = SceneFactory::getScene(gameInfo.rootOfFiles + gameInfo.levelNames.front(), surfaceOfWindow);
	}
}

bool Game::gameOver()
{
	return levelsPassed < gameInfo.levelNames.size();
}

void Game::loop()
{
	SDL_Event eventLast;
	Timer timer;
	while (!quit && gameOver()) {
		while (SDL_PollEvent(&eventLast) != 0)
		{
			if (eventLast.type == SDL_QUIT) {
				quitGame();
			}
		}
		
	}
}

void Game::quitGame() {
	quit = true;
}