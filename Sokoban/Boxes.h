#pragma once
#include "Entity.h"
class Boxes :public Entity
{
public:
	Boxes();
	~Boxes();

	void LoadContent(vector<string> attributes, vector<string> contents);
	void Unload();
	void Update(ALLEGRO_EVENT ev, Input input);
	void OnCollision(Entity e);
	void Draw(ALLEGRO_DISPLAY *display);
private:
	int counter;
};

