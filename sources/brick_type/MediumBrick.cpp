#include "MediumBrick.h"

void MediumBrick::onHitRegistered()
{
	if (isBroken()) {
		onBrickDestroyed();
	}
	else {
		changeSurface(brokenSurfaceFile);
	}
}

bool MediumBrick::isBroken()
{
	return lifeCount == 0;
}
