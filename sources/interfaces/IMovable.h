#pragma once
#include <memory>
#include <vector>

class Rectangle;

class IMovable {
public:
	virtual void updateState(const std::vector<Rectangle*> &vector) = 0;
	virtual ~IMovable(){}
};

