#include "MainMenu.h"

void MainMenu::LoadContent() {
	font = al_load_font("ariali.ttf", 30, NULL);
}

void MainMenu::Unload() {
	al_destroy_font(font);
}

void MainMenu::Update(ALLEGRO_EVENT ev) {
	if (input.isKeyPressed(ev, ALLEGRO_KEY_ENTER)) {
		SceneManager::GetInstance().addScene(new Screen);
	}
	
}

void MainMenu::Draw(ALLEGRO_DISPLAY *display) {
	al_draw_text(font, al_map_rgb(255, 0, 0), 100, 100, NULL, "MENU");
}