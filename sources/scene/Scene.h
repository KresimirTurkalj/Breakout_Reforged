#pragma once
#include <interfaces\IPresentable.h>
#include <string>
#include <SDL_Mixer.h>
#include <xml_parser\XMLParser.h>

class Scene : public IPresentable {
public:
	Scene(XMLParser::SceneInfo sI);
	bool sceneIsLoaded() { return bgSurfaceIsLoaded() && musicIsLoaded(); }
	virtual void startCycle(Presenter* presenter, int logicInterval, int screenInterval) override;
	virtual ~Scene();
protected:
	SDL_TimerID logicID;
	SDL_TimerID screenID;
	bool logicCycleDown = true;
	bool screenCycleDown = true;
	Presenter* presenter;

	const XMLParser::SceneInfo& getSceneInfo() { return sceneInfo; }
private:
	XMLParser::SceneInfo sceneInfo;
	SDL_Surface* bgSurface = nullptr;
	Mix_Music* music = nullptr;

	Scene();
	bool loadBMPBackgroundSurface(std::string bgFilePath, SDL_Surface* refSurface);
	bool loadBgMusic(std::string musicFilePath);
	bool bgSurfaceIsLoaded() { return bgSurface != nullptr; }
	bool musicIsLoaded() { return music != nullptr; }
	bool bothCyclesDown();
	SDL_Surface* loadAndConvertSurface(SDL_Surface* baseSurface, SDL_Surface* refSurface);
	void fillBackgroundSurface(SDL_Surface* srcSurface);
	SDL_Surface* createBackgroundSurface();

	virtual void onSceneOver() override;
};

