#pragma once
#include "allegro5/allegro.h"
#include "allegro5/keyboard.h"
#include <vector>


using namespace std;
class Input {

public:

	void Update();

	bool isKeyPressed(ALLEGRO_EVENT ev, int key);
	bool isKeyPressed(ALLEGRO_EVENT ev, vector<int> keys);

	bool isKeyReleased(ALLEGRO_EVENT ev, int key);
	bool isKeyReleased(ALLEGRO_EVENT ev, vector <int> keys);
	
	bool isKeyDown(int key);

private:
	ALLEGRO_KEYBOARD_STATE keyboard;
	
};
