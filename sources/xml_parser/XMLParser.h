#pragma once
#include <tinyxml2.h>
#include <string>
#include <vector>

class SDL_Surface;

class XMLParser {
public:
	struct SceneInfo {
		std::string sceneFile;
		std::string bgSurfaceFilePath;
		std::string musicFilePath;
		SDL_Surface* parentSurface = nullptr;
	};

	struct GameInfo {
		std::vector<std::string> levelNames;
		std::string rootOfFiles = "";
	};

	struct LevelInfo {
		SceneInfo sI;
		std::string levelInfoFile = "";
	};

	static SceneInfo getSceneInfoFrom(std::string fileLocation, SDL_Surface* parentSurface);
	static GameInfo getGameInfoFrom(std::string fileLocation);
	static LevelInfo getLevelInfoFrom(std::string fileLocation);

private:
	static std::string cleanString(const char* string);
	static const tinyxml2::XMLElement* getLevelElement(std::string fileLocation);
	static std::vector<std::string> getVectorOfLevelNames(const char* string);
};

