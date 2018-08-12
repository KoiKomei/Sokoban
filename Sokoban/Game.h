#pragma once
#include <allegro5/allegro.h>

class Game {

public: 
	Game();
	~Game();

	virtual void LoadContent();
	virtual void Update();
	virtual void Draw(ALLEGRO_DISPLAY *display);
	virtual void Unload();

};