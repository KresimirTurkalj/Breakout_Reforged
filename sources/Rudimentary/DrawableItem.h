#pragma once
#include "Texture.h"
#include "../EventInterfaces/EventProcessor.h"
#include "../EventInterfaces/IDrawable.h"

class DrawableItem : public IPositionable, public IDrawable
{
public:
	DrawableItem(IPositionable* parent);
	virtual ~DrawableItem();
	virtual void DrawTo(SDL_Renderer* renderer) override;
	virtual bool loadTexture(SDL_Surface* surface);

protected:
	std::unique_ptr<Texture> texture;
};

