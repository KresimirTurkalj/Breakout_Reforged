#pragma once
#include <SDL.h>
#include "../Rudimentary/DrawableItem.h"
#define DEBUG

typedef unsigned int uint;

class Label : public DrawableItem
{
public:
	Label(std::string text, IPositionable* parent);
	~Label() {}

	void setTextureForString(std::string label);
	void SetTextColour(SDL_Color color);

protected:
	std::string labelText;
	SDL_Color foregroundColor;

	void updateText();
};

