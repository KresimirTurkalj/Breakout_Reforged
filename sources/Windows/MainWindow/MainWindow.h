#pragma once 
#include "../../Rudimentary/Window.h"
#include "../../Drawables/Background.h"
#include "../../Drawables/Label.h"
#include "../../Rudimentary/ClickableItem.h"
#include "../../Drawables/FPSCounter.h"
#include "../../Drawables/KeyShower.h"
#include <memory>

class MainWindow : public Window
{
public:
	MainWindow(std::string windowName, SDL_Rect windowRectangle);
	void displayBackground();
private:
	std::unique_ptr<Background> background;
	std::unique_ptr<Label> label;
	std::unique_ptr<ClickableItem> click;
	std::unique_ptr<KeyShower> keyShower;
};