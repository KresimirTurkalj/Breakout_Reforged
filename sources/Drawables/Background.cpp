#include "Background.h"
#include "../TextureLoaders/SDLInit.h"

Background::Background(std::string filePath, IPositionable* parent) : DrawableItem(parent)
{
	if (auto surface = SDLgraphics::getImageSurface(filePath))
	{
		loadTexture(surface);
		SDLgraphics::freeSurface(surface);
	}
}

void Background::DrawTo(SDL_Renderer* renderer)
{
	auto textureArea = texture->getTextureClip();
	SDL_Rect position{ 0, 0, textureArea->w, textureArea->h }, edgeArea = *textureArea;
	while (parent->Size().x > position.x + textureArea->w)
	{
		position.y = 0;
		position.h = textureArea->h;
		while (parent->Size().y > position.y + textureArea->h)
		{
			SDL_RenderCopy(renderer, texture->getSDLTexture(), textureArea, &position);
			position.y += textureArea->h - 1;
		}
		edgeArea.h = parent->Size().y - position.y;
		position.h = edgeArea.h;
		SDL_RenderCopy(renderer, texture->getSDLTexture(), &edgeArea, &position);
		position.x += textureArea->h - 1;
	}
	position.y = 0;
	edgeArea.w = parent->Size().x - position.x;
	edgeArea.h = textureArea->h;
	position.h = edgeArea.h;
	position.w = edgeArea.w;
	while (parent->Size().y > position.y + textureArea->h)
	{
		SDL_RenderCopy(renderer, texture->getSDLTexture(), &edgeArea, &position);
		position.y += textureArea->h - 1;
	}
	edgeArea.h = parent->Size().y - position.y;
	position.h = edgeArea.h;
	SDL_RenderCopy(renderer, texture->getSDLTexture(), &edgeArea, &position);
}
