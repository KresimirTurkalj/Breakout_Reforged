/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include "GameEngine/Engine.h"
#include <iostream>

int main( int argc, char* args[] )
{	
	auto engine = std::make_unique<Engine>();
	engine->startLoop();
	return 0;
}