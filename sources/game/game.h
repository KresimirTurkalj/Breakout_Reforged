#pragma once
#include <vector>
#include <SDL.h>
#include <string>
#include <xml_parser/XMLParser.h>

class IPresentable;

class Game {
public:
	static const int SCREEN_WIDTH = 852;  //Prebaci u klasu sa konstantama
	static const int SCREEN_HEIGHT = 480; //Prebaci u klasu sa konstantama
	Game();
	~Game();
	void loop();
	void quitGame();
private:
	const std::string initFileLocation = "./game.xml"; //Prebaci u klasu sa konstantama
	IPresentable *currentScreen;
	XMLParser::GameInfo gameInfo;
	int levelsPassed = 0;

	SDL_Window* windowOfGame = NULL;
	SDL_Surface* surfaceOfWindow = NULL;
	bool quit = false;

	bool initWindow();
	bool initSDL();
	bool initGame();
	void setNextScene();
	int frequencyToCentiseconds(int frequency) { return  ((1 * 1000 / frequency)/10)*10; }
	bool gameOver();
};