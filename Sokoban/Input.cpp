#include "Input.h"


void Input::Update() {
	al_get_keyboard_state(&keyboard);
}

bool Input::isKeyPressed(ALLEGRO_EVENT ev, int key) {
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		if (ev.keyboard.keycode == key) {
			return true;
		}
	}
	return false;

}
bool Input::isKeyPressed(ALLEGRO_EVENT ev, vector <int> keys) {
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		for (int i = 0; i < keys.size(); i++) {
			if (ev.keyboard.keycode == keys[i]) {
				return true;
			}
		}
	}
	return false;

}

bool Input::isKeyReleased(ALLEGRO_EVENT ev, int key) {
	if (ev.type == ALLEGRO_EVENT_KEY_UP) {
		if (ev.keyboard.keycode == key) {
			return true;
		}
	}
	return false;

}
bool Input::isKeyReleased(ALLEGRO_EVENT ev, vector <int> keys) {
	if (ev.type == ALLEGRO_EVENT_KEY_UP) {
		for (int i = 0; i < keys.size(); i++) {
			if (ev.keyboard.keycode == keys[i]) {
				return true;
			}
		}
	}
	return false;


}

bool Input::isKeyDown(int key) {
	if (al_key_down(&keyboard, key)) {
		return true;
	}
	return false;
}