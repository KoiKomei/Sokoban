#pragma once
#include "Animation.h"
class Spritesheet
{
public:
	Spritesheet();
	~Spritesheet();
	void Update(Animation &a);

private:
	int frameCounter, switchFrame;
};

