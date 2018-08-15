#pragma once
#include "Game.h"
#include "Player.h"
class Gameplay: public Game
{
public:
	Gameplay();
	~Gameplay();

	void LoadContent();
	void Unload();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);

private:
	Player player;
};

