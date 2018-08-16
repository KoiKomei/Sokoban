#pragma once
#include "allegro5/allegro.h"
#include "Animation.h"
#include "Player.h"
#include <iostream>
using namespace std;
class Tile
{
public:
	Tile();
	~Tile();
	
	enum State {Solid, Passive};

	void setContent(int id, ALLEGRO_BITMAP *tileImage, State state, pair<float, float> position);
	void Unload();
	void Update(Entity &e);
	void Draw(ALLEGRO_DISPLAY *display);

	private:
		ALLEGRO_BITMAP * image;
		Animation tileAnimation;
		State state;
		pair<float, float> position;
		int id;
};

