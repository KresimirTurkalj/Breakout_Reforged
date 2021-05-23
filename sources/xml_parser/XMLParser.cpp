#include "XMLParser.h"
#include <vector>

using namespace tinyxml2;
XMLParser::SceneInfo XMLParser::getSceneInfoFrom(std::string fileLocation, SDL_Surface* parentSurface) {
	SceneInfo sceneInfo;
	XMLDocument doc;
	if (doc.LoadFile(fileLocation.c_str()) == XML_SUCCESS) {
		const XMLElement* sceneElement = doc.FirstChildElement("Scene");
		if (sceneElement != nullptr) {
			const XMLAttribute* firstAttr = sceneElement->FindAttribute("SceneDoc");
			const XMLAttribute* secondAttr = sceneElement->FindAttribute("BackgroundTexture");
			const XMLAttribute* thirdAttr = sceneElement->FindAttribute("BackgroundMusic");
			sceneInfo = SceneInfo{ firstAttr->Value(), secondAttr->Value(), thirdAttr->Value(), parentSurface };
		}
	}
	return sceneInfo;
}

XMLParser::GameInfo XMLParser::getGameInfoFrom(std::string fileLocation) {
	GameInfo gI;
	XMLDocument doc;
	if (doc.LoadFile(fileLocation.c_str()) == XML_SUCCESS) {
		XMLElement* gameElement = doc.FirstChildElement("Game");
		if (gameElement != nullptr) {
			gI.rootOfFiles = gameElement->FindAttribute("rootOfLevelFile")->Value();
			const XMLNode* levelNamesNode = gameElement->FirstChildElement("Scenes")->FirstChild();
			gI.levelNames = (getVectorOfLevelNames(levelNamesNode->Value()));
		}
	}
	return gI;
}

XMLParser::LevelInfo XMLParser::getLevelInfoFrom(std::string fileLocation)
{
	return LevelInfo();
}

std::string XMLParser::cleanString(const char* string)
{
	std::string stringOfNames(string);
	stringOfNames.erase(remove(stringOfNames.begin(), stringOfNames.end(), '\t'), stringOfNames.end());
	stringOfNames.erase(remove(stringOfNames.begin(), stringOfNames.end(), '\n'), stringOfNames.end());
	return stringOfNames;
}

const tinyxml2::XMLElement* XMLParser::getLevelElement(std::string fileLocation)
{
	return nullptr;
}

std::vector<std::string> XMLParser::getVectorOfLevelNames(const char* string)
{
	//using namespace boost::algorithm;
	std::string stringOfNames(string);
	std::vector<std::string> stringVector;
	//split(stringVector, stringOfNames, is_any_of("\t\n ,"));
	stringVector.erase(remove(stringVector.begin(), stringVector.end(), ""), stringVector.end());
	return stringVector;
}