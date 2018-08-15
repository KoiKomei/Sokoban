#pragma once
#ifndef FADE_H
#define FADE_H

#include "Animation.h"

class Fade :public Animation {
public:

	Fade();
	void setIncrease(bool value);
	void Update(Animation &a);


private:
	float speed;
	bool increase;
};

#endif 