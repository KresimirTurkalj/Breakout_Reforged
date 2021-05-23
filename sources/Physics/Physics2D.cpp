#include "Physics2D.h"

bool operator==(const SDL_Point& lhs, const SDL_Point& rhs) { return(lhs.x == rhs.x && lhs.y == rhs.y); }
bool operator!=(const SDL_Point& lhs, const SDL_Point& rhs) { return !(lhs == rhs); }

void Physics2D::MoveObjects(std::chrono::steady_clock::duration timeLeft)
{
	MovementInfo tempInfo, info{ std::deque<std::pair<Object2D*, Object2D*>>(), timeLeft };
	for (int i = 0; i < dequeOfObjects.size(); i++)	//Issue of object colliding with multiple objects at once
	{
		for (int j = i + 1; j < dequeOfObjects.size(); j++)
		{
			if (!isObjectMoving(dequeOfObjects[i]))
			{
				tempInfo = timeToChange(dequeOfObjects[i], dequeOfObjects[j], timeLeft);
				info.dequeOfPairs.push_back(tempInfo.dequeOfPairs.back());
				if (tempInfo.timeTo < info.timeTo)
				{
					info.timeTo = tempInfo.timeTo;
				}
			}
		}
	}
	for (auto object : dequeOfObjects)
	{

	}
}

void Physics2D::addObject(Object2D* object)
{
	if (isObjectMoving(object)) dequeOfObjects.push_front(object);
	else { dequeOfObjects.push_back(object); }
}

bool Physics2D::isObjectMoving(Object2D* object)
{
	return (object->getObjectInfo().velocity != SDL_Point{0,0});
}

Physics2D::MovementInfo Physics2D::timeToChange(Object2D* firstObject, Object2D* secondObject, std::chrono::steady_clock::duration timeLeft)
{
	return MovementInfo{firstObject, secondObject};
}

void Physics2D::elasticCollisionBetween(MovementInfo collisionInfo)
{

}
