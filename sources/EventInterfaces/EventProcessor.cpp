#include "EventProcessor.h"
#include <algorithm>

void EventProcessor::OnWindowAreaChange()
{
	for (auto item : vectorOfPositionableItems)
	{
		item->OnWindowAreaChange();
	}
}

void EventProcessor::DrawTo(SDL_Renderer* renderer)
{
	for (auto item : vectorOfDrawableItems)
	{
		item->DrawTo(renderer);
	}
}

void EventProcessor::Update(std::chrono::steady_clock::duration elapsed)
{
	for (auto item : vectorOfUpdatableItems)
	{
		item->Update(elapsed);
	}
}

void EventProcessor::mouseHover(SDL_MouseMotionEvent motionEvent)
{
	auto point = SDL_Point{ motionEvent.x, motionEvent.y };
	if (isPointInside(&point))
	{
		for (auto item : vectorOfMouseEventItems)
		{
			item->mouseHover(motionEvent);
		}
	}
	else
	{
		mouseOutsideHover(motionEvent);
	}
}

void EventProcessor::mouseClick(SDL_MouseButtonEvent buttonEvent)
{
	auto point = SDL_Point{ buttonEvent.x, buttonEvent.y };
	if (isPointInside(&point))
	{
		for (auto item : vectorOfMouseEventItems)
		{
			item->mouseClick(buttonEvent);
		}
	}
	else
	{
		mouseOutsideClick(buttonEvent);
	}
}

void EventProcessor::mouseOutsideHover(SDL_MouseMotionEvent motionEvent)
{
	for (auto item : vectorOfMouseEventItems)
	{
		item->mouseOutsideHover(motionEvent);
	}
}

void EventProcessor::mouseOutsideClick(SDL_MouseButtonEvent buttonEvent)
{
	for (auto item : vectorOfMouseEventItems)
	{
		item->mouseOutsideClick(buttonEvent);
	}
}

void EventProcessor::onKeyPress(SDL_KeyboardEvent keyboardEvent)
{
	for (auto item : vectorOfKeyboardEventItems)
	{
		item->onKeyPress(keyboardEvent);
	}
}

void EventProcessor::addPositionableItem(IPositionable* item, int position)
{
	position = (position >= 0) ? position : vectorOfPositionableItems.size();
	vectorOfPositionableItems.insert(vectorOfPositionableItems.begin() + position, item);
}

void EventProcessor::addDrawableItem(IDrawable* item, int position)
{
	position = (position >= 0) ? position : vectorOfDrawableItems.size();
	vectorOfDrawableItems.insert(vectorOfDrawableItems.begin() + position,item);
}

void EventProcessor::removePositionableItem(IPositionable* item)
{
	vectorOfPositionableItems.erase(std::remove(vectorOfPositionableItems.begin(), vectorOfPositionableItems.end(), item), vectorOfPositionableItems.end());
}

void EventProcessor::removeDrawableItem(IDrawable* item)
{
	vectorOfDrawableItems.erase(std::remove(vectorOfDrawableItems.begin(), vectorOfDrawableItems.end(), item), vectorOfDrawableItems.end());
}

void EventProcessor::addUpdatableItem(IUpdatable* item, int position)
{
	position = (position >= 0) ? position : vectorOfUpdatableItems.size();
	vectorOfUpdatableItems.insert(vectorOfUpdatableItems.begin() + position, item);
}

void EventProcessor::removeUpdatableItem(IUpdatable* item)
{
	vectorOfUpdatableItems.erase(std::remove(vectorOfUpdatableItems.begin(), vectorOfUpdatableItems.end(), item), vectorOfUpdatableItems.end());
}

void EventProcessor::addMouseEventsItem(IMouseEvents* item, int position)
{
	position = (position >= 0) ? position : vectorOfMouseEventItems.size();
	vectorOfMouseEventItems.insert(vectorOfMouseEventItems.begin() + position, item);
}

void EventProcessor::removeMouseEventsItem(IMouseEvents* item)
{
	vectorOfMouseEventItems.erase(std::remove(vectorOfMouseEventItems.begin(), vectorOfMouseEventItems.end(), item), vectorOfMouseEventItems.end());
}

void EventProcessor::addKeyboardEventsItem(IKeyboardEvents* item, int position)
{
	position = (position >= 0) ? position : vectorOfKeyboardEventItems.size();
	vectorOfKeyboardEventItems.insert(vectorOfKeyboardEventItems.begin() + position, item);
}

void EventProcessor::removeKeyboardEventsItem(IKeyboardEvents* item)
{
	vectorOfKeyboardEventItems.erase(std::remove(vectorOfKeyboardEventItems.begin(), vectorOfKeyboardEventItems.end(), item), vectorOfKeyboardEventItems.end());
}