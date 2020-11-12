#pragma once
#include "BrickEnforcement.h"
class MediumBrick : public BrickEnforcement{
public:
	MediumBrick(BrickInfo bI, std::string brokenSurface) : BrickEnforcement(bI), brokenSurfaceFile(brokenSurface) {}
	virtual void onHitRegistered() override;
private:
	std::string brokenSurfaceFile;
	int lifeCount = 2;

	MediumBrick();
	bool isBroken();
};

