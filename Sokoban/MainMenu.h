#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H


#include "MenuManager.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"


class MainMenu : public Game{


public:

	void LoadContent();
	void Unload();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);

private:
	ALLEGRO_FONT * font;
	Input input;
	MenuManager menu;
};
#endif // !MAINMENU_H