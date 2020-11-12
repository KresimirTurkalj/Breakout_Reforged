#include "HardBrick.h"

void HardBrick::onHitRegistered() {
	if (isBroken()) {
		onBrickDestroyed();
	}
	else if(isBraking()){
		changeSurface(brokenSurfaceFile);
	}
	else {
		changeSurface(crackedSurfaceFile);
	}
}

bool HardBrick::isBroken()
{
	return lifeCount == 0;
}

bool HardBrick::isBraking()
{
	return lifeCount == 1;
}
