#include "Animation.h"

void Animation::LoadContent(ALLEGRO_BITMAP *image, string txt, float position[2]) {
	(*this).image = image;
	(*this).txt = txt;
	(*this).position[0] = position[0];
	(*this).position[1] = position[1];
	alpha = 255;
	font = al_load_font("ariali.ttf", 30, NULL);
	rectangle = image;

}

void Animation::Unload() {
	al_destroy_bitmap(image);
	al_destroy_bitmap(rectangle);
	al_destroy_font(font);
	alpha = NULL;
	position[0] = position[1] = NULL;
	isActive = false;
}

void Animation::Update(Input input) {


}

void Animation::Draw(ALLEGRO_DISPLAY *display) {
	if (rectangle != NULL) {
		al_draw_tinted_bitmap(rectangle, al_map_rgba(0, 0, 0, alpha), position[0], position[1], NULL);
	}
	
	if (txt != "") {
		al_draw_text(font, al_map_rgba(255, 0, 0, alpha), position[0], position[1], NULL, txt.c_str());
	}
}