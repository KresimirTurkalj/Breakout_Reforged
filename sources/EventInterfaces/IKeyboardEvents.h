#pragma once
#include <SDL.h>

class IKeyboardEvents {
public:
	virtual ~IKeyboardEvents(){}
	virtual void onKeyPress(SDL_KeyboardEvent keyboardEvent) = 0;
};