#include "Window.h"
#include <iostream>

Window::Window(std::string windowName, SDL_Rect windowRectangle) : EventProcessor(nullptr), windowHolder(SDL_CreateWindow(windowName.c_str(), windowRectangle.x, windowRectangle.y, windowRectangle.w, windowRectangle.h, SDL_WINDOW_SHOWN))
{
	if (windowHolder == NULL)
	{
	#ifdef DEBUG
		std::cout << "Creating window failed: " << SDL_GetError() << std::endl;
	#endif // DEBUG
	}
	else
	{
		renderer = std::make_unique<Renderer>(windowHolder);
		SetPosition(SDL_Point{ 0,0 });
		SetSize(SDL_Point{ windowRectangle.w, windowRectangle.h });
	}
}

void Window::UpdateScreenWindow()
{
	renderer->clearScreen();
	DrawTo(renderer->getRenderer());
	renderer->updateScreen();
}

bool Window::frameTimePassed()
{
	return frameTime < timePassed;
}

SDL_Renderer* Window::getWindowRenderer()
{
	return renderer->getRenderer();
}

void Window::addPositionableItem(IPositionable* item, int position)
{
	EventProcessor::addPositionableItem(item, position);
	item->OnWindowAreaChange();
}

void Window::Update(std::chrono::steady_clock::duration elapsed)
{
	EventProcessor::Update(elapsed);
	timePassed += elapsed;
	if (frameTimePassed())
	{
		timePassed = std::chrono::duration<int>(0);
		UpdateScreenWindow();
	}
}
