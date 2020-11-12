#pragma once
#include <sound_object/SoundObject.h>
#include <interfaces/IMovable.h>
#include <circle/Circle.h>

class Ball : public Circle, public SoundObject, public IMovable {
public:
	struct BallInfo {
		ObjectInfo oI;
		std::string soundFileLocation;
		Point vectorVeloc;
	};

	Ball(BallInfo bI);
	// Inherited via IMovable
	virtual void updateState(const std::vector<Rectangle*>& vector) override;
private:
	Point vectorVelocity;

	Point nextCenter();

};

