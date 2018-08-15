#include "Fade.h"

Fade::Fade() {
	speed = 10.0f;
	increase = false;
}




void Fade::Update(Animation &a) {

	if (a.getIsActive()) {
		if (!increase) {
			a.getAlpha() -= speed;
		}
		else {
			a.getAlpha() += speed;
		}
		if (a.getAlpha() <= 0) {
			a.getAlpha() = 0;
			increase = true;
		}
		else if (a.getAlpha() >= 255){
			a.getAlpha()= 255;
			increase = false;
			
		}
		
	}
	else {
		a.getAlpha() = 255;
	}
	
}

void Fade::setIncrease(bool value) {
	increase = value;
}
