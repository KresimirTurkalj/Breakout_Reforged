#pragma once
#include <SDL.h>
#include "Label.h"
#include "../EventInterfaces/IKeyboardEvents.h"
#define DEBUG

typedef unsigned int uint;

class KeyShower : public Label, public IKeyboardEvents
{
public:
	KeyShower(IPositionable* parent);
	~KeyShower() {}

	// Inherited via IKeyboardEvents
	virtual void onKeyPress(SDL_KeyboardEvent keyboardEvent) override;
};

