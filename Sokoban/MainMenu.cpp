#include "MainMenu.h"

void MainMenu::LoadContent() {
	font = al_load_font("ariali.ttf", 30, NULL);
	menu.LoadContent("Title");
}

void MainMenu::Unload() {
	Game::Unload();
	al_destroy_font(font);
	menu.Unload();
}

void MainMenu::Update(ALLEGRO_EVENT ev) {
	
	menu.Update(ev, input);
	
}

void MainMenu::Draw(ALLEGRO_DISPLAY *display) {
	//al_draw_text(font, al_map_rgb(255, 0, 0), 100, 100, NULL, "MENU");
	menu.Draw(display);
}