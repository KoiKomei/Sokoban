#pragma once
#include "Entity.h"
#include "FileManager.h"
#include "Player.h"
#include "Boxes.h"
class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	void LoadContent(string filename, string id, string type);
	void Unload();
	void Update(ALLEGRO_EVENT ev, Input input);
	void EntityCollision(EntityManager e);
	void Draw(ALLEGRO_DISPLAY *display);

	vector<Entity*> entities;
	bool moving;


private:
	
};

