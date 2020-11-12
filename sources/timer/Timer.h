#pragma once
#include <SDL.h>

class Timer {
public:
	static Uint32 timeSinceStart();
	Uint32 MillisPassed();
private:
	Uint32 lastMeasuredTime = 0;
};

