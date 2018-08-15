#include "Animation.h"

void Animation::LoadContent(ALLEGRO_BITMAP *image, string txt, pair<float,float>position) {
	(*this).image = image;
	(*this).txt = txt;
	(*this).position = position;
	alpha = 255;
	font = al_load_font("ariali.ttf", 30, NULL);
	rectangle = image;

}

void Animation::Unload() {
	al_destroy_bitmap(image);
	al_destroy_bitmap(rectangle);
	al_destroy_font(font);
	alpha = NULL;
	position = pair<float, float>(0, 0);
	isActive = false;
}

void Animation::Update(Animation &a) {


}

void Animation::Draw(ALLEGRO_DISPLAY *display) {
	al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);
	if (rectangle != NULL) {
		al_draw_tinted_bitmap(rectangle, al_map_rgba(255, 255, 255, alpha), position.first, position.second, NULL);
	}
	
	if (txt != "") {
		al_draw_text(font, al_map_rgba(255, 0, 0, alpha), position.first, position.second, NULL, txt.c_str());
	}
}