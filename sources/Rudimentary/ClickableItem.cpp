#include "ClickableItem.h"

ClickableItem::ClickableItem(IPositionable* parent) : DrawableItem(parent)
{

}

void ClickableItem::mouseHover(SDL_MouseMotionEvent motionEvent)
{
	auto point = SDL_Point{ motionEvent.x, motionEvent.y };
	if (isPointInside(&point)) 
	{
		for (auto lambda : vectorOfOnHoverLambdas)
		{
			lambda(motionEvent);
		}
	}
	else
	{
		mouseOutsideHover(motionEvent);
	}
}

void ClickableItem::mouseClick(SDL_MouseButtonEvent buttonEvent)
{
	auto point = SDL_Point{ buttonEvent.x, buttonEvent.y };
	if (isPointInside(&point))
	{
		for (auto lambda : vectorOfOnClickLambdas)
		{
			lambda(buttonEvent);
		}
	}
	else
	{
		mouseOutsideClick(buttonEvent);
	}
}

void ClickableItem::mouseOutsideHover(SDL_MouseMotionEvent motionEvent)
{
	for (auto lambda : vectorOfOnOutsideHoverLambdas)
	{
		lambda(motionEvent);
	}
}

void ClickableItem::mouseOutsideClick(SDL_MouseButtonEvent buttonEvent)
{
	for (auto lambda : vectorOfOnOutsideClickLambdas)
	{
		lambda(buttonEvent);
	}
}

void ClickableItem::addOnHoverLambda(std::function<void(SDL_MouseMotionEvent buttonEvent)> lambda)
{
	vectorOfOnHoverLambdas.push_back(lambda);
}

void ClickableItem::addOnClickLambda(std::function<void(SDL_MouseButtonEvent buttonEvent)> lambda)
{
	vectorOfOnClickLambdas.push_back(lambda);
}

void ClickableItem::addOnOutsideHoverLambda(std::function<void(SDL_MouseMotionEvent buttonEvent)> lambda)
{
	vectorOfOnOutsideHoverLambdas.push_back(lambda);
}

void ClickableItem::addOnOutsideClickLambda(std::function<void(SDL_MouseButtonEvent buttonEvent)> lambda)
{
	vectorOfOnOutsideClickLambdas.push_back(lambda);
}
