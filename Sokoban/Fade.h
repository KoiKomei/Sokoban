#pragma once
#ifndef FADE_H
#define FADE_H

#include "Animation.h"

class Fade :public Animation {
public:
	void LoadContent(ALLEGRO_BITMAP *image, string txt, float position[2]);
	void Unload();
	void setAlpha(float value) { alpha = value; if (alpha == 0) increase = true; else if (alpha == 255) increase = false; }
	void Update(Input input);

private:
	float speed;
	bool increase;
};

#endif 