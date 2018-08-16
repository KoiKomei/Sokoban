#include "Screen.h"

void Screen::LoadContent() {
	cout << "PROVA" << endl;
	imageNumber = 0;
	font = al_load_font("ariali.ttf", 30, NULL);
	filemanager.LoadContent("utilities/loader.txt", attributes, contents);
	for (int i = 0; i < attributes.size(); i++) {
		for (int j = 0; j < attributes[i].size(); j++) {
			if (attributes[i][j] == "Image") {
				pair<float, float> position(0, 0);
				images.push_back(al_load_bitmap(contents[i][j].c_str()));
				fade.push_back(new Fade);
				(*fade[fade.size() - 1]).LoadContent(images[fade.size() - 1], "", position);
				(*fade[fade.size() - 1]).getIsActive() = true;
			}
			
		}
	}
}

void Screen::Unload() {
	Game::Unload();
	al_destroy_font(font);
	for (int i = 0; i < fade.size(); i++) {
		al_destroy_bitmap(images[i]);
		delete fade[i];
	}
	fade.clear();
}

void Screen::Update(ALLEGRO_EVENT ev) {
	
	if (input.isKeyPressed(ev, ALLEGRO_KEY_ENTER))
		SceneManager::GetInstance().addScene("Title");
}

void Screen::Draw(ALLEGRO_DISPLAY *display) {
	al_draw_text(font, al_map_rgb(255, 255, 0), 100, 100, NULL, "MENU");
	//(*fade[imageNumber]).Draw(display);
}