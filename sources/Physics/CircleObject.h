#pragma once
#include "Object2D.h"

class CircleObject : public Object2D
{
public:
	CircleObject(CircleInfo circleInfo);
	virtual ~CircleObject() {}
};