#include "Animation.h"

void Animation::LoadContent(ALLEGRO_BITMAP *image, string txt, pair<float,float>position) {
	(*this).image = image;
	(*this).txt = txt;
	(*this).position = position;
	alpha = 255;
	font = al_load_font("ariali.ttf", 30, NULL);
	rectangle = image;
	isActive = false;
	frames = pair<int, int>(3, 4);
	currentFrame = pair<int, int>(1, 2);

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

pair<int,int>& Animation::CurrentFrame() {
	return currentFrame;
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

pair<float, float> &Animation::Position() {
	return position;
}

pair<int, int> &Animation::AmountOfFrames() {
	return frames;
}

pair<int, int> Animation::FrameSize() {
	pair<int, int> size(al_get_bitmap_width(image) / frames.first, al_get_bitmap_height(image)/frames.second);
	return size;
}

ALLEGRO_BITMAP*& Animation:: SourceRect() {
	return rectangle;
}

ALLEGRO_BITMAP* Animation::Sprite() {
	return image;
}