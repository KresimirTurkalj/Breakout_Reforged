#pragma once
#include "../EventInterfaces/IMouseEvents.h"
#include "DrawableItem.h"
#include <vector>
#include <functional>
#define DEBUG

typedef unsigned int uint;

class ClickableItem : public DrawableItem, public IMouseEvents
{
public:
	ClickableItem(IPositionable* parent);
	virtual ~ClickableItem() {}

	// Inherited via IMouseEvents
	virtual void mouseHover(SDL_MouseMotionEvent motionEvent) override;
	virtual void mouseClick(SDL_MouseButtonEvent buttonEvent) override;
	virtual void mouseOutsideHover(SDL_MouseMotionEvent motionEvent) override;
	virtual void mouseOutsideClick(SDL_MouseButtonEvent buttonEvent) override;

	void addOnHoverLambda(std::function<void(SDL_MouseMotionEvent motionEvent)> lambda);
	void addOnClickLambda(std::function<void(SDL_MouseButtonEvent buttonEvent)> lambda);
	void addOnOutsideHoverLambda(std::function<void(SDL_MouseMotionEvent motionEvent)> lambda);
	void addOnOutsideClickLambda(std::function<void(SDL_MouseButtonEvent buttonEvent)> lambda);
protected:
	std::vector<std::function<void(SDL_MouseMotionEvent motionEvent)>> vectorOfOnHoverLambdas;
	std::vector<std::function<void(SDL_MouseButtonEvent buttonEvent)>> vectorOfOnClickLambdas;
	std::vector<std::function<void(SDL_MouseMotionEvent motionEvent)>> vectorOfOnOutsideHoverLambdas;
	std::vector<std::function<void(SDL_MouseButtonEvent buttonEvent)>> vectorOfOnOutsideClickLambdas;
};

