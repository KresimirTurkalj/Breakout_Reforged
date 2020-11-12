#include "menu.h"
#include <iostream>
#include <functional>

Menu::Menu(XMLParser::SceneInfo sI)	: Scene(sI) {
	/*Vjerojatno treba pripremiti tekst za prikazati na ekranu?*/
}

Menu::~Menu() {
	/*Možda ništa?*/
}

Uint32 Menu::updateForInterval(Uint32 interval) {
	return interval;
}

Uint32 Menu::updateScreen(Uint32 interval) {
	return interval;
}
