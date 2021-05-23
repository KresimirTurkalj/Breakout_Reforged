#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include "DrawableItem.h"
#define DEBUG

typedef unsigned int uint;

class Renderer
{
public:
	Renderer(SDL_Window* window);
	~Renderer();
	void clearScreen();
	void updateScreen();
	SDL_Renderer* getRenderer();
	SDL_Rect& getWindowArea();

private:
	SDL_Renderer* rendererHolder;
	SDL_Rect viewport;
};

