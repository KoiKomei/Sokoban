#pragma once
#include "Game.h"

#include "Map.h"
#include "EntityManager.h"
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
	EntityManager player, boxes;
	Map map;
};

