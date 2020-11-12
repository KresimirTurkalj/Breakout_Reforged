#pragma once
#include "shaped_object\ShapedObject.h"

class Circle : public ShapedObject{
public:
	Circle(ObjectInfo oI);
	virtual void blitElement(SDL_Surface* parentSurface) override;
protected:
	int radius;
private:
	SDL_Rect drawRect;

	void setDrawRect(SDL_Surface* parentSurface);
	Circle();
};

