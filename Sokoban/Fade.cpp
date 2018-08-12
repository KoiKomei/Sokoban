#include "Fade.h"

void Fade::LoadContent(ALLEGRO_BITMAP *image, string txt, float position[2]){
	Animation::LoadContent(image, txt, position);
	speed = 1.0f;
	increase = false;
}

void Fade::Unload() {
	Animation::Unload();
	speed = NULL;
}

void Fade::Update(Input input) {

	if (isActive) {
		if (!increase) {
			alpha -= speed;
		}
		else {
			alpha += speed;
		}
		if (alpha <= 0) {
			alpha = 0;
			increase = true;
		}
		else if (alpha >= 255){
			alpha = 255;
			increase = false;
			
		}
		
	}
	else {
		alpha = 255;
	}
	
	

}