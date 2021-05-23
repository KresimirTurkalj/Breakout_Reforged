#include "FPSCounter.h"

FPSCounter::FPSCounter(IPositionable* parent) : Label("", parent), frameCount(0), timePassed(std::chrono::duration<int>(0))
{

}

void FPSCounter::onFrameUpdate()
{
	frameCount++;
}

void FPSCounter::Update(std::chrono::steady_clock::duration elapsed)
{
	timePassed += elapsed;
	setTextureForString(std::to_string(1000000.0 * frameCount / std::chrono::duration_cast<std::chrono::microseconds>(timePassed).count()));
}
