#include "Circle.h"

Circle::Circle(ObjectInfo oI) : ShapedObject(oI)
{
	radius = getSurface()->w / 2;
	drawRect = SDL_Rect{ centre.x, centre.y,getSurface()->w, getSurface()->h };
}

void Circle::blitElement(SDL_Surface* parentSurface)
{
	setDrawRect(parentSurface);
	drawRect.w = parentSurface->w;
	drawRect.h = parentSurface->h;
	SDL_BlitSurface(getSurface(), NULL, parentSurface, &drawRect);
}

void Circle::setDrawRect(SDL_Surface* parentSurface)
{
	drawRect.x = centre.x - radius;
	drawRect.y = centre.y - radius;
	drawRect.w = parentSurface->w;
	drawRect.h = parentSurface->h;
}
