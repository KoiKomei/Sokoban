#include "Tile.h"



Tile::Tile()
{
}


Tile::~Tile()
{
}


void Tile::setContent(int id, ALLEGRO_BITMAP *tileImage, State state, pair<float, float> position) {
	image = tileImage;
	(*this).state = state;
	(*this).position = position;
	tileAnimation.LoadContent(tileImage,"", position);
	(*this).id = id;
	
}

void Tile::Unload() {
	al_destroy_bitmap(image);
}

void Tile::Update(Entity &e) {
	FloatRect tileRect(position.first, position.second, 32, 32);
	if ((*e.rect).Intersects(tileRect) && state==State::Solid) {
		if ((*e.rect).Bottom >= tileRect.Top && (*e.prevRect).Bottom <= tileRect.Top) {
			e.position.second = tileRect.Top - 32;
			e.tileID = id;
		}
		else if ((*e.rect).Top <= tileRect.Bottom && (*e.prevRect).Top >= tileRect.Bottom) {
			e.position.second = tileRect.Bottom;
		}
		else if ((*e.rect).Right >= tileRect.Left && (*e.prevRect).Right <= tileRect.Left) {
			e.position.first = tileRect.Left - 32;
		}
		else if ((*e.rect).Left <= tileRect.Right && (*e.prevRect).Left >= tileRect.Right) {
			e.position.first = tileRect.Right;
		}
		e.animation.Position() = e.position;
	}
}

void Tile::Draw(ALLEGRO_DISPLAY * display) {
	tileAnimation.Draw(display);
}