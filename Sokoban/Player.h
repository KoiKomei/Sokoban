#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "allegro5/allegro.h"
#include "Input.h"
#include "FileManager.h"
#include "Spritesheet.h"
#include <vector>
#include <string>
#include "Entity.h"

class Player:public Entity
{
public:
	Player();
	~Player();

	void LoadContent(vector<string> attributes, vector<string> contents);
	void Unload();
	void Update(ALLEGRO_EVENT ev, Input input);
	void OnCollision(Entity e);
	void Draw(ALLEGRO_DISPLAY *display);
	

private:
	ALLEGRO_BITMAP * playerImage;
};

#endif // !PLAYER_H