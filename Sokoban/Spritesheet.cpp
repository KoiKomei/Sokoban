#include "Spritesheet.h"



Spritesheet::Spritesheet()
{
	frameCounter = 0;
	switchFrame = 10;

}


Spritesheet::~Spritesheet()
{
}

void Spritesheet::Update(Animation &a) {
	if (a.getIsActive()) {
		frameCounter++;
		if (frameCounter >= switchFrame) {
			frameCounter = 0;
			a.CurrentFrame().first++;
			if (a.CurrentFrame().first *a.FrameSize().first >= al_get_bitmap_width(a.Sprite())) {
				a.CurrentFrame().first = 0;
			}
		}
	}
	else {
		frameCounter = 0;
		a.CurrentFrame().first = 1;
	}
	a.SourceRect() = al_create_sub_bitmap(a.Sprite(), a.CurrentFrame().first*a.FrameSize().first, a.CurrentFrame().second*a.FrameSize().second, a.FrameSize().first, a.FrameSize().second);



}