#include "Texture.h"

Texture::Texture() : textureHolder(nullptr), textureClip(SDL_Rect{ 0,0,0,0 }), texturePosition(SDL_Point{0,0})
{

}

Texture::~Texture()
{
	freeTexture();
}

bool Texture::textureFromSurface(SDL_Surface* surface, SDL_Renderer* renderer)
{
	freeTexture();
	textureHolder = SDL_CreateTextureFromSurface(renderer, surface);
	if (textureHolder == NULL)
	{
	#ifdef DEBUG
		std::cout << SDL_GetError() << std::endl;
	#endif // DEBUG
		return false;
	}
	textureClip = { 0, 0, surface->w, surface->h };
	return true;
}

SDL_Texture* Texture::getSDLTexture()
{
	return textureHolder;
}

SDL_Point& Texture::getPosition()
{
	return texturePosition;
}

SDL_Rect* Texture::getTextureClip()
{
	return &textureClip;
}

void Texture::freeTexture()
{
	if (textureHolder != NULL)
	{
		SDL_DestroyTexture(textureHolder);
	}
}
