#include "Level.h"

Level::Level(XMLParser::SceneInfo sI) : Scene(sI) {
	//Napuni vektore
}

Level::~Level() {
	vectorOfMovables.clear();
	vectorOfObjects.clear();
}

Uint32 Level::updateForInterval(Uint32 interval) {
	//Logika u Ball dodati
	for (int i = 0; i < vectorOfMovables.size(); i++) {
		vectorOfMovables[i]->updateState(vectorOfCollidables);
	}
	return interval;
}

Uint32 Level::updateScreen(Uint32 interval) {
	for (int i = 0; i < vectorOfObjects.size(); i++) {
		vectorOfObjects[i]->blitElement(getSceneInfo().parentSurface);
	}
	return interval;
}
