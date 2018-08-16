#include "FloatRect.h"




FloatRect::~FloatRect()
{
}

FloatRect::FloatRect(float x, float y, float w, float h):Left(x), Right(x + w), Top(y), Bottom(y + h){
	
}

bool FloatRect::Intersects(FloatRect f) {
	if (Right<f.Left || Left>f.Right || Top > f.Bottom || Bottom < f.Top) {
		return false;
	}
	return true;
}