#include "MainWindow.h"

MainWindow::MainWindow(std::string windowName, SDL_Rect windowRectangle) : Window(windowName, windowRectangle) {}

void MainWindow::displayBackground()
{
	background = std::make_unique<Background>("resources/level_background/star_pattern.jpg", this);
	addPositionableItem(background.get());
	addDrawableItem(background.get());

	label = std::make_unique<Label>("Test 123", this);
	label->SetAnchorHorizontal(HAnchor::Right);
	label->SetAnchorVertical(VAnchor::Top);
	addPositionableItem(label.get());
	addDrawableItem(label.get());

	click = std::make_unique<ClickableItem>(this);
	click->SetAnchorHorizontal(HAnchor::Center);
	click->SetAnchorVertical(VAnchor::Middle);
	click->SetSize(SDL_Point{ 100, 100 });
	click->addOnHoverLambda([](SDL_MouseMotionEvent motionEvent){
		std::cout << "Cursor: " << motionEvent.x << "\t" << motionEvent.y << std::endl;
	});
	addPositionableItem(click.get());
	addMouseEventsItem(click.get());

	keyShower = std::make_unique<KeyShower>(this);
	keyShower->SetAnchorHorizontal(HAnchor::Center);
	keyShower->SetAnchorVertical(VAnchor::Middle);
	addPositionableItem(keyShower.get());
	addDrawableItem(keyShower.get());
	addKeyboardEventsItem(keyShower.get());
}
