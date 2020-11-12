#pragma once
#include <scene/Scene.h>
#include <interfaces\IMovable.h>
#include <shaped_object\ShapedObject.h>
#include <vector>
#include <xml_parser\XMLParser.h>

class Level : public Scene{
public:
	Level(XMLParser::SceneInfo sI);
	~Level();
private:
	std::vector<IMovable*> vectorOfMovables;
	std::vector<Rectangle*> vectorOfCollidables;
	std::vector<ShapedObject*> vectorOfObjects;

	virtual Uint32 updateForInterval(Uint32 interval) override;
	virtual Uint32 updateScreen(Uint32 interval) override;
};

