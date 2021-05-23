#pragma once
#include <vector>
#include "../Windows/MainWindow/MainWindow.h"
#include <string>
#include <xml_parser/XMLParser.h>
#include "../EventInterfaces/EventProcessor.h"
#include "../Drawables/Background.h"

class Engine {
public:
	Engine();
	~Engine();
	void startLoop();
	void quitGame();
private:
	bool quit = false;
	Uint32 startTime, endTime, interval;

	bool initGame();
	bool gameOver();

	void updateItems();
};