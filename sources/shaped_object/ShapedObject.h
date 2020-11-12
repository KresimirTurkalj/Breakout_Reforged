#pragma once
#include "interfaces\IDrawable.h"
#include <string>
#include <SDL.h>

class ShapedObject : public IDrawable {
public:
	struct Point {
		int x;
		int y;
	};
	struct ObjectInfo {
		Point centre;
		std::string fileLocation;
	};

	ShapedObject(ObjectInfo oI) : surface(SDL_LoadBMP(oI.fileLocation.c_str())), centre(oI.centre) {}
	~ShapedObject() { SDL_FreeSurface(surface); }
protected:
	Point centre;
	bool isSurfaceLoaded() { return surface != nullptr; }
	void changeSurface(std::string fileLocation);
	SDL_Surface* getSurface() { return surface; }
private:
	SDL_Surface* surface = nullptr;

	ShapedObject();
};

