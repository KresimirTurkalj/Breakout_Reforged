#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle(ObjectInfo oI) : ShapedObject(oI){
	height = getSurface()->w / 2;
	width = getSurface()->h / 2;
	drawRect = SDL_Rect{centre.x, centre.y, height, width};
}

void Rectangle::blitElement(SDL_Surface* parentSurface){
	drawRect.w = parentSurface->w;
	drawRect.h = parentSurface->h;
	SDL_BlitSurface(getSurface(), NULL, parentSurface, &drawRect);
}

ShapedObject::Point Rectangle::pointOfCollision(Point centre, double radius, Point vectorOfVeloc)
{
	Point nextCentre = Point{ centre.x + vectorOfVeloc.x, centre.y + vectorOfVeloc.y };
	if (!isCircleColliding(nextCentre, radius)) { return nextCentre; }
	else {
		
	}
}

bool Rectangle::isCircleColliding(Point point, double radius)
{
	Point cPoint = findClosestPoint(point);
	return (isClosestPointWithinRadius(cPoint, point, radius) || isInsideRectangle(cPoint, point));
}

void Rectangle::adjustDrawRect(SDL_Surface* parentSurface) {
	drawRect.w = getSurface()->w;
	drawRect.h = getSurface()->h;
}

ShapedObject::Point Rectangle::findClosestPoint(Point point) {
	Point cPoint;
	Sign x = (centre.x < point.x) ? plus : minus;
	Sign y = (centre.y < point.y) ? plus : minus;
	Point corner = getCornerPoint(x, y);
	if ((centre.x < point.x) == (corner.x <= point.x)) { cPoint.x = corner.x; }
	else { cPoint.x = point.x; }
	if ((centre.y < point.y) == (corner.y <= point.y)) { cPoint.y = corner.y; }
	else { cPoint.y = point.y; }
	return cPoint;
}

ShapedObject::Point Rectangle::getCornerPoint(Sign x, Sign y) {
	return Point{ centre.x + x * width / 2, centre.y + y * height / 2 };
}

bool Rectangle::isInsideRectangle(Point cPoint, Point point) {
	return ((centre.x < point.x) != (cPoint.x < point.x) && ((centre.y < point.y) != (cPoint.y < point.y)));
}

bool Rectangle::isClosestPointWithinRadius(Point cPoint, Point point, double radius) {
	return radius >= sqrt(pow(cPoint.x - point.x, 2) + pow(cPoint.y - point.y, 2));
}
