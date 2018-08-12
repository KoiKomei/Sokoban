#pragma once
#include "allegro5/allegro.h"
#include "allegro5/keyboard.h"
#include <vector>


using namespace std;
class Input {

public:

	bool isKeyPressed(ALLEGRO_EVENT ev, int key);
	bool isKeyPressed(ALLEGRO_EVENT ev, vector<int> keys);

	bool isKeyReleased(ALLEGRO_EVENT ev, int key);
	bool isKeyReleased(ALLEGRO_EVENT ev, vector <int> keys);

private:
	ALLEGRO_KEYBOARD_STATE keyboard;
	
};
