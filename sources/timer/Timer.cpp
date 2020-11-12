#include "Timer.h"

Uint32 Timer::MillisPassed() {
	Uint32 timePassed = SDL_GetTicks() - lastMeasuredTime;
	lastMeasuredTime = SDL_GetTicks();
	return timePassed;
}

Uint32 Timer::timeSinceStart() {
	return SDL_GetTicks();
}
