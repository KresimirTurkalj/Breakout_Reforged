#pragma once
#include "BrickEnforcement.h"
class HardBrick : public BrickEnforcement {
public:
	HardBrick(BrickInfo bI, std::string brokenSurface, std::string crackedSurface) : 
		BrickEnforcement(bI),crackedSurfaceFile(crackedSurface), brokenSurfaceFile(brokenSurface) {}
	virtual void onHitRegistered() override;
private:
	std::string crackedSurfaceFile;
	std::string brokenSurfaceFile;
	int lifeCount = 3;

	HardBrick();
	bool isBroken();
	bool isBraking();
};

