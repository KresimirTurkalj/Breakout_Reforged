#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

typedef unsigned int uint;
class Texture
{
public:
	Texture();
	virtual ~Texture();
	
	SDL_Texture* getSDLTexture();
	SDL_Point& getPosition();
	SDL_Rect* getTextureClip();
	void freeTexture();
	bool textureFromSurface(SDL_Surface* surface, SDL_Renderer* renderer);

protected:
	SDL_Texture* textureHolder;
	SDL_Rect textureClip;
	SDL_Point texturePosition;
};