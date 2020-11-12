#pragma once
#include "rectangle\Rectangle.h"
#include "sound_object\SoundObject.h"
#include "interfaces\IHitObservation.h"
#include "interfaces\IBreakObservation.h"

class Brick : public Rectangle, public SoundObject, public IHitObserver, public IBreakSubject {
public:
	struct BrickInfo {
		ObjectInfo oI;
		IBreakObserver* observer;
		std::string soundFileLocation;
	};

	Brick(BrickInfo bI);
	~Brick();
	virtual void registerObserver(IBreakObserver* observer) override;
protected:
	void onBrickDestroyed();
private:
	IBreakObserver* breakObserver;
	static int brickCount;
};

