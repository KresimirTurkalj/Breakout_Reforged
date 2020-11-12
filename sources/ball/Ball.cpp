#include "Ball.h"
#include <rectangle/Rectangle.h>

Ball::Ball(BallInfo bI) : Circle(bI.oI), SoundObject(bI.soundFileLocation), vectorVelocity(bI.vectorVeloc){

}

void Ball::updateState(const std::vector<Rectangle*>& vector) {
	for (int i = 0; i < vector.size(); i++) {
		/*if (nextCenter == vector[i]->pointOfCollision(centre, radius, vectorVelocity)) {
			
		}*/
	}
}

ShapedObject::Point Ball::nextCenter()
{
	return Point{ centre.x + vectorVelocity.x, centre.y + vectorVelocity.y };
}
