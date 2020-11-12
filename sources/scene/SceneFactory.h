#pragma once
#include <string>

class IPresentable;
class SDL_Surface;

class SceneFactory
{
public:
	static IPresentable* getScene(std::string sceneFilePath, SDL_Surface* parentSurface);
private:
	static const std::string menu;
	static const std::string level;
};

