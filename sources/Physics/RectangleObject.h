#pragma once
#include "Object2D.h"

class RectangleObject : public Object2D
{
public:
	RectangleObject(RectangleInfo rectangleInfo);
	virtual ~RectangleObject() {}
};