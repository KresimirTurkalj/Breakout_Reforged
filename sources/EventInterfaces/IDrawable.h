#pragma once
#include <SDL.h>

class IDrawable {
public:
	IDrawable() : enabled(true){}
	virtual void setEnabled(bool state) { enabled = state; };
	virtual bool isEnabled() { return enabled; };
	virtual void DrawTo(SDL_Renderer* renderer) = 0;

	virtual ~IDrawable(){}
protected:
	bool enabled;
};