#pragma once
#include <SDL.h>
#include <interfaces\IPresentable.h>
#include <scene\Scene.h>
#include <string>

class Menu : public Scene {
public:
	Menu(XMLParser::SceneInfo sI);
	virtual ~Menu();
	virtual Uint32 updateForInterval(Uint32 interval) override;
	virtual Uint32 updateScreen(Uint32 interval) override;
};