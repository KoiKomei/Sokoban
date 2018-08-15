#pragma once
#ifndef GAME_H
#define GAME_H
#include <allegro5/allegro.h>
#include "Input.h"
#include "FileManager.h"

class Game {

public: 
	Game();
	~Game();

	virtual void LoadContent();
	virtual void Update(ALLEGRO_EVENT ev);
	virtual void Draw(ALLEGRO_DISPLAY *display);
	virtual void Unload();

	Input getInput()const { return input; }

protected:
	Input input;
	vector<vector<string>> attributes, contents;
	FileManager file;
};
#endif 