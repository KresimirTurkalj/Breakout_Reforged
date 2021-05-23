#pragma once
#include "Object2D.h"
#include <deque>

class Physics2D
{
public:
	static void MoveObjects(std::chrono::steady_clock::duration timeLeft);
	static void addObject(Object2D* object);
protected:
	struct CollisionInfo
	{
		std::deque<std::pair<Object2D*, Object2D*>> dequeOfPairs;
		std::chrono::steady_clock::duration timeTo;
	};
	static bool isObjectMoving(Object2D* object);
	static CollisionInfo timeToChange(Object2D* firstObject, Object2D* secondObject, std::chrono::steady_clock::duration timeLeft);
	static void elasticCollisionBetween(CollisionInfo collisionInfo);

	static std::deque<Object2D*> dequeOfObjects;
};