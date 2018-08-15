#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "allegro5/allegro.h"
#include "Input.h"
#include "FileManager.h"
#include <vector>
#include <string>

class Player
{
public:
	Player();
	~Player();

	void LoadContent();
	void Unload();
	void Update(ALLEGRO_EVENT ev, Input input);
	void Draw(ALLEGRO_DISPLAY *display);

private:
	ALLEGRO_BITMAP * playerImage;
	pair<float, float>position;
	float speed;
	FileManager file;
	vector<vector<string>> attributes, contents;
};

#endif // !PLAYER_H