#pragma once
#include "../Rudimentary/DrawableItem.h"

class Background : public DrawableItem 
{
public:
	Background(std::string filePath, IPositionable* parent);
	~Background() {}
	virtual void DrawTo(SDL_Renderer* renderer) override;
};

