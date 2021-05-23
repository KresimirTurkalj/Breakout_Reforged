#include "IPositionable.h"

SDL_Point operator+(const SDL_Point lhs, const SDL_Point& rhs)
{
	return SDL_Point{ lhs.x + rhs.x, lhs.y + rhs.y };
}

SDL_Point& operator+=(SDL_Point lhs, const SDL_Point& rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	return lhs;
};

SDL_Point operator/(const SDL_Point lhs, const int& scale)
{
	return SDL_Point{ lhs.x / scale, lhs.y / scale };
}

SDL_Point operator*(const SDL_Point lhs, const int& scale)
{
	return SDL_Point{ lhs.x * scale, lhs.y * scale };
}

IPositionable::IPositionable(IPositionable* p) : area(SDL_Rect{ 0, 0, 0, 0}), relativePosition(SDL_Point{ 0,0 }), parent(p), hAnchor(HAnchor::Left), vAnchor(VAnchor::Top)
{

}

SDL_Point IPositionable::Position()
{
	return SDL_Point{area.x, area.y};
}

void IPositionable::SetPosition(SDL_Point newPosition)
{ 
	area.x = newPosition.x;
	area.y = newPosition.y;
}

SDL_Point IPositionable::Size()
{
	return SDL_Point{ area.w, area.h };
}

void IPositionable::SetSize(SDL_Point newSize)
{ 
	area.w = newSize.x;
	area.h = newSize.y;
	UpdatePosition();
}

void IPositionable::OnWindowAreaChange()
{ 
	UpdatePosition();
}

SDL_Point& IPositionable::RelativePosition()
{ 
	return relativePosition;
}

void IPositionable::SetRelativePosition(SDL_Point newPosition)
{ 
	relativePosition = newPosition;
	UpdatePosition();
}

void IPositionable::SetAnchorHorizontal(HAnchor horizontalAnchor)
{ 
	hAnchor = horizontalAnchor;
	UpdatePosition();
}
HAnchor& IPositionable::AnchorHorizontal() 
{ 
	return hAnchor;
}

void IPositionable::SetAnchorVertical(VAnchor verticalAnchor)
{ 
	vAnchor = verticalAnchor;
	UpdatePosition();
}

VAnchor& IPositionable::AnchorVertical() 
{ 
	return vAnchor; 
}

bool IPositionable::isPointInside(SDL_Point* point)
{
	return SDL_PointInRect(point, &area);
}

void IPositionable::UpdatePosition()
{
	if (parent != nullptr)
	{
		switch (hAnchor)
		{
		case HAnchor::Right:
			area.x = parent->area.w - area.w + relativePosition.x + parent->area.x;
			break;
		case HAnchor::Center:
			area.x = relativePosition.x + parent->area.x + (parent->area.w - area.w) / 2;
			break;
		}
		switch (vAnchor)
		{
		case VAnchor::Bottom:
			area.y = parent->area.h - area.h + relativePosition.y + parent->area.y;
			break;
		case VAnchor::Middle:
			area.y = relativePosition.y + parent->area.y + (parent->area.h - area.h) / 2;
			break;
		}
	}
}