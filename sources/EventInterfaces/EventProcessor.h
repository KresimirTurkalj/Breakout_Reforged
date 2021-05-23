#pragma once
#include "IPositionable.h"
#include "IDrawable.h"
#include "IMouseEvents.h"
#include "IUpdatable.h"
#include "IKeyboardEvents.h"
#include <vector>
#include <memory>

class EventProcessor : public IPositionable, public IDrawable, public IUpdatable, public IMouseEvents, public IKeyboardEvents
{
public:
	EventProcessor(IPositionable* parent) : IPositionable(parent){}
	virtual ~EventProcessor() {}
	// Inherited via IPositionable
	virtual void OnWindowAreaChange() override;
	// Inherited via IDrawable
	virtual void DrawTo(SDL_Renderer* renderer) override;
	// Inherited via IUpdatable
	virtual void Update(std::chrono::steady_clock::duration elapsed) override;
	// Inherited via IMouseEvents
	virtual void mouseHover(SDL_MouseMotionEvent motionEvent) override;
	virtual void mouseClick(SDL_MouseButtonEvent buttonEvent) override;
	virtual void mouseOutsideHover(SDL_MouseMotionEvent motionEvent) override;
	virtual void mouseOutsideClick(SDL_MouseButtonEvent buttonEvent) override;
	// Inherited via IKeyboardEvents
	virtual void onKeyPress(SDL_KeyboardEvent keyboardEvent) override;

protected:
	std::vector<IPositionable*> vectorOfPositionableItems;
	std::vector<IDrawable*> vectorOfDrawableItems;
	std::vector<IUpdatable*> vectorOfUpdatableItems;
	std::vector<IMouseEvents*> vectorOfMouseEventItems;
	std::vector<IKeyboardEvents*> vectorOfKeyboardEventItems;

	virtual void addPositionableItem(IPositionable* item, int position = -1);
	virtual void addDrawableItem(IDrawable* item, int position = -1);
	virtual void addUpdatableItem(IUpdatable* item, int position = -1);
	virtual void addMouseEventsItem(IMouseEvents* item, int position = -1);
	virtual void addKeyboardEventsItem(IKeyboardEvents* item, int position = -1);

	virtual void removePositionableItem(IPositionable* item);
	virtual void removeDrawableItem(IDrawable* item);
	virtual void removeUpdatableItem(IUpdatable* item);
	virtual void removeMouseEventsItem(IMouseEvents* item);
	virtual void removeKeyboardEventsItem(IKeyboardEvents* item);
};