#pragma once
#include <SDL.h>
#include <chrono>

enum class ObjectType
{
	Rectangle,
	Circle,
	Unknown
};

struct RectangleInfo
{
	ObjectType type;
	SDL_Point centerPosition;
	SDL_Point velocity;
	Uint8 width;
	Uint8 height;
};

struct CircleInfo
{
	ObjectType type;
	SDL_Point centerPosition;
	SDL_Point velocity;
	Uint8 radius;
};

union ObjectInfo
{
	ObjectType type;
	SDL_Point centerPosition;
	SDL_Point velocity;
	RectangleInfo rectangleInfo;
	CircleInfo circleInfo;
};

class Object2D
{
public:
	Object2D();
	Object2D(ObjectInfo objectInfo);
	virtual ~Object2D() {}

	ObjectInfo& getObjectInfo();
	void moveObject(std::chrono::steady_clock::duration forTime, Object2D* collidingObject = nullptr);

protected:
	ObjectInfo objectInfo;
};