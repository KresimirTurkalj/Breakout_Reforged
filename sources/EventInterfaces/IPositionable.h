#pragma once
#include <SDL_rect.h>

enum class HAnchor
{
	Left,
	Center,
	Right
};
enum class VAnchor
{
	Top,
	Middle,
	Bottom,
};

class IPositionable{
public:
	IPositionable(IPositionable* parent);
	virtual ~IPositionable() {}

	virtual SDL_Point Position();
	virtual void SetPosition(SDL_Point newPosition);

	virtual SDL_Point Size();
	virtual void SetSize(SDL_Point newSize);

	virtual void OnWindowAreaChange();

	virtual SDL_Point& RelativePosition();
	virtual void SetRelativePosition(SDL_Point newPosition);

	virtual void SetAnchorHorizontal(HAnchor horizontalAnchor);
	virtual HAnchor& AnchorHorizontal();
	virtual void SetAnchorVertical(VAnchor verticalAnchor);
	virtual VAnchor& AnchorVertical();

	virtual bool isPointInside(SDL_Point* point);

protected:
	IPositionable* parent;
	SDL_Rect area;
	SDL_Point relativePosition;
	HAnchor hAnchor;
	VAnchor vAnchor;

	void UpdatePosition();
};