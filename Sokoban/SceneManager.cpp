#include "SceneManager.h"
#include "MainMenu.h"
#include "Screen.h"

SceneManager &SceneManager::GetInstance() {
	static SceneManager instance;
	return instance;
}

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {}

void SceneManager::addScene(string sceneName) {

	transition.getAlpha() = 0;
	fade.setIncrease(true);
	startTransition = true;
	newscene = directory[sceneName];
	transition.setIsActive(true);
	
}

void SceneManager::setText(string txt) {
	text = txt;
	
}

void SceneManager::getText() {

	cout << text << endl;
}

void SceneManager::Initialize() {

	cout << "MA COSA STA SUCCEDENDO" << endl;
	directory["Screen"] = new Screen();
	directory["Title"] = new MainMenu();
	directory["Gameplay"] = new Gameplay();
	current = directory["Gameplay"];

}

void SceneManager::LoadContent() {
	(*current).LoadContent();
	trans = al_load_bitmap("black.png");
	pair<float, float>position(0, 0);
	transition.LoadContent(trans, "", position);
	startTransition = false;
}

void SceneManager::Unload() {
	al_destroy_bitmap(trans);
	(*current).Unload();
	transition.Unload();

	for (map<string, Game*>::iterator it = directory.begin(); it != directory.end(); it++) {
		(*it).second;
	}
	directory.clear();
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
	fade.Update(transition);
	if (transition.getAlpha() >= 255) {
		transition.getAlpha()=255;
		
		(*current).Unload();
		
		current = newscene;
		(*current).LoadContent();
		al_rest(1.0f);
	}
	else if (transition.getAlpha() <= 0) {
		startTransition = false;
		transition.getIsActive()=false;
	}
}
