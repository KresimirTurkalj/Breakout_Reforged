#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <chrono>
#include "../Windows/MainWindow/MainWindow.h"

class SDLgraphics{
public:
	static bool initialise(int flags);
	static SDL_Surface* getImageSurface(std::string filePath);
	static void freeSurface(SDL_Surface* surface);
	static void quit();
};

class SDLtext {
public:
	static bool initialise();
	static void quit();
	static SDL_Surface* getTextSurface(std::string text, SDL_Color fg);
	static void freeSurface(SDL_Surface* surface);
private:
	static TTF_Font* openSansBold20;
};

class SDL {
public:
	static bool initialise();
	static SDL_Renderer* getRenderer();
	static std::chrono::steady_clock::duration elapsedTime(); //Get time in milliseconds since last call of this function;
	static void quit();

	static std::unique_ptr<MainWindow> mainWindow;
	static std::chrono::steady_clock::time_point startTime;
	static std::chrono::steady_clock::time_point endTime;
};