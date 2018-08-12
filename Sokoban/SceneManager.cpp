#include "SceneManager.h"

SceneManager &SceneManager::GetInstance() {
	static SceneManager instance;
	return instance;
}

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {}

void SceneManager::addScene(Game *scene) {

	newscreen = scene;
	(*current).Unload();
	current = newscreen;
	(*current).LoadContent();
}

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

void SceneManager::Update(ALLEGRO_EVENT ev) {
	(*current).Update(ev);
}

void SceneManager::Draw(ALLEGRO_DISPLAY *display) {
	(*current).Draw(display);

}
