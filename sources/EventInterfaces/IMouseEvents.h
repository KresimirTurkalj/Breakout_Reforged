#pragma once
#include <SDL.h>

class EventProcessor;

class IMouseEvents {
	friend class EventProcessor;
public:
	virtual ~IMouseEvents(){}

	virtual void mouseHover(SDL_MouseMotionEvent motionEvent) = 0;
	virtual void mouseClick(SDL_MouseButtonEvent buttonEvent) = 0;
protected:
	virtual void mouseOutsideHover(SDL_MouseMotionEvent motionEvent) = 0;
	virtual void mouseOutsideClick(SDL_MouseButtonEvent buttonEvent) = 0;
};