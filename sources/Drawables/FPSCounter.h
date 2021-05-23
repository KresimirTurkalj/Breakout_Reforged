#pragma once
#include "Label.h"
#include "../EventInterfaces/IUpdatable.h"
#define DEBUG

class FPSCounter : public Label, public IUpdatable
{
public:
	FPSCounter(IPositionable* parent);
	~FPSCounter() {}
	void onFrameUpdate();
	// Inherited via IUpdatable
	virtual void Update(std::chrono::steady_clock::duration elapsed) override;

private:
	std::chrono::steady_clock::duration timePassed;
	unsigned long frameCount;
};

