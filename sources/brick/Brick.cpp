#include "Brick.h"

Brick::Brick(BrickInfo bI) : Rectangle(bI.oI), SoundObject(bI.soundFileLocation){
	registerObserver(bI.observer);
	brickCount++;
}

Brick::~Brick()
{
	brickCount--;
}

void Brick::registerObserver(IBreakObserver* observer){
	breakObserver = observer;
}

void Brick::onBrickDestroyed(){
	breakObserver->onBreakObserved(this);
}

int Brick::brickCount = 0;
