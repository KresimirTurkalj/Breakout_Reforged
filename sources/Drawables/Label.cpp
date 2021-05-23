#include "Label.h"
#include "../TextureLoaders/SDLInit.h"

Label::Label(std::string text, IPositionable* parent) : DrawableItem(parent), foregroundColor(SDL_Color{255,255,255,255}), labelText(text)
{
	if (auto surface = SDLtext::getTextSurface(text, foregroundColor))
	{
		loadTexture(surface);
		SetSize(SDL_Point{ texture->getTextureClip()->w, texture->getTextureClip()->h });
		SDLgraphics::freeSurface(surface);
	}
}

void Label::setTextureForString(std::string label)
{
	texture->freeTexture();
	if (auto surface = SDLtext::getTextSurface(label, foregroundColor))
	{
		loadTexture(surface);
		SetSize(SDL_Point{ texture->getTextureClip()->w, texture->getTextureClip()->h });
		SDL_FreeSurface(surface);
	}
}

void Label::SetTextColour(SDL_Color color)
{
	foregroundColor = color;
}

void Label::updateText()
{
	texture->freeTexture();
	if (auto surface = SDLtext::getTextSurface(labelText, foregroundColor))
	{
		loadTexture(surface);
		SetSize(SDL_Point{ texture->getTextureClip()->w, texture->getTextureClip()->h });
		SDL_FreeSurface(surface);
	}
}
