#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include <string>
#include "Input.h"
using namespace std;
class Animation {
public:
	void LoadContent(ALLEGRO_BITMAP *image, string txt, pair<float,float>position);
	virtual void Update(Animation &a);
	void Unload();
	void Draw(ALLEGRO_DISPLAY *display);
	void setAlpha(float value) { alpha = value; }
	float &getAlpha() { return alpha; }

	void setIsActive(bool value) { isActive = value; }
	bool &getIsActive(){ return isActive; }

	pair<float,float> &Position();
	pair<int, int> &AmountOfFrames();
	pair<int, int> &CurrentFrame();
	pair<int, int> FrameSize();
	ALLEGRO_BITMAP* Sprite();
	ALLEGRO_BITMAP *&SourceRect();


private:
	ALLEGRO_BITMAP * image, *rectangle;
	string txt;
	ALLEGRO_FONT *font;

	pair<float,float> position;
	pair <int, int> frames;
	pair<int, int> currentFrame;
	float alpha;
	bool isActive;

};
#endif 
