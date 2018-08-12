#pragma once
#include "SceneManager.h"
#include <vector>


class Input {

public:

	bool isKeyPressed(ALLEGRO_EVENT ev, int key);
	bool isKeyPressed(ALLEGRO_EVENT ev, vector<int> keys);

	bool isKeyReleased(ALLEGRO_EVENT ev, int key);
	bool isKeyReleased(ALLEGRO_EVENT ev, vector <int> keys);

private:
	ALLEGRO_KEYBOARD_STATE keyboard;




};