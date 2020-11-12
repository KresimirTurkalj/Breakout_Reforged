#pragma once
#include "BrickEnforcement.h"
class InvicibleBrick : public BrickEnforcement {
public:
	InvicibleBrick(BrickInfo bI) : BrickEnforcement(bI) {}
	virtual void onHitRegistered() override;
};

