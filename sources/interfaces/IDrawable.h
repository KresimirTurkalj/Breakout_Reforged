#pragma once

class SDL_Surface;

class IDrawable {
public:
	virtual void blitElement(SDL_Surface* parentSurface) = 0;
	virtual ~IDrawable(){}
};