#pragma once
#include <SDL_rect.h>
#include <chrono>

class IUpdatable {
public:
	virtual ~IUpdatable(){}

	virtual void Update(std::chrono::steady_clock::duration elapsed) = 0;
};