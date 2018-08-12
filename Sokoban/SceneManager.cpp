#include "SceneManager.h"
Game *current, *newscreen;
SceneManager &SceneManager::GetInstance() {
	static SceneManager instance;
	return instance;
}

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {}

void SceneManager::setText(string txt) {
	text = txt;
	
}

void SceneManager::getText() {

	cout << text << endl;
}

void SceneManager::Initialize() {
	current = new Screen();

}

void SceneManager::LoadContent() {
	(*current).LoadContent();
}

void SceneManager::Update() {
	(*current).Update();
}

void SceneManager::Draw(ALLEGRO_DISPLAY *display) {
	(*current).Draw(display);

}
