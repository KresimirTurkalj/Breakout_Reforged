#pragma once
#include "rectangle\Rectangle.h"
#include "interfaces\IMovable.h"
#include "interfaces\IBreakObservation.h"

class Platform : public Rectangle, public IMovable, public IBreakObserver {

};

