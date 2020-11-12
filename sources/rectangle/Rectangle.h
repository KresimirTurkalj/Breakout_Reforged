#pragma once
#include "shaped_object\ShapedObject.h"
/*Bolje sredi Point da je klasa, lakse odrediti tocke gdje se sjece i slicno*/
class Rectangle : public ShapedObject {
public:
	Rectangle(ObjectInfo oI);
	virtual void blitElement(SDL_Surface* parentSurface) override;
	virtual Point pointOfCollision(Point centre, double radius, Point vectorOfVeloc);
	virtual bool isCircleColliding(Point point, double radius);
private:
	int width;
	int height;
	enum Sign {minus = -1, plus = 1};

	void adjustDrawRect(SDL_Surface* parentSurface);
	Point findClosestPoint(Point point);
	Point getCornerPoint(Sign x, Sign y);
	bool isInsideRectangle(Point cPoint, Point point);
	bool isClosestPointWithinRadius(Point cPoint, Point point, double radius);
	SDL_Rect drawRect;
	Rectangle();
};

