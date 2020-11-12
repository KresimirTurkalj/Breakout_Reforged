#include "ShapedObject.h"

void ShapedObject::changeSurface(std::string fileLocation)
{
	SDL_FreeSurface(surface);
	SDL_LoadBMP(fileLocation.c_str());
}
