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
	virtual void LoadContent(ALLEGRO_BITMAP *image, string txt, float position[2]);
	virtual void Update(Input input);
	virtual void Unload();
	void Draw(ALLEGRO_DISPLAY *display);
	virtual void setAlpha(float value) { alpha = value; }
	float getAlpha()const { return alpha; }

	void setIsActive(bool value) { isActive = value; }
	bool getIsActive()const { return isActive; }

protected:
	ALLEGRO_BITMAP * image, *rectangle;
	string txt;
	ALLEGRO_FONT *font;

	float position[2];
	float alpha;
	bool isActive;

};
#endif 
