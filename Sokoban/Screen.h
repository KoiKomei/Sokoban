#pragma once
#ifndef SCREEN_H
#define SCREEN_H


#include "MainMenu.h"
#include "Input.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
class Screen : public Game {
public:
	void LoadContent();
	void Unload();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
private:
	ALLEGRO_FONT * font;
	Input input;
};

#endif // !SCREEN_H