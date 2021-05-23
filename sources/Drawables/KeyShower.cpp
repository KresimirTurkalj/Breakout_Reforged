#include "KeyShower.h"

KeyShower::KeyShower(IPositionable* parent) : Label("", parent)
{
}

void KeyShower::onKeyPress(SDL_KeyboardEvent keyboardEvent)
{
	setTextureForString(std::string(1, static_cast<char>(keyboardEvent.keysym.scancode + 61)));
}
