#include "Renderer.h"

Renderer::Renderer(SDL_Window* window) : rendererHolder(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED))
{
	viewport.x = 0;
	viewport.y = 0;
	SDL_GetWindowSize(window, &viewport.w, &viewport.h);
	#ifdef DEBUG
		if (rendererHolder == NULL) std::cout << "Creating renderer failed : " << SDL_GetError() << std::endl;
	#endif // DEBUG
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(rendererHolder);
}

void Renderer::clearScreen()
{
	SDL_RenderClear(rendererHolder);
}

SDL_Renderer* Renderer::getRenderer()
{
	return rendererHolder;
}

SDL_Rect& Renderer::getWindowArea()
{
	return viewport;
}

void Renderer::updateScreen()
{
	SDL_RenderPresent(rendererHolder);
}
