#include "SceneFactory.h"
#include <xml_parser/XMLParser.h>
#include <menu/Menu.h>
#include <level/Level.h>

const std::string SceneFactory::level = "level.xml";
const std::string SceneFactory::menu = "menu.xml";

IPresentable* SceneFactory::getScene(std::string sceneFilePath, SDL_Surface* parentSurface) {
	XMLParser::SceneInfo sceneInfo = XMLParser::getSceneInfoFrom(sceneFilePath, parentSurface);
	if (sceneInfo.sceneFile == menu) {
		return new Menu(sceneInfo);
	}
	if (sceneInfo.sceneFile == level) {
		return new Level(sceneInfo);
	}
	return nullptr;
}
