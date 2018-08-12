#include "SceneManager.h"

SceneManager &SceneManager::GetInstance() {
	static SceneManager instance;
	return instance;
}

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {}

void SceneManager::addScene(Game *scene) {

	transition.setAlpha(0);
	startTransition = true;
	newscene = scene;
	transition.setIsActive(true);
	
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
	trans = al_load_bitmap("black.png");
	float pos[2] = { 0,0 };
	transition.LoadContent(trans, "", pos);
	startTransition = false;
}

void SceneManager::Unload() {
	al_destroy_bitmap(trans);
	transition.Unload();
}

void SceneManager::Update(ALLEGRO_EVENT ev) {
	if (!startTransition)
		(*current).Update(ev);
	else
		Transition();
}

void SceneManager::Draw(ALLEGRO_DISPLAY *display) {
	(*current).Draw(display);
	if (startTransition)
		transition.Draw(display);
}

void SceneManager::Transition() {
	transition.Update((*current).getInput());
	if (transition.getAlpha() >= 255) {
		transition.setAlpha(255);
		
		(*current).Unload();
		delete current;
		current = newscene;
		(*current).LoadContent();
		al_rest(1.0f);
	}
	else if (transition.getAlpha() <= 0) {
		startTransition = false;
		transition.setIsActive(false);
	}
}
