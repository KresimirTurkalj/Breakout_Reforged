#pragma once
#include "Renderer.h"
#include "../EventInterfaces/EventProcessor.h"
#include <memory>

class Window : public EventProcessor
{
public:
	Window(std::string windowName, SDL_Rect windowRectangle);
	virtual ~Window() {}

	SDL_Renderer* getWindowRenderer();
	virtual void addPositionableItem(IPositionable* item, int position = -1) override;
	virtual void Update(std::chrono::steady_clock::duration elapsed) override;
protected:
	std::chrono::steady_clock::duration timePassed;
	std::chrono::duration<double, std::milli> const frameTime = std::chrono::duration<double, std::milli>(16.67);
	std::shared_ptr<Renderer> renderer;
	SDL_Window* windowHolder;

	virtual void UpdateScreenWindow();
	virtual bool frameTimePassed();
};