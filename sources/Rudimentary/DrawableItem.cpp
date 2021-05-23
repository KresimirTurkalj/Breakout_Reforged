#include "DrawableItem.h"
#include "../TextureLoaders/SDLInit.h"

DrawableItem::DrawableItem(IPositionable* parent) : IPositionable(parent), IDrawable(), texture(std::make_unique<Texture>())
{

}

DrawableItem::~DrawableItem()
{

}

void DrawableItem::DrawTo(SDL_Renderer* renderer)
{
	SDL_Rect position{ Position().x, Position().y, Size().x, Size().y };
	SDL_RenderCopy(renderer, texture->getSDLTexture(), texture->getTextureClip(), &position);
}

bool DrawableItem::loadTexture(SDL_Surface* surface)
{
	return texture->textureFromSurface(surface, SDL::getRenderer());
}
