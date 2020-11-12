#include "Scene.h"
#include <xml_parser/XMLParser.h>
#include <game/game.h>

Scene::Scene(XMLParser::SceneInfo sI) : bgSurface(createBackgroundSurface()), sceneInfo(sI){
	if (loadBMPBackgroundSurface(sI.bgSurfaceFilePath, sI.parentSurface) && loadBgMusic(sI.musicFilePath)) {
		Mix_PlayMusic(music, -1);
	}
}

void Scene::startCycle(Presenter* presenterPtr, int logicInterval, int screenInterval) {
	presenter = presenterPtr;
	logicID = SDL_AddTimer(logicInterval, &Scene::logicCallback, this);
	logicCycleDown = false;
	screenID = SDL_AddTimer(screenInterval, &Scene::screenCallback, this);
	screenCycleDown = false;
}

Scene::~Scene() {
	if(bgSurfaceIsLoaded()) SDL_FreeSurface(bgSurface);
	if(musicIsLoaded()) Mix_FreeMusic(music);
}

bool Scene::loadBMPBackgroundSurface(std::string bgFilePath, SDL_Surface* refSurface)
{
	SDL_Surface* bmpSurface = loadAndConvertSurface(SDL_LoadBMP(bgFilePath.c_str()), refSurface);
	if (bmpSurface == nullptr) { return false; }
	fillBackgroundSurface(bmpSurface);
	SDL_FreeSurface(bmpSurface);
	return true;
}

bool Scene::loadBgMusic(std::string musicFilePath)
{
	music = Mix_LoadMUS("./resources/music.wav");
	return (music != nullptr);
}

bool Scene::bothCyclesDown()
{
	return (logicCycleDown && screenCycleDown);
}

SDL_Surface* Scene::loadAndConvertSurface(SDL_Surface* baseSurface, SDL_Surface* refSurface) {
	if (baseSurface == nullptr) { return nullptr; }
	SDL_Surface* convertedSurface = SDL_ConvertSurface(baseSurface, refSurface->format, 0);
	SDL_FreeSurface(baseSurface);
	return convertedSurface;
}

void Scene::fillBackgroundSurface(SDL_Surface* srcSurface)
{
	SDL_Rect srcRect{ 0, 0, srcSurface->w, srcSurface->h }, destRect{ 0, 0, bgSurface->w, bgSurface->h };
	while (destRect.x < destRect.w) {
		if (destRect.x + srcRect.w > destRect.w) { srcRect.w = destRect.w - destRect.x; }
		while (destRect.y < destRect.h) {
			if (destRect.y + srcRect.h > destRect.h) { srcRect.h = destRect.h - destRect.y; }
			SDL_BlitSurface(srcSurface, &srcRect, bgSurface, &destRect);	//BlitSurface piše u SDL_Rect, može li se ljepše?
			destRect.w = bgSurface->w;	
			destRect.h = bgSurface->h;
			destRect.y += srcRect.h;
		}
		destRect.y = 0;
		srcRect.h = srcSurface->h;
		destRect.x += srcRect.w;
	}
}

SDL_Surface* Scene::createBackgroundSurface()
{
		#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		Uint32 rmask = 0xff000000;
		Uint32 gmask = 0x00ff0000;
		Uint32 bmask = 0x0000ff00;
		Uint32 amask = 0x000000ff;
		#else
		Uint32 rmask = 0x000000ff;
		Uint32 gmask = 0x0000ff00;
		Uint32 bmask = 0x00ff0000;
		Uint32 amask = 0xff000000;
		#endif
		return SDL_CreateRGBSurface(0, Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT, 32, rmask, gmask, bmask, amask);
}

void Scene::onSceneOver()
{
	if (bothCyclesDown()) { presenter->sceneOver(); }
}

