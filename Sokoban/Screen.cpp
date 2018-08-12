#include "Screen.h"

void Screen::LoadContent() {
	font = al_load_font("ariali.ttf", 30, NULL);
}

void Screen::Unload() {
	al_destroy_font(font);
}

void Screen::Update(ALLEGRO_EVENT ev) {
	if (input.isKeyPressed(ev, ALLEGRO_KEY_Z)) {
		SceneManager::GetInstance().addScene(new MainMenu);
	}

}

void Screen::Draw(ALLEGRO_DISPLAY *display) {
	al_draw_text(font, al_map_rgb(255, 255, 0), 100, 100, NULL, "MENU");
}