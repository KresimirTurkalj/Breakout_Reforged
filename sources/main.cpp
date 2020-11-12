/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include "game/game.h"
#include <iostream>


int main( int argc, char* args[] )
{	
	std::cout << "Start\n";
	Game* game = new Game();
	std::cout << "Loop start\n";
	game->loop();
	std::cout << "Loop end\n";
	delete game;
	std::cout << "End\n";
	return 0;
}