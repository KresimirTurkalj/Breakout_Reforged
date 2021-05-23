#include "SDLInit.h"
#define DEBUG

bool SDL::initialise()
{
	if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0)
	{
	#ifdef DEBUG
		std::cout << "SDL_Init() failed:\t" << SDL_GetError() << std::endl;
	#endif // DEBUG
		return false;
	}
	else
	{
		if (!SDLgraphics::initialise(IMG_INIT_PNG) || !SDLtext::initialise())
		{
		#ifdef DEBUG
			std::cout << "Module initialisation() failed.\t" << std::endl;
		#endif // DEBUG
			return false;
		}
		else
		{
			mainWindow = std::make_unique<MainWindow>("Breakout Reforged", SDL_Rect{ SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768 });
			mainWindow->displayBackground();
			return true;
		}
	};
}

SDL_Renderer* SDL::getRenderer()
{
	return mainWindow->getWindowRenderer();
}

std::chrono::steady_clock::duration SDL::elapsedTime()
{
	endTime = std::chrono::steady_clock::now();
	std::chrono::steady_clock::duration interval = endTime - startTime;
	startTime = endTime;
	return interval;
}

void SDLtext::freeSurface(SDL_Surface* surface)
{
	SDL_FreeSurface(surface);
}

void SDLgraphics::freeSurface(SDL_Surface* surface)
{
	SDL_FreeSurface(surface);
}

void SDL::quit()
{
	SDLtext::quit();
	SDLgraphics::quit();
	SDL_Quit();
}

bool SDLgraphics::initialise(int flags)
{
	return (IMG_Init(flags) & flags);
}

SDL_Surface* SDLgraphics::getImageSurface(std::string filePath)
{
	return IMG_Load(filePath.c_str());
}

void SDLgraphics::quit()
{
	IMG_Quit();
}

bool SDLtext::initialise()
{
	if (TTF_Init() < 0)
	{
		std::cout << "TTF_Init() failed: " << TTF_GetError() << std::endl;
		return false;
	}
	else {
		if (openSansBold20 = TTF_OpenFont("C:/dev/cpp/Breakout_Reforged/resources/fonts/OpenSans-Bold.ttf", 20))
		{
			return true;
		}
		else
		{
			std::cout << "TTF_OpenFont() failed: " << TTF_GetError() << std::endl;
			return false;
		};
	};
}

void SDLtext::quit() { TTF_CloseFont(openSansBold20); TTF_Quit(); }

SDL_Surface* SDLtext::getTextSurface(std::string text, SDL_Color fg)
{ 
	return TTF_RenderText_Blended(openSansBold20, text.c_str(), fg);
}

TTF_Font* SDLtext::openSansBold20 = nullptr;
std::unique_ptr<MainWindow> SDL::mainWindow = nullptr;
std::chrono::steady_clock::time_point SDL::startTime = std::chrono::steady_clock::now();
std::chrono::steady_clock::time_point SDL::endTime = std::chrono::steady_clock::time_point();
